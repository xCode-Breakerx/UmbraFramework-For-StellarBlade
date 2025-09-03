#include "SBCharacter.h"
#include "Net/UnrealNetwork.h"

#include "SBSkeletalMeshComponent.h"

void ASBCharacter::WeaponForceHide(bool bHide)
{
}

void ASBCharacter::UpdateEyePosition(bool inReset)
{
}

void ASBCharacter::StartFlyingAction()
{
}

void ASBCharacter::StartClimbing(FHitResult Hit)
{
}

void ASBCharacter::SetOverridePonytailClothPhysicsAsset(UPhysicsAsset* inClothPhysicsAsset)
{
}

void ASBCharacter::SetOverrideClothPhysicsAsset(const FString& inMeshPath, bool inApplyHair, bool inFromBodyMesh)
{
}

void ASBCharacter::SetMoveToTargetLocation(FVector InTargetLocation, FVector InTargetDirection, float InMoveSpeedPerSec, float InMinimumDistToTarget, USceneComponent* pBaseComp, float InAfterBlockMoveInputDuration)
{
}

void ASBCharacter::SetMoveInputBlockDuration(float InDuration)
{
}

void ASBCharacter::SetMoveInputBlock(bool inMoveBlock)
{
}

void ASBCharacter::SetLockupSimulatePhysics(bool inLockupSimulatePhysics)
{
}

void ASBCharacter::SetKinematicForShortPonytail(bool bFlag)
{
}

void ASBCharacter::SetKeepAllBodiesPhysicsTransform(int32 inKeepFrame)
{
}

void ASBCharacter::SetGlobalMaterialScalarParameterValue(FName InParameterName, float InValue)
{
}

void ASBCharacter::SetEnableCollision(bool bEnable)
{
}

void ASBCharacter::SetDroneSpotLight(USpotLightComponent* inSpotLightComponent)
{
}

void ASBCharacter::SetDollyCamMode(bool bFlag)
{
}

void ASBCharacter::SetCustomFloat(FName inCustom, float InValue)
{
}

void ASBCharacter::SetCustomBool(FName inCustom, bool InValue)
{
}

void ASBCharacter::SetClothAdditiveWindDirection(FVector inAdditiveWindDirection)
{
}

void ASBCharacter::SetCamOverrideFovMode(float NewFOV, float BlendTime)
{
}

void ASBCharacter::SetCameraLagSpeed(float InSpeed)
{
}

bool ASBCharacter::SetBlackboardVectorValue(FName InName, FVector InValue)
{
    return false;
}

bool ASBCharacter::SetBlackboardIntValue(FName InName, int32 InValue)
{
    return false;
}

bool ASBCharacter::SetBlackboardFloatValue(FName InName, float InValue)
{
    return false;
}

void ASBCharacter::SetActivateFootIK(const FString& CallStack, bool bInActive, float InBlendTime, float InTargetValue, float InApplyDelayTime, bool bInForceApply, float InPriority)
{
}

void ASBCharacter::SetActivateFeetIK(bool bInActive)
{
}

void ASBCharacter::ServerRequest_DoJump_Implementation(bool inbJump, bool inbJumpDir, FVector inJumpDir)
{
}

void ASBCharacter::ServerMoveWrapper_Implementation(float Timestamp, FVector_NetQuantize10 InAccel, FVector_NetQuantize100 ClientLoc, uint8 CompressedMoveFlags, uint8 ClientRoll, uint32 View, UPrimitiveComponent* ClientMovementBase, FName ClientBaseBoneName, uint8 ClientMovementMode)
{
}

bool ASBCharacter::ServerMoveWrapper_Validate(float Timestamp, FVector_NetQuantize10 InAccel, FVector_NetQuantize100 ClientLoc, uint8 CompressedMoveFlags, uint8 ClientRoll, uint32 View, UPrimitiveComponent* ClientMovementBase, FName ClientBaseBoneName, uint8 ClientMovementMode)
{
    return true;
}

void ASBCharacter::ServerMoveNoBaseWrapper_Implementation(float Timestamp, FVector_NetQuantize10 InAccel, FVector_NetQuantize100 ClientLoc, uint8 CompressedMoveFlags, uint8 ClientRoll, uint32 View, uint8 ClientMovementMode)
{
}

