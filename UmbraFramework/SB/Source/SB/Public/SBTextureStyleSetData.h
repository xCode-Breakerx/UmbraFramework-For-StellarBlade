#pragma once
#include "CoreMinimal.h"
// CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=DataAsset -FallbackName=DataAsset
// CROSS-MODULE INCLUDE V2: -ModuleName=InputCore -ObjectName=Key -FallbackName=Key
#include "ESBTextureStyleType.h"
#include "SBTextureStyleInfo.h"
#include "SBTextureStyleSetData.generated.h"

class UTexture2D;

UCLASS(Blueprintable)

class SB_API USBTextureStyleSetData : public UDataAsset
{
    GENERATED_BODY()

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TMap<FName, FSBTextureStyleInfo> actions;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TMap<FKey, FSBTextureStyleInfo> Keys;

    USBTextureStyleSetData();

    UFUNCTION(BlueprintCallable)
    UTexture2D* GetTextureFromKey(const FKey& InKey, TEnumAsByte<ESBTextureStyleType> InStyleType);

    UFUNCTION(BlueprintCallable)
    UTexture2D* GetTextureFromAction(const FName& InAction, TEnumAsByte<ESBTextureStyleType> InStyleType);
};

inline USBTextureStyleSetData::USBTextureStyleSetData()
{
}

inline UTexture2D* USBTextureStyleSetData::GetTextureFromKey(const FKey& InKey, TEnumAsByte<ESBTextureStyleType> InStyleType)
{
    return nullptr;
}

inline UTexture2D* USBTextureStyleSetData::GetTextureFromAction(const FName& InAction, TEnumAsByte<ESBTextureStyleType> InStyleType)
{
    return nullptr;
}