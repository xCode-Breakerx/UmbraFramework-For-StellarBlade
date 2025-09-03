#pragma once
#include "CoreMinimal.h"
#include "SBTextureStyleInfo.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)

struct SB_API FSBTextureStyleInfo
{
    GENERATED_BODY()

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UTexture2D* Default;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UTexture2D* StanardKeyboard;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UTexture2D* StanardJoystic;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UTexture2D* PS4;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UTexture2D* XBox;
};