bool ASBCharacter::ServerMoveNoBaseWrapper_Validate(float Timestamp, FVector_NetQuantize10 InAccel, FVector_NetQuantize100 ClientLoc, uint8 CompressedMoveFlags, uint8 ClientRoll, uint32 View, uint8 ClientMovementMode)
{
    return true;
}

float ASBCharacter::RopeSwingPendulumAnglePerAlpha()
{
    return 0.0f;
}

void ASBCharacter::RegisterFXSystem(UFXSystemComponent* inFXSystem)
{
}

void ASBCharacter::OnToggleClimbCam()
{
}

void ASBCharacter::OnRep_BroadcastSpawnInfo()
{
}

void ASBCharacter::OnFinishedLevelSequence()
{
}

void ASBCharacter::OnCollisionOriginHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
}

void ASBCharacter::OnCollisionOriginEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

void ASBCharacter::OnCollisionOriginBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void ASBCharacter::OnCapsuleComponentEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

void ASBCharacter::OnCapsuleComponentBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

bool ASBCharacter::IsWireMoving()
{
    return false;
}

bool ASBCharacter::IsWallRunJumpScaleOverrided(float& OutValue)
{
    return false;
}

bool ASBCharacter::IsWallRunJump()
{
    return false;
}

bool ASBCharacter::IsWallRun()
{
    return false;
}

bool ASBCharacter::IsWallHitAction()
{
    return false;
}

bool ASBCharacter::IsVisibleSwordTrail()
{
    return false;
}

bool ASBCharacter::IsValidTachyWingSnapshotDataPath() const
{
    return false;
}

bool ASBCharacter::IsValidMoveRightSmoothValue(bool inIgnoreGamePad)
{
    return false;
}

bool ASBCharacter::IsValidHairSnapshotDataPath() const
{
    return false;
}

bool ASBCharacter::IsUseSlopeMovingCamera()
{
    return false;
}

bool ASBCharacter::IsUnderWaterSwimming()
{
    return false;
}

bool ASBCharacter::IsTPSMode()
{
    return false;
}

bool ASBCharacter::IsSwimJumping()
{
    return false;
}

bool ASBCharacter::IsSprintJump()
{
    return false;
}

bool ASBCharacter::IsSprint()
{
    return false;
}

bool ASBCharacter::IsSlopeMoving()
{
    return false;
}

bool ASBCharacter::IsSlopeJumpOut()
{
    return false;
}

bool ASBCharacter::IsSlopeJumping()
{
    return false;
}

bool ASBCharacter::IsSlideSlipJumping()
{
    return false;
}

bool ASBCharacter::IsSlideSlipFalling()
{
    return false;
}

bool ASBCharacter::IsSideRodWallless()
{
    return false;
}

bool ASBCharacter::IsSideRodJumping()
{
    return false;
}

bool ASBCharacter::IsSideRodFalling()
{
    return false;
}

bool ASBCharacter::IsShowCharacter()
{
    return false;
}

bool ASBCharacter::IsShortPonyTail()
{
    return false;
}

bool ASBCharacter::IsRunSpiderNavWay() const
{
    return false;
}

bool ASBCharacter::IsRunningSkill()
{
    return false;
}

bool ASBCharacter::IsRunningInteraction()
{
    return false;
}

bool ASBCharacter::IsRunHuddleUpAction()
{
    return false;
}

bool ASBCharacter::IsRun()
{
    return false;
}

bool ASBCharacter::IsRopeSwing()
{
    return false;
}

bool ASBCharacter::IsRopeMoving()
{
    return false;
}

bool ASBCharacter::IsRodJumping()
{
    return false;
}

bool ASBCharacter::IsRagdollSimulate(bool isAllBodies)
{
    return false;
}

bool ASBCharacter::IsPlayJumpTransitAnim()
{
    return false;
}

bool ASBCharacter::IsPlayingRunInteraction()
{
    return false;
}

bool ASBCharacter::IsPlayableWhenLevelSequence()
{
    return false;
}

bool ASBCharacter::IsPhotoModeFacialAnimationEnabled()
{
    return false;
}

bool ASBCharacter::IsPhotoModeDefaultWeaponSnapshot() const
{
    return false;
}

bool ASBCharacter::IsPhotoModeDefaultSnapshot() const
{
    return false;
}

bool ASBCharacter::IsOverrideBlendSpaceUpper()
{
    return false;
}

