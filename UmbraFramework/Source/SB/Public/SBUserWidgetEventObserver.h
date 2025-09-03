#pragma once
#include "CoreMinimal.h"
// CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "SBUserWidgetEventObserver.generated.h"

UCLASS(Blueprintable)

class SB_API USBUserWidgetEventObserver : public UObject
{
    GENERATED_BODY()

public:

    USBUserWidgetEventObserver()
    {
    }

private:

    UFUNCTION(BlueprintCallable)

    void OnWidgetListViewEvent(UObject* InData)
    {
    }

    UFUNCTION(BlueprintCallable)

    void OnWidgetEvent()
    {
    }

public:

    UFUNCTION(BlueprintCallable)

    void NotifyListViewRelease(UObject* InData)
    {
    }

    UFUNCTION(BlueprintCallable)

    void NotifyListViewPress(UObject* InData)
    {
    }

    UFUNCTION(BlueprintCallable)

    void NotifyListViewDoubleClick(UObject* InData)
    {
    }

    UFUNCTION(BlueprintCallable)

    void NotifyListViewClick(UObject* InData)
    {
    }
};
