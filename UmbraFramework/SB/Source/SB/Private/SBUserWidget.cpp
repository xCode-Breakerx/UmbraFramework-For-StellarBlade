#include "SBUserWidget.h"
#include "Templates/SubclassOf.h"

USBUserWidget::USBUserWidget() : UUserWidget(FObjectInitializer::Get())
{
    ParentWidget                         = NULL;
    TargetUILogic                        = ESBUILogicType_NONE;
    bUseInputOnly                        = true;
    bInputOnlyWhenAllBlock               = true;
    InputOpenBlockTime                   = 0.30f;
    bUseGroupFocus                       = false;
    bUseShowMouseCursor                  = false;
    bMouseCursorVisibleWhenKeyboardInput = false;
    bIgnorePause                         = false;
    bTickActive                          = true;
    bAccessSuperClassProperty            = false;
    RemainInvalidateRootCount            = 3;
    bActiveMouseCursor                   = false;
    RestoreFocusCheckRemainCount         = 0;
    bCheckEventWidgetFocusRestore        = false;
    bBindEventWidgetFocusRestore         = false;
}

void USBUserWidget::SetTickActive(bool bActive)
{
}

void USBUserWidget::SetEnableAutoDestroy(bool bEnable)
{
}

void USBUserWidget::SendWidgetInputEvent(FName InActionName, TEnumAsByte<EInputEvent> InInputEvent, TEnumAsByte<ESBUILogicType> InTargetLogicType)
{
}

void USBUserWidget::SelectItemToListView(UObject* ListViewData, TEnumAsByte<ESBUILogicType> inLogicType)
{
}

void USBUserWidget::RestoreFocusToListView(UListView* ListView, UObject* ListViewData)
{
}

void USBUserWidget::RequestWidgetFocus(UWidget* InWidget)
{
}

void USBUserWidget::RemoveDynamicChildUserWidget(USBUserWidget* InSBUserWidget)
{
}

void USBUserWidget::RemoveChildSBUserWidget(USBUserWidget* SBUserWidget)
{
}

bool USBUserWidget::OnWidgetFocusRestore_Implementation()
{
    return false;
}

void USBUserWidget::NotifyReleaseToListView(FName inNotifyEvent, UObject* ListViewData, TEnumAsByte<ESBUILogicType> inLogicType)
{
}

void USBUserWidget::NotifyPressToListView(FName inNotifyEvent, UObject* ListViewData, TEnumAsByte<ESBUILogicType> inLogicType, bool inItemSelection)
{
}

void USBUserWidget::NotifyDoubleClickToListView(FName inNotifyEvent, UObject* ListViewData, TEnumAsByte<ESBUILogicType> inLogicType, bool inItemSelection)
{
}

void USBUserWidget::NotifyClientRunEvent(TEnumAsByte<ESBZoneEventType> InEventType, FName InAlias)
{
}

void USBUserWidget::NotifyClickToListView(FName inNotifyEvent, UObject* ListViewData, TEnumAsByte<ESBUILogicType> inLogicType, bool inItemSelection)
{
}

void USBUserWidget::NotifyBlueprint(const FString& inEvent)
{
}

void USBUserWidget::LoadBrushAsyncResourceImageWidgets()
{
}

bool USBUserWidget::LastFocusActive(bool bRecursiveChild)
{
    return false;
}

bool USBUserWidget::KeyReleased(FKey InKey)
{
    return false;
}

bool USBUserWidget::KeyPressed(FKey InKey)
{
    return false;
}

bool USBUserWidget::IsVisiblityParent(bool bRecursive)
{
    return false;
}

bool USBUserWidget::IsTickActive()
{
    return false;
}

bool USBUserWidget::IsSameParentGroupFoucs(USBUserWidget* InSBUserWidget, FName inWidgetName)
{
    return false;
}

bool USBUserWidget::IsManagedParentGroupFocus()
{
    return false;
}

bool USBUserWidget::IsKeyDown(FKey InKey)
{
    return false;
}

bool USBUserWidget::IsFocusSBUserWidget()
{
    return false;
}

bool USBUserWidget::IsAutoDestroy()
{
    return false;
}

void USBUserWidget::InvalidationRootWindow()
{
}

void USBUserWidget::InputWidgetUnbind(FName InActionName, TEnumAsByte<EInputEvent> InInputEvent, USBUserWidget* InReceiveTarget)
{
}

bool USBUserWidget::InputWidgetBind(USBUserWidget* InReceiveTarget, FName InActionName, int32 InPriority, TEnumAsByte<EInputEvent> InInputEvent)
{
    return false;
}

bool USBUserWidget::HasFocusActive(bool bRecursiveChild)
{
    return false;
}

USBUserWidget* USBUserWidget::GetUserWidgetFromTileView(UTileView* InListView, UObject* InDataObject)
{
    return NULL;
}

USBUserWidget* USBUserWidget::GetUserWidgetFromListView(UListView* InListView, UObject* InDataObject)
{
    return NULL;
}

UTexture2D* USBUserWidget::GetTextureStyleSetKey(USBTextureStyleSetData* InStyle, FKey InKey, TEnumAsByte<ESBTextureStyleType> InStyleType)
{
    return NULL;
}

UTexture2D* USBUserWidget::GetTextureStyleSetAction(USBTextureStyleSetData* InStyle, FName InAction, TEnumAsByte<ESBTextureStyleType> InStyleType)
{
    return NULL;
}

UWidget* USBUserWidget::GetSBNavigation_Implementation(EUINavigation InNavigation)
{
    return NULL;
}

FVector2D USBUserWidget::GetRightStickVector()
{
    return FVector2D{};
}

float USBUserWidget::GetRenderOpacityParent() const
{
    return 0.0f;
}

FVector2D USBUserWidget::GetLeftStickVector()
{
    return FVector2D{};
}

FName USBUserWidget::GenerateEventObserverNameKey(FName inWidgetName, FName inEventTag, const FString& inWidgetPath)
{
    return NAME_None;
}

USBUserWidget* USBUserWidget::FoundParentWidgetHasUILogicType()
{
    return NULL;
}

UWidget* USBUserWidget::FoundFirstFocusWidget_Implementation()
{
    return NULL;
}

USBUserWidgetEventObserver* USBUserWidget::FindWidgetEventObserverNameEventTag(FName inNameEventTag)
{
    return NULL;
}

USBUserWidget* USBUserWidget::FindParentSBUserWidget(UWidget* InWidget, TEnumAsByte<ESBUILogicType> inLogicType)
{
    return NULL;
}

USBUserWidget* USBUserWidget::CreateDynamicChildUserWidget(TSubclassOf<USBUserWidget> InWidgetClass, UPanelWidget* InPanelWidget)
{
    return NULL;
}

bool USBUserWidget::ConsumeNotifyBlueprint_Implementation(const FString& inEvent)
{
    return false;
}

// bool USBUserWidget::ConsumeInputEvent_Implementation(USBUserWidget* InUserWidget, FName InActionName, TEnumAsByte<EInputEvent> InInputEvent)
// {
//     return false;
// }

void USBUserWidget::CloseSelf()
{
}

void USBUserWidget::ClearBrushAsyncResourceImageWidgets()
{
}

void USBUserWidget::AddChildSBUserWidget(USBUserWidget* SBUserWidget, bool InNotRelease)
{
}