bool ASBCharacter::IsOverriddenBlendSpacePlayerActive()
{
    return false;
}

bool ASBCharacter::IsNeedPlayTurnAnim()
{
    return false;
}

bool ASBCharacter::IsMovingTargetOn()
{
    return false;
}

bool ASBCharacter::IsMoving()
{
    return false;
}

bool ASBCharacter::IsMoveInputBlock()
{
    return false;
}

bool ASBCharacter::IsMoveBlockedByWall()
{
    return false;
}

bool ASBCharacter::IsMoveBackByTargetOverlap()
{
    return false;
}

bool ASBCharacter::IsMotionMoving()
{
    return false;
}

bool ASBCharacter::IsMetaAITiredState()
{
    return false;
}

bool ASBCharacter::IsLockOn()
{
    return false;
}

bool ASBCharacter::IsJumping()
{
    return false;
}

bool ASBCharacter::IsJoggingRun()
{
    return false;
}

bool ASBCharacter::IsHoldSwimming()
{
    return false;
}

bool ASBCharacter::IsHoldBalanceBeam()
{
    return false;
}

bool ASBCharacter::IsHidePonyTail()
{
    return false;
}

bool ASBCharacter::IsGrabObjectMoving()
{
    return false;
}

bool ASBCharacter::IsGlide()
{
    return false;
}

bool ASBCharacter::IsFlyingAction()
{
    return false;
}

bool ASBCharacter::IsFishingReel()
{
    return false;
}

bool ASBCharacter::IsExistFloor()
{
    return false;
}

bool ASBCharacter::IsEventMovingSlidingState()
{
    return false;
}

bool ASBCharacter::IsEventMoving()
{
    return false;
}

bool ASBCharacter::IsEnableKneeIK()
{
    return false;
}

bool ASBCharacter::IsDoubleJump()
{
    return false;
}

bool ASBCharacter::IsDisableLookAtEye()
{
    return false;
}

bool ASBCharacter::IsDisableIdleAdditiveAnim()
{
    return false;
}

bool ASBCharacter::IsDisableFootIKWhenRideOnVehicle()
{
    return false;
}

bool ASBCharacter::IsCurrentStretchSideRodSearch()
{
    return false;
}

bool ASBCharacter::IsClimbing()
{
    return false;
}

bool ASBCharacter::IsBlockingMode()
{
    return false;
}

bool ASBCharacter::IsbDoWallJump()
{
    return false;
}

bool ASBCharacter::IsBattle()
{
    return false;
}

bool ASBCharacter::IsAttackParried()
{
    return false;
}

bool ASBCharacter::IsAttachedToLevelSequenceWithoutPlayable()
{
    return false;
}

bool ASBCharacter::IsAllowLookAtTargetWhenLevelSequence()
{
    return false;
}

bool ASBCharacter::IsActiveTPSAimOffset()
{
    return false;
}

bool ASBCharacter::IsActiveOverlapMove()
{
    return false;
}

bool ASBCharacter::IsActiveFullBodyIK_ByName(const FString& Name)
{
    return false;
}

bool ASBCharacter::IsActiveFullBodyIK()
{
    return false;
}

bool ASBCharacter::IsActiveFootIK()
{
    return false;
}

bool ASBCharacter::IsActiveFeetIK()
{
    return false;
}

bool ASBCharacter::IsActiveCustomMovingStanceData()
{
    return false;
}

bool ASBCharacter::IsActiveBoneBlend()
{
    return false;
}

bool ASBCharacter::IsAccelSwimUp()
{
    return false;
}

bool ASBCharacter::IsAccelSwimDown()
{
    return false;
}

float ASBCharacter::GetWallSlideSideValue()
{
    return 0.0f;
}

FVector ASBCharacter::GetWallRunNormal()
{
    return FVector{};
}

FVector ASBCharacter::GetWallRunDir()
{
    return FVector{};
}

FVector ASBCharacter::GetTPSLookAtWorldLocation(bool inReCheckHitLocation)
{
    return FVector{};
}

FVector ASBCharacter::GetTPSLookAtLocalSpaceDirection()
{
    return FVector{};
}

FVector2D ASBCharacter::GetTPSLookAtBlendSpaceXY()
{
    return FVector2D{};
}

float ASBCharacter::GetSprintSpeedScale()
{
    return 0.0f;
}

