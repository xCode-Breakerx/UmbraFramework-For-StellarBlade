#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
// CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=TableRowBase
// -FallbackName=TableRowBase
#include "SBTablePropertyBase.generated.h"

USTRUCT(BlueprintType)

struct FSBTablePropertyBase : public FTableRowBase
{
    GENERATED_BODY()
};
