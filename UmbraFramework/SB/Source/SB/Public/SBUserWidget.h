#pragma once
#include "CoreMinimal.h"
// CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
// CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=EInputEvent -FallbackName=EInputEvent
// CROSS-MODULE INCLUDE V2: -ModuleName=InputCore -ObjectName=Key -FallbackName=Key
// CROSS-MODULE INCLUDE V2: -ModuleName=SlateCore -ObjectName=EUINavigation -FallbackName=EUINavigation
// CROSS-MODULE INCLUDE V2: -ModuleName=UMG -ObjectName=UserWidget -FallbackName=UserWidget
#include "ESBTextureStyleType.h"
#include "ESBUIInputAxisType.h"
#include "ESBUILogicType.h"
#include "ESBZoneEventType.h"
#include "SBTextureStyleSetData.h"
#include "SBUserWidgetEventObserver.h"
#include "SBUserWidgetInputBindInfo.h"
#include "Blueprint/UserWidget.h"
#include "Components/ListView.h"
#include "Components/TileView.h"
#include "Templates/SubclassOf.h"
#include "SBUserWidget.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)

class SB_API USBUserWidget : public UUserWidget
{
    GENERATED_BODY()

public:

    USBUserWidget();

protected:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    USBUserWidget* ParentWidget;

private:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TEnumAsByte<ESBUILogicType> TargetUILogic;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bUseInputOnly;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bInputOnlyWhenAllBlock;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float InputOpenBlockTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TSet<FName> Tags;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bUseGroupFocus;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bUseShowMouseCursor;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bMouseCursorVisibleWhenKeyboardInput;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bIgnorePause;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bTickActive;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bAccessSuperClassProperty;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    int32 RemainInvalidateRootCount;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta = (AllowPrivateAccess = true))
    TWeakObjectPtr<USBUserWidget> CachedSBUserWidgetListView;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta = (AllowPrivateAccess = true))
    TWeakObjectPtr<UListView> CachedWidgetListView;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bActiveMouseCursor;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta = (AllowPrivateAccess = true))
    TWeakObjectPtr<UListView> RestoreFocusListView;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    TWeakObjectPtr<UObject> RestoreFocusListViewData;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    int32 RestoreFocusCheckRemainCount;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    uint8 bCheckEventWidgetFocusRestore : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    uint8 bBindEventWidgetFocusRestore : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    TMap<ESBUIInputAxisType, FSBUserWidgetInputBindInfo> PuzzleInputInfoMap;

public:

    UFUNCTION(BlueprintCallable)
    void SetTickActive(bool bActive);

protected:

    UFUNCTION(BlueprintCallable)
    void SetEnableAutoDestroy(bool bEnable);

    UFUNCTION(BlueprintCallable)
    void SendWidgetInputEvent(FName InActionName, TEnumAsByte<EInputEvent> InInputEvent, TEnumAsByte<ESBUILogicType> InTargetLogicType);

public:

    UFUNCTION(BlueprintCallable)
    void SelectItemToListView(UObject* ListViewData, TEnumAsByte<ESBUILogicType> inLogicType);

    UFUNCTION(BlueprintCallable)
    void RestoreFocusToListView(UListView* ListView, UObject* ListViewData);

    UFUNCTION(BlueprintCallable)
    void RequestWidgetFocus(UWidget* InWidget);

    UFUNCTION(BlueprintCallable)
    void RemoveDynamicChildUserWidget(USBUserWidget* InSBUserWidget);

    UFUNCTION(BlueprintCallable)
    void RemoveChildSBUserWidget(USBUserWidget* SBUserWidget);

protected:

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool OnWidgetFocusRestore();

    UFUNCTION(BlueprintCallable, BlueprintCosmetic, BlueprintImplementableEvent)
    void OnInputPuzzleRightAxisY(float Value);

    UFUNCTION(BlueprintCallable, BlueprintCosmetic, BlueprintImplementableEvent)
    void OnInputPuzzleRightAxisX(float Value);

    UFUNCTION(BlueprintCallable, BlueprintCosmetic, BlueprintImplementableEvent)
    void OnInputPuzzleLeftAxisY(float Value);

    UFUNCTION(BlueprintCallable, BlueprintCosmetic, BlueprintImplementableEvent)
    void OnInputPuzzleLeftAxisX(float Value);

    UFUNCTION(BlueprintCallable, BlueprintCosmetic, BlueprintImplementableEvent)
    void OnExternalUIChange(bool bInIsOpening, bool bIsSteamInputActive);

