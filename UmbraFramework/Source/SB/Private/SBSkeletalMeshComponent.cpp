#include "SBSkeletalMeshComponent.h"

void USBSkeletalMeshComponent::SetPhysicsBodySimulate(FVector InForce, const FName& InBoneName, bool bNewSimulate, float InBlendWeight, bool InSetBelowAllBody, bool bIncludeSelf)
{
}

void USBSkeletalMeshComponent::SetPhysicsAssetAndKeepTransform(UPhysicsAsset* NewPhysicsAsset, bool bForceReInit)
{
}

void USBSkeletalMeshComponent::SetEnableGravityPhysicsBones(bool bFlag, const TArray<FName>& InBoneArray)
{
}

void USBSkeletalMeshComponent::SetCustomAnimWeight(float InAnimWeight)
{
}

void USBSkeletalMeshComponent::SetCustomAnimStateName(FName InAnimStateName)
{
}

void USBSkeletalMeshComponent::SetBlendPhysicsWeight(bool bInEnablePhysic, float InBlendTime)
{
}

void USBSkeletalMeshComponent::ResetOverrideMaterials()
{
}

FName USBSkeletalMeshComponent::GetSBSkeletalMeshTag()
{
    return NAME_None;
}

float USBSkeletalMeshComponent::GetCustomAnimWeight()
{
    return 0.0f;
}

FName USBSkeletalMeshComponent::GetCustomAnimStateName()
{
    return NAME_None;
}

void USBSkeletalMeshComponent::FindEventMoveIKData(FName InBoneName, FSBEventMoveIKData& OutIKData)
{
}

void USBSkeletalMeshComponent::ClearBlendPhysicsWeight()
{
}