bool ASBCharacter::GetSequencerAnimMode()
{
    return false;
}

float ASBCharacter::GetSelfieAnimBSValue()
{
    return 0.0f;
}

float ASBCharacter::GetSBSpeedForAnimGraph()
{
    return 0.0f;
}

USBSkeletalMeshComponent* ASBCharacter::GetSBSkeletalMeshComponent(TEnumAsByte<ESBSkelMeshSlot> Slot)
{
    return NULL;
}

FVector ASBCharacter::GetSBCharacterRightVector()
{
    return FVector{};
}

float ASBCharacter::GetRunInputDuration()
{
    return 0.0f;
}

float ASBCharacter::GetPoseSnapBlendWeight()
{
    return 0.0f;
}

FName ASBCharacter::GetPoseName_PhotoMode() const
{
    return NAME_None;
}

FName ASBCharacter::GetPonytailMeshName()
{
    return NAME_None;
}

UAnimSequence* ASBCharacter::GetPhotoModeFacialAnimation()
{
    return NULL;
}

TEnumAsByte<EPhysicalSurface> ASBCharacter::GetOverrideFootStepPhySurface(TEnumAsByte<EPhysicalSurface> inDefaultSurfacee)
{
    return SurfaceType_Default;
}

float ASBCharacter::GetMoveInputDirectionAngle()
{
    return 0.0f;
}

ASBCharacter* ASBCharacter::GetLookAtTargetCharacter()
{
    return NULL;
}

ASBCharacter* ASBCharacter::GetLockOnTargetCharacter()
{
    return NULL;
}

float ASBCharacter::GetKneeIKSearchDistanceForwardR()
{
    return 0.0f;
}

float ASBCharacter::GetKneeIKSearchDistanceForwardL()
{
    return 0.0f;
}

float ASBCharacter::GetKneeIKSearchDistanceBackwardR()
{
    return 0.0f;
}

float ASBCharacter::GetKneeIKSearchDistanceBackwardL()
{
    return 0.0f;
}

float ASBCharacter::GetKneeIKOffset_RToe()
{
    return 0.0f;
}

float ASBCharacter::GetKneeIKOffset_RKnee()
{
    return 0.0f;
}

float ASBCharacter::GetKneeIKOffset_LToe()
{
    return 0.0f;
}

float ASBCharacter::GetKneeIKOffset_LKnee()
{
    return 0.0f;
}

float ASBCharacter::GetIdleAdditiveAnimAlpha()
{
    return 0.0f;
}

float ASBCharacter::GetGrabIKAlpha()
{
    return 0.0f;
}

FVector ASBCharacter::GetGlobalMaterialVectorParameterValue(FName InParameterName)
{
    return FVector{};
}

float ASBCharacter::GetGlobalMaterialScalarParameterValue(FName InParameterName)
{
    return 0.0f;
}

float ASBCharacter::GetGamePadRTriggerAxisValue()
{
    return 0.0f;
}

float ASBCharacter::GetGamePadLTriggerAxisValue()
{
    return 0.0f;
}

float ASBCharacter::GetFullBodyIkActiveHitPointAngle()
{
    return 0.0f;
}

FVector ASBCharacter::GetFowardVector(bool bActorFoward)
{
    return FVector{};
}

float ASBCharacter::GetFootIKAlphaValue()
{
    return 0.0f;
}

float ASBCharacter::GetFishingRodDirection()
{
    return 0.0f;
}

float ASBCharacter::GetFishingLookAtBlendSpaceX()
{
    return 0.0f;
}

float ASBCharacter::GetFeetIKTraceScale()
{
    return 0.0f;
}

float ASBCharacter::GetFeetIKAlphaValue()
{
    return 0.0f;
}

int32 ASBCharacter::GetFacialIdleAnimType()
{
    return 0;
}

int32 ASBCharacter::GetFacialAnimType_PhotoMode() const
{
    return 0;
}

float ASBCharacter::GetFacialAnimPosition_PhotoMode() const
{
    return 0.0f;
}

bool ASBCharacter::GetEyeTrackingToCam()
{
    return false;
}

FVector2D ASBCharacter::GetEyePosition2D()
{
    return FVector2D{};
}

int32 ASBCharacter::GetEventMoveSideValue()
{
    return 0;
}

float ASBCharacter::GetEventMoveIKActivateTime()
{
    return 0.0f;
}