public:

    UFUNCTION(BlueprintCallable)
    void NotifyReleaseToListView(FName inNotifyEvent, UObject* ListViewData, TEnumAsByte<ESBUILogicType> inLogicType);

    UFUNCTION(BlueprintCallable)
    void NotifyPressToListView(FName inNotifyEvent, UObject* ListViewData, TEnumAsByte<ESBUILogicType> inLogicType, bool inItemSelection);

    UFUNCTION(BlueprintCallable)
    void NotifyDoubleClickToListView(FName inNotifyEvent, UObject* ListViewData, TEnumAsByte<ESBUILogicType> inLogicType, bool inItemSelection);

    UFUNCTION(BlueprintCallable)
    void NotifyClientRunEvent(TEnumAsByte<ESBZoneEventType> InEventType, FName InAlias);

    UFUNCTION(BlueprintCallable)
    void NotifyClickToListView(FName inNotifyEvent, UObject* ListViewData, TEnumAsByte<ESBUILogicType> inLogicType, bool inItemSelection);

    UFUNCTION(BlueprintCallable)
    void NotifyBlueprint(const FString& inEvent);

    UFUNCTION(BlueprintCallable)
    void LoadBrushAsyncResourceImageWidgets();

    UFUNCTION(BlueprintCallable)
    bool LastFocusActive(bool bRecursiveChild);

    UFUNCTION(BlueprintCallable)
    bool KeyReleased(FKey InKey);

    UFUNCTION(BlueprintCallable)
    bool KeyPressed(FKey InKey);

    UFUNCTION(BlueprintCallable)
    bool IsVisiblityParent(bool bRecursive);

    UFUNCTION(BlueprintCallable)
    bool IsTickActive();

    UFUNCTION(BlueprintCallable)
    bool IsSameParentGroupFoucs(USBUserWidget* InSBUserWidget, FName inWidgetName);

    UFUNCTION(BlueprintCallable)
    bool IsManagedParentGroupFocus();

    UFUNCTION(BlueprintCallable)
    bool IsKeyDown(FKey InKey);

    UFUNCTION(BlueprintCallable)
    bool IsFocusSBUserWidget();

protected:

    UFUNCTION(BlueprintCallable)
    bool IsAutoDestroy();

public:

    UFUNCTION(BlueprintCallable)
    void InvalidationRootWindow();

    UFUNCTION(BlueprintCallable)
    void InputWidgetUnbind(FName InActionName, TEnumAsByte<EInputEvent> InInputEvent, USBUserWidget* InReceiveTarget);

    UFUNCTION(BlueprintCallable)
    bool InputWidgetBind(USBUserWidget* InReceiveTarget, FName InActionName, int32 InPriority, TEnumAsByte<EInputEvent> InInputEvent);

    UFUNCTION(BlueprintCallable)
    bool HasFocusActive(bool bRecursiveChild);

    UFUNCTION(BlueprintCallable)
    USBUserWidget* GetUserWidgetFromTileView(UTileView* InListView, UObject* InDataObject);

    UFUNCTION(BlueprintCallable)
    USBUserWidget* GetUserWidgetFromListView(UListView* InListView, UObject* InDataObject);

    UFUNCTION(BlueprintCallable)
    UTexture2D* GetTextureStyleSetKey(USBTextureStyleSetData* InStyle, FKey InKey, TEnumAsByte<ESBTextureStyleType> InStyleType);

    UFUNCTION(BlueprintCallable)
    UTexture2D* GetTextureStyleSetAction(USBTextureStyleSetData* InStyle, FName InAction, TEnumAsByte<ESBTextureStyleType> InStyleType);

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    UWidget* GetSBNavigation(EUINavigation InNavigation);

    UFUNCTION(BlueprintCallable)
    FVector2D GetRightStickVector();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetRenderOpacityParent() const;

    UFUNCTION(BlueprintCallable)
    FVector2D GetLeftStickVector();

    UFUNCTION(BlueprintCallable)
    FName GenerateEventObserverNameKey(FName inWidgetName, FName inEventTag, const FString& inWidgetPath);

    UFUNCTION(BlueprintCallable)
    USBUserWidget* FoundParentWidgetHasUILogicType();

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    UWidget* FoundFirstFocusWidget();

    UFUNCTION(BlueprintCallable)
    USBUserWidgetEventObserver* FindWidgetEventObserverNameEventTag(FName inNameEventTag);

    UFUNCTION(BlueprintCallable)
    USBUserWidget* FindParentSBUserWidget(UWidget* InWidget, TEnumAsByte<ESBUILogicType> inLogicType);

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void EventWidgetPaused(bool InPause);

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void EventWidgetGroupFocusDeactive(FName InLastWidgetName, USBUserWidget* InLastUserWidget);

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void EventWidgetGroupFocusChanged(FName InLastWidgetName, USBUserWidget* InLastUserWidget, FName InNextWidgetName, USBUserWidget* InNextUserWidget);

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void EventWidgetGroupFocusActive(FName InNextWidgetName, USBUserWidget* InNextUserWidget);

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void EventWidgetFocusDeactive(FName InWidgetTag, UWidget* InWidget, USBUserWidget* InNextUserWidget, FName InNextWidgetTag, UWidget* InNextWidget);

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void EventWidgetFocusActive(FName InWidgetTag, UWidget* InWidget);

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void EventTileViewObjectUpdate(UObject* Data);

