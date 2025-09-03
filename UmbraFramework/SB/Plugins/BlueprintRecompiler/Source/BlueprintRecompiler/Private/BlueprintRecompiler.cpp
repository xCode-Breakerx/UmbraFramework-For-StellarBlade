// Copyright Epic Games, Inc. All Rights Reserved.

#include "BlueprintRecompiler.h"
#include "BlueprintRecompilerStyle.h"
#include "BlueprintRecompilerCommands.h"
#include "LevelEditor.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "ToolMenus.h"
#include "Engine/Blueprint.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Kismet2/KismetEditorUtilities.h"
#include "Framework/Notifications/NotificationManager.h"
#include "Widgets/Notifications/SNotificationList.h"
#include "Misc/MessageDialog.h"
#include "BlueprintGraph/Classes/K2Node.h"
#include "Engine/BlueprintGeneratedClass.h"

static const FName BlueprintRecompilerTabName("BlueprintRecompiler");

#define LOCTEXT_NAMESPACE "FBlueprintRecompilerModule"

void FBlueprintRecompilerModule::StartupModule()
{
    FBlueprintRecompilerStyle::Initialize();
    FBlueprintRecompilerStyle::ReloadTextures();

    FBlueprintRecompilerCommands::Register();

    PluginCommands = MakeShareable(new FUICommandList);

    PluginCommands->MapAction(
        FBlueprintRecompilerCommands::Get().OpenPluginWindow,
        FExecuteAction::CreateRaw(this, &FBlueprintRecompilerModule::PluginButtonClicked),
        FCanExecuteAction());

    UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FBlueprintRecompilerModule::RegisterMenus));
}

void FBlueprintRecompilerModule::ShutdownModule()
{
    UToolMenus::UnRegisterStartupCallback(this);
    UToolMenus::UnregisterOwner(this);
    FBlueprintRecompilerStyle::Shutdown();
    FBlueprintRecompilerCommands::Unregister();
}

void FBlueprintRecompilerModule::PluginButtonClicked()
{
    // Show confirmation dialog
    EAppReturnType::Type Result = FMessageDialog::Open(
        EAppMsgType::YesNo,
        LOCTEXT("ConfirmRecompile", "This will mark all blueprints as dirty and force recompilation. This may take a while. Continue?"));

    if (Result == EAppReturnType::Yes)
    {
        RecompileAllBlueprints();
    }
}

void FBlueprintRecompilerModule::RecompileAllBlueprints()
{
    // Get asset registry
    FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
    IAssetRegistry&       AssetRegistry       = AssetRegistryModule.Get();

    // Find all blueprint assets
    TArray<FAssetData>    AllBlueprintAssets;
    AssetRegistry.GetAssetsByClass(UBlueprint::StaticClass()->GetFName(), AllBlueprintAssets);

    // Filter to only include blueprints in /Content/ folder (project content)
    TArray<FAssetData> BlueprintAssets;
    for (const FAssetData& AssetData : AllBlueprintAssets)
    {
        FString PackageName = AssetData.PackageName.ToString();

        // Only include assets that start with /Game/ (which represents the /Content/ folder)
        // This excludes engine content (/Engine/), plugin content (/PluginName/), etc.
        if (PackageName.StartsWith(TEXT("/Game/")))
        {
            BlueprintAssets.Add(AssetData);
        }
    }

    if (BlueprintAssets.Num() == 0)
    {
        FNotificationInfo Info(LOCTEXT("NoBlueprints", "No blueprints found to recompile."));
        Info.ExpireDuration = 3.0f;
        FSlateNotificationManager::Get().AddNotification(Info);
        return;
    }

    // Show progress notification
    FNotificationInfo Info(FText::Format(LOCTEXT("RecompilingBlueprints", "Recompiling {0} blueprints..."), BlueprintAssets.Num()));
    Info.bFireAndForget                            = false;
    Info.ExpireDuration                            = 0.0f;
    TSharedPtr<SNotificationItem> NotificationItem = FSlateNotificationManager::Get().AddNotification(Info);

    int32                         ProcessedCount   = 0;
    int32                         SuccessCount     = 0;
    int32                         FailedCount      = 0;

    // Process each blueprint
    for (const FAssetData& AssetData : BlueprintAssets)
    {
        UBlueprint* Blueprint = Cast<UBlueprint>(AssetData.GetAsset());
        if (Blueprint)
        {
            // Mark blueprint as dirty
            Blueprint->Modify();

            // Force recompilation
            FKismetEditorUtilities::CompileBlueprint(Blueprint, EBlueprintCompileOptions::None);

            if (Blueprint->Status == BS_UpToDate)
            {
                SuccessCount++;
            }
            else
            {
                FailedCount++;
                UE_LOG(LogTemp, Warning, TEXT("Failed to compile blueprint: %s"), *Blueprint->GetName());
            }
        }

        ProcessedCount++;

        // Update progress
        if (NotificationItem.IsValid())
        {
            FText ProgressText = FText::Format(
                LOCTEXT("RecompileProgress", "Recompiling blueprints... {0}/{1} ({2} successful, {3} failed)"),
                ProcessedCount,
                BlueprintAssets.Num(),
                SuccessCount,
                FailedCount);
            NotificationItem->SetText(ProgressText);
        }
    }

    // Complete notification
    if (NotificationItem.IsValid())
    {
        FText CompletionText = FText::Format(
            LOCTEXT("RecompileComplete", "Blueprint recompilation complete! {0} successful, {1} failed out of {2} total."),
            SuccessCount,
            FailedCount,
            BlueprintAssets.Num());

        NotificationItem->SetText(CompletionText);
        NotificationItem->SetCompletionState(FailedCount > 0 ? SNotificationItem::CS_Fail : SNotificationItem::CS_Success);
        NotificationItem->ExpireAndFadeout();
    }

    UE_LOG(LogTemp, Log, TEXT("Blueprint recompilation complete: %d successful, %d failed, %d total"), SuccessCount, FailedCount, BlueprintAssets.Num());
}

void FBlueprintRecompilerModule::RegisterMenus()
{
    // Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
    FToolMenuOwnerScoped OwnerScoped(this);

    {
        UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Tools");
        {
            FToolMenuSection& Section = Menu->FindOrAddSection("Programming");
            Section.AddMenuEntryWithCommandList(FBlueprintRecompilerCommands::Get().OpenPluginWindow, PluginCommands);
        }
    }

    {
        UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar");
        {
            FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("Settings");
            {
                FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FBlueprintRecompilerCommands::Get().OpenPluginWindow));
                Entry.SetCommandList(PluginCommands);
            }
        }
    }

    // Add button to main viewport toolbar next to play button
    {
        UToolMenu* ViewportToolbar = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.PlayToolBar");
        {
            FToolMenuSection& Section = ViewportToolbar->FindOrAddSection("PlayGameExtensions");
            {
                FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(
                    FBlueprintRecompilerCommands::Get().OpenPluginWindow,
                    LOCTEXT("RecompileBlueprints", "Recompile All Blueprints"),
                    LOCTEXT("RecompileBlueprintsTooltip", "Mark all blueprints as dirty and force recompilation"),
                    FSlateIcon(FBlueprintRecompilerStyle::GetStyleSetName(), "BlueprintRecompiler.OpenPluginWindow")));
                Entry.SetCommandList(PluginCommands);
            }
        }
    }
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FBlueprintRecompilerModule, BlueprintRecompiler)