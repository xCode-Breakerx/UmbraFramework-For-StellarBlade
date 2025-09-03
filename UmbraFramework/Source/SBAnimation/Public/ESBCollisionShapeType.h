#pragma once
#include "CoreMinimal.h"
#include "ESBCollisionShapeType.generated.h"

UENUM(BlueprintType)
enum ESBCollisionShapeType {
    ESBCollisionShapeType_None,
    ESBCollisionShapeType_Line,
    ESBCollisionShapeType_Box,
    ESBCollisionShapeType_Sphere,
    ESBCollisionShapeType_Capsule,
};