protected:

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void EventReleaseWidget();

public:

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void EventNotification(const FString& inEvent);

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void EventListViewObjectUpdate(UObject* Data);

protected:

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void EventInitWidget();

public:

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void EventFocusActivate(bool bActivate);

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void EventFirstWidgetFocus();

    UFUNCTION(BlueprintCallable)
    USBUserWidget* CreateDynamicChildUserWidget(TSubclassOf<USBUserWidget> InWidgetClass, UPanelWidget* InPanelWidget);

    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool ConsumeNotifyBlueprint(const FString& inEvent);

    // UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    // bool ConsumeInputEvent(USBUserWidget* InUserWidget, FName InActionName, TEnumAsByte<EInputEvent> InInputEvent);

    UFUNCTION(BlueprintCallable)
    void CloseSelf();

    UFUNCTION(BlueprintCallable)
    void ClearBrushAsyncResourceImageWidgets();

    UFUNCTION(BlueprintCallable)
    void AddChildSBUserWidget(USBUserWidget* SBUserWidget, bool InNotRelease);
};

//
// inline void USBUserWidget::SetTickActive(bool bActive)
// {
// }
//
// inline void USBUserWidget::SetEnableAutoDestroy(bool bEnable)
// {
// }
//
// inline void USBUserWidget::SendWidgetInputEvent(FName InActionName, TEnumAsByte<EInputEvent> InInputEvent, TEnumAsByte<ESBUILogicType> InTargetLogicType)
// {
// }
//
// inline void USBUserWidget::SelectItemToListView(UObject* ListViewData, TEnumAsByte<ESBUILogicType> inLogicType)
// {
// }
//
// inline void USBUserWidget::RestoreFocusToListView(UListView* ListView, UObject* ListViewData)
// {
// }
//
// inline void USBUserWidget::RequestWidgetFocus(UWidget* InWidget)
// {
// }
//
// inline void USBUserWidget::RemoveDynamicChildUserWidget(USBUserWidget* InSBUserWidget)
// {
// }
//
// inline void USBUserWidget::RemoveChildSBUserWidget(USBUserWidget* SBUserWidget)
// {
// }
//
// inline bool USBUserWidget::OnWidgetFocusRestore_Implementation()
// {
//     return false;
// }
//
// inline void USBUserWidget::NotifyReleaseToListView(FName inNotifyEvent, UObject* ListViewData, TEnumAsByte<ESBUILogicType> inLogicType)
// {
// }
//
// inline void USBUserWidget::NotifyPressToListView(FName inNotifyEvent, UObject* ListViewData, TEnumAsByte<ESBUILogicType> inLogicType, bool inItemSelection)
// {
// }
//
// inline void USBUserWidget::NotifyDoubleClickToListView(FName inNotifyEvent, UObject* ListViewData, TEnumAsByte<ESBUILogicType> inLogicType, bool inItemSelection)
// {
// }
//
// inline void USBUserWidget::NotifyClientRunEvent(TEnumAsByte<ESBZoneEventType> InEventType, FName InAlias)
// {
// }
//
// inline void USBUserWidget::NotifyClickToListView(FName inNotifyEvent, UObject* ListViewData, TEnumAsByte<ESBUILogicType> inLogicType, bool inItemSelection)
// {
// }
//
// inline void USBUserWidget::NotifyBlueprint(const FString& inEvent)
// {
// }
//
// inline void USBUserWidget::LoadBrushAsyncResourceImageWidgets()
// {
// }
//
// inline bool USBUserWidget::LastFocusActive(bool bRecursiveChild)
// {
// return false;
// }
//
// inline bool USBUserWidget::KeyReleased(FKey InKey)
// {
// return false;
// }
//
// inline bool USBUserWidget::KeyPressed(FKey InKey)
// {
// return false;
// }
//
// inline bool USBUserWidget::IsVisiblityParent(bool bRecursive)
// {
// return false;
// }
//
// inline bool USBUserWidget::IsTickActive()
// {
// return false;
// }
//
// inline bool USBUserWidget::IsSameParentGroupFoucs(USBUserWidget* InSBUserWidget, FName inWidgetName)
// {
// return false;
// }
//
// inline bool USBUserWidget::IsManagedParentGroupFocus()
// {
// return false;
// }
//
// inline bool USBUserWidget::IsKeyDown(FKey InKey)
// {
// return false;
// }
//
// inline bool USBUserWidget::IsFocusSBUserWidget()
// {
// return false;
// }
//
// inline bool USBUserWidget::IsAutoDestroy()
// {
// return false;
// }
//
// inline void USBUserWidget::InvalidationRootWindow()
// {
// }
//
// inline void USBUserWidget::InputWidgetUnbind(FName InActionName, TEnumAsByte<EInputEvent> InInputEvent, USBUserWidget* InReceiveTarget)
// {
// }
//
// inline bool USBUserWidget::InputWidgetBind(USBUserWidget* InReceiveTarget, FName InActionName, int32 InPriority, TEnumAsByte<EInputEvent> InInputEvent)
// {
// return false;
// }
//
// inline bool USBUserWidget::HasFocusActive(bool bRecursiveChild)
// {
// return false;
// }
//
// inline USBUserWidget* USBUserWidget::GetUserWidgetFromTileView(UTileView* InListView, UObject* InDataObject)
// {
// return nullptr;
// }
//
// inline USBUserWidget* USBUserWidget::GetUserWidgetFromListView(UListView* InListView, UObject* InDataObject)
// {
// return nullptr;
// }
//
// inline UTexture2D* USBUserWidget::GetTextureStyleSetKey(USBTextureStyleSetData* InStyle, FKey InKey, TEnumAsByte<ESBTextureStyleType> InStyleType)
// {
// return nullptr;
// }
//
// inline UTexture2D* USBUserWidget::GetTextureStyleSetAction(USBTextureStyleSetData* InStyle, FName InAction, TEnumAsByte<ESBTextureStyleType> InStyleType)
// {
// return nullptr;
// }
//
// inline UWidget* USBUserWidget::GetSBNavigation_Implementation(EUINavigation InNavigation)
// {
// return nullptr;
// }
//
// inline FVector2D USBUserWidget::GetRightStickVector()
// {
// return {};
// }
//
// inline float USBUserWidget::GetRenderOpacityParent() const
// {
//     return 0;
// }
//
// inline FVector2D USBUserWidget::GetLeftStickVector()
// {
// return {};
// }
//
// inline FName USBUserWidget::GenerateEventObserverNameKey(FName inWidgetName, FName inEventTag, const FString& inWidgetPath)
// {
//
//     return {};
// }
//
// inline USBUserWidget* USBUserWidget::FoundParentWidgetHasUILogicType()
// {
// return nullptr;
// }
//
// inline UWidget* USBUserWidget::FoundFirstFocusWidget_Implementation()
// {
// return nullptr;
// }
//
// inline USBUserWidgetEventObserver* USBUserWidget::FindWidgetEventObserverNameEventTag(FName inNameEventTag)
// {
//     return nullptr;
// }
//
// inline USBUserWidget* USBUserWidget::FindParentSBUserWidget(UWidget* InWidget, TEnumAsByte<ESBUILogicType> inLogicType)
// {
// return nullptr;
// }
//
// inline USBUserWidget* USBUserWidget::CreateDynamicChildUserWidget(TSubclassOf<USBUserWidget> InWidgetClass, UPanelWidget* InPanelWidget)
// {
// return nullptr;
// }
//
// inline bool USBUserWidget::ConsumeNotifyBlueprint_Implementation(const FString& inEvent)
// {
// return false;
// }
//
// // inline bool USBUserWidget::ConsumeInputEvent_Implementation(USBUserWidget* InUserWidget, FName InActionName, TEnumAsByte<EInputEvent> InInputEvent)
// // {
// // return false;
// // }
//
//
//
// inline void USBUserWidget::CloseSelf()
// {
// }
//
// inline void USBUserWidget::ClearBrushAsyncResourceImageWidgets()
// {
// }
//
// inline void USBUserWidget::AddChildSBUserWidget(USBUserWidget* SBUserWidget, bool InNotRelease)
// {
// }