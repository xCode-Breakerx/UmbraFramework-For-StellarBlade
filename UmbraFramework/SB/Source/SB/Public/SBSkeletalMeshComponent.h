#pragma once
#include "CoreMinimal.h"
// CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Quat -FallbackName=Quat
// CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
// CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=SkeletalMeshComponent -FallbackName=SkeletalMeshComponent
// CROSS-MODULE INCLUDE V2: -ModuleName=SBAnimation -ObjectName=SBEventMoveIKData -FallbackName=SBEventMoveIKData
// CROSS-MODULE INCLUDE V2: -ModuleName=SBAnimation -ObjectName=SBMovementBoneData -FallbackName=SBMovementBoneData
#include "BoneAnimScaleIgnoreInfo.h"
#include "ESBMeshAttachType.h"
#include "ESBPhysicHitType.h"
#include "ESBSkelMeshSlot.h"
#include "MaterialDefaultInfo.h"
#include "SBEventMoveIKData.h"
#include "SBMovementBoneData.h"
#include "VertexShakeInfo.h"
#include "SBSkeletalMeshComponent.generated.h"

class UPhysicsAsset;
class USceneComponent;

UCLASS(Blueprintable, EditInlineNew, ClassGroup = Custom, meta = (BlueprintSpawnableComponent))

class SB_API USBSkeletalMeshComponent : public USkeletalMeshComponent
{
    GENERATED_BODY()

public:

protected:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector LastKeepAllBodiesBoneLocation;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FQuat LastKeepAllBodiesBoneQuat;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    TArray<float> HistoryResetPhysVelocty;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    TArray<float> HistoryResetPhysDegree;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    int32 CurrentHistoryResetPhysNum;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    int32 CurrentMaxHistoryResetPhysNum;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RemainResetPhysics;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TEnumAsByte<ESBSkelMeshSlot> MeshSlot;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TEnumAsByte<ESBMeshAttachType> MeshSlotAttachType;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    TArray<FMaterialDefaultInfo> MaterialParamDefaultValue;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TArray<FName> DynamicPhysicControlBones;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TArray<FName> DynamicPhysicExclusiveBones;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FName CustomAnimStateName;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float CustomAnimWeight;

    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    uint8 bUseDynamicBound : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FName SBSkeletalMeshTag;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float OverrideOffsetLODViewAngle;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    int32 OverrideOffsetLODValue;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FVector AdditiveBoundsBoxExtent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bDisableComponentsClothTick;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float ComponentsClothTickDistance;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    TMap<FName, FSBEventMoveIKData> IKTargetInfoMap;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    TArray<FSBEventMoveIKData> DurationIKDataList;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bPlayDynamicPhysicBoneControl;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RemainDynamicPhysicBoneDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float DynamicPhysicBoneDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float DynamicPhysicBoneBlendInTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float DynamicPhysicBoneBlendOutTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float DynamicPhysicBoneWeight;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float DynamicPhysicBoneIgnoreRemainTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector PhysicalHitForceVector;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FName PhysicalHitForceTargetBone;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector PhysicalHitForceLocation;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float PhysicalHitForcePower;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    TEnumAsByte<ESBPhysicHitType> PhysicalHitType;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bSetDynamicPhysicBelowAll;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVertexShakeInfo VertexShakeInfo;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FBoneAnimScaleIgnoreInfo BoneAnimScaleIgnoreInfo;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FName RestoreAttachBoneName;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta = (AllowPrivateAccess = true))
    USceneComponent* RestoreAttachComponent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    TArray<FSBMovementBoneData> MovementBoneDataList;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bReturnRelativeBlendOffset;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float CurrentRelativeBlendOffsetTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RelativeBlendToTargetTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RelativeBlendReturnTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector RelativeBlendOffset;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector BackupRelativeLocation;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float CurrentPhysicsWeightBlendTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float PhysicsWeightBlendTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float TargetPhysicsWeight;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float CurrentMassScale;

public:

    UFUNCTION(BlueprintCallable)
    void SetPhysicsBodySimulate(FVector InForce, const FName& InBoneName, bool bNewSimulate, float InBlendWeight, bool InSetBelowAllBody, bool bIncludeSelf);

    UFUNCTION(BlueprintCallable)
    void SetPhysicsAssetAndKeepTransform(UPhysicsAsset* NewPhysicsAsset, bool bForceReInit);

    UFUNCTION(BlueprintCallable)
    void SetEnableGravityPhysicsBones(bool bFlag, const TArray<FName>& InBoneArray);

    UFUNCTION(BlueprintCallable)
    void SetCustomAnimWeight(float InAnimWeight);

    UFUNCTION(BlueprintCallable)
    void SetCustomAnimStateName(FName InAnimStateName);

    UFUNCTION(BlueprintCallable)
    void SetBlendPhysicsWeight(bool bInEnablePhysic, float InBlendTime);

    UFUNCTION(BlueprintCallable)
    void ResetOverrideMaterials();

    UFUNCTION(BlueprintCallable)
    FName GetSBSkeletalMeshTag();

    UFUNCTION(BlueprintCallable)
    float GetCustomAnimWeight();

    UFUNCTION(BlueprintCallable)
    FName GetCustomAnimStateName();

    UFUNCTION(BlueprintCallable)
    void FindEventMoveIKData(FName InBoneName, FSBEventMoveIKData& OutIKData);

    UFUNCTION(BlueprintCallable)
    void ClearBlendPhysicsWeight();
};