bool ASBCharacter::GetDollyCamMode(bool bFlag)
{
    return false;
}

float ASBCharacter::GetCustomPoseSnapBlendWeight()
{
    return 0.0f;
}

float ASBCharacter::GetCustomFloat(FName inCustom)
{
    return 0.0f;
}

bool ASBCharacter::GetCustomBool(FName inCustom)
{
    return false;
}

FVector ASBCharacter::GetCustomBlendSpaceInput()
{
    return FVector{};
}

FName ASBCharacter::GetCurrentStanceName()
{
    return NAME_None;
}

float ASBCharacter::GetCurrentSideRodSearchDegreeValue()
{
    return 0.0f;
}

float ASBCharacter::GetCurrentRotaionPower()
{
    return 0.0f;
}

float ASBCharacter::GetCurrentCustomAnimByMeshSlotAlpha(TEnumAsByte<ESBSkelMeshSlot> InMeshSlotType)
{
    return 0.0f;
}

float ASBCharacter::GetCurrentCustomAnimAlpha_Upper(int32 inCustomAnimIndex)
{
    return 0.0f;
}

float ASBCharacter::GetCurrentCustomAnimAlpha_Lower(int32 inCustomAnimIndex)
{
    return 0.0f;
}

float ASBCharacter::GetCurrentCustomAnimAlpha(int32 inCustomAnimIndex)
{
    return 0.0f;
}

float ASBCharacter::GetCurrentCustomAnimAddtiveAlpha_Upper()
{
    return 0.0f;
}

float ASBCharacter::GetCurrentCustomAnimAddtiveAlpha()
{
    return 0.0f;
}

float ASBCharacter::GetCurrentCameraLagSpeed()
{
    return 0.0f;
}

FName ASBCharacter::GetCurrentBulletItemAlias()
{
    return NAME_None;
}

float ASBCharacter::GetCamOverrideFovMode()
{
    return 0.0f;
}

float ASBCharacter::GetCameraZoom()
{
    return 0.0f;
}

FName ASBCharacter::GetBodyMeshName()
{
    return NAME_None;
}

bool ASBCharacter::GetBlackboardValue(FName InName, int32& outIntValue, float& outFloatValue, FVector& outVectorValue)
{
    return false;
}

bool ASBCharacter::GetArriveMetaAIBehaviorNode()
{
    return false;
}

float ASBCharacter::GetAnimControllerSpringWeight()
{
    return 0.0f;
}

float ASBCharacter::GetAnimControllerFullbodyIKFactor()
{
    return 0.0f;
}

FVector ASBCharacter::GetActorBottomLocation()
{
    return FVector{};
}

void ASBCharacter::ForceAllClothNextUpdateTeleportAndReset()
{
}

void ASBCharacter::ExitVehicle()
{
}

void ASBCharacter::EnterVehicle(AActor* Vehicle, bool inBlockSimulatePhysicsFromTransform, bool inControlRotation, bool bInDisableFootIKWhenRideOnVehicle)
{
}

void ASBCharacter::EndFlyingAction()
{
}

void ASBCharacter::DeactiveCustomMovingStanceData()
{
}

void ASBCharacter::ClearNeedPlayTurnAnimFlag()
{
}

bool ASBCharacter::CheckMoveRightSmoothValue(float inUnderValue, bool inIgnoreGamePad)
{
    return false;
}

void ASBCharacter::ChangeAttachTarget(TEnumAsByte<ESBSkelMeshSlot> OwnerSlot, TEnumAsByte<ESBSkelMeshSlot> TargetSlot, FName AttachSocketName, float InBlendTime, float InPriority)
{
}

void ASBCharacter::CancelClimbing()
{
}

void ASBCharacter::CalcHitEventDirection(FVector ForceOrigin, FVector ForceVelocity)
{
}

float ASBCharacter::CalcAnimSpeedByWalkSpeed()
{
    return 0.0f;
}

float ASBCharacter::CalcAnimSpeedByRunSpeed()
{
    return 0.0f;
}

float ASBCharacter::CalcAnimSpeedByClimbSpeed()
{
    return 0.0f;
}

void ASBCharacter::ApplyKeepAllBodiesPhysicsTransform()
{
}

void ASBCharacter::AddCameraZoom(float Value)
{
}

void ASBCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}
