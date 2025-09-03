#pragma once
#include "CoreMinimal.h"
#include "ESBPhysicHitType.generated.h"

UENUM(BlueprintType)

enum ESBPhysicHitType
{
    ESBPhysicHitType_AddForceDir,
    ESBPhysicHitType_AddForceImpactPoint,
};
