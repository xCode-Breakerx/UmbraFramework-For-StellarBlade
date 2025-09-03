#pragma once
#include "CoreMinimal.h"
#include "ESBSkelMeshSlot.generated.h"

UENUM(BlueprintType)

enum ESBSkelMeshSlot
{
    ESBMesh_Body,
    ESBMesh_Face,
    ESBMesh_Hair1,
    ESBMesh_Ponytail,
    ESBMesh_PonytailShort,
    ESBMesh_Weapon1,
    ESBMesh_Weapon2,
    ESBMesh_Weapon3,
    ESBMesh_Weapon4,
    ESBMesh_Accessory1,
    ESBMesh_Accessory2,
    ESBMesh_Accessory3,
    ESBMesh_Accessory4,
    ESBMesh_Accessory5,
    ESBMesh_Etc1,
    ESBMesh_Etc2,
    ESBMesh_Num,
    ESBMesh_All = 100,
};
