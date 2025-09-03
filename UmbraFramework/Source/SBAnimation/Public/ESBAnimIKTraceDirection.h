#pragma once
#include "CoreMinimal.h"
#include "ESBAnimIKTraceDirection.generated.h"

UENUM(BlueprintType)
enum ESBAnimIKTraceDirection {
    ESBAnimTraceDir_Forward,
    ESBAnimTraceDir_Right,
    ESBAnimTraceDir_Up,
    ESBAnimTraceDir_InverseForward,
    ESBAnimTraceDir_InverseRight,
    ESBAnimTraceDir_InverseUp,
};

