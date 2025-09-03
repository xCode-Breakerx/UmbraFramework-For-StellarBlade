#pragma once
#include "CoreMinimal.h"
// CROSS-MODULE INCLUDE V2: -ModuleName=AIModule -ObjectName=AIRequestID -FallbackName=AIRequestID
// CROSS-MODULE INCLUDE V2: -ModuleName=AIModule -ObjectName=CrowdAgentInterface -FallbackName=CrowdAgentInterface
// CROSS-MODULE INCLUDE V2: -ModuleName=AIModule -ObjectName=EPathFollowingResult -FallbackName=EPathFollowingResult
// CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Color -FallbackName=Color
// CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=EAxis -FallbackName=EAxis
// CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Guid -FallbackName=Guid
// CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Quat -FallbackName=Quat
// CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Rotator -FallbackName=Rotator
// CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=SoftObjectPath -FallbackName=SoftObjectPath
// CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Transform -FallbackName=Transform
// CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector -FallbackName=Vector
// CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Vector2D -FallbackName=Vector2D
// CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Character -FallbackName=Character
// CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ECollisionChannel -FallbackName=ECollisionChannel
// CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=EMovementMode -FallbackName=EMovementMode
// CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=HitResult -FallbackName=HitResult
// CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=MatineeAnimInterface -FallbackName=MatineeAnimInterface
// CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Vector_NetQuantize10 -FallbackName=Vector_NetQuantize10
// CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=Vector_NetQuantize100 -FallbackName=Vector_NetQuantize100
// CROSS-MODULE INCLUDE V2: -ModuleName=PhysicsCore -ObjectName=EPhysicalSurface -FallbackName=EPhysicalSurface
// CROSS-MODULE INCLUDE V2: -ModuleName=SBAnimation -ObjectName=ESBCharacterTransitAnim -FallbackName=ESBCharacterTransitAnim
// CROSS-MODULE INCLUDE V2: -ModuleName=SBAnimation -ObjectName=ESBLookAtIKType -FallbackName=ESBLookAtIKType

#include "Camera/CameraComponent.h"
#include "Components/SplineComponent.h"
#include "Components/SpotLightComponent.h"
#include "ESBSkelMeshSlot.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "NiagaraParameterCollection.h"
#include "Particles/ParticleSystemComponent.h"
#include "SBSkeletalMeshComponent.h"
#include "SBCharacter.generated.h"

UCLASS(Blueprintable, Config = Engine)

class SB_API ASBCharacter : public ACharacter
{
    GENERATED_BODY()

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float BaseTurnRate;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float BaseLookUpRate;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float CurrentLockOnDistance;

private:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    UCameraComponent* FollowCamera;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    USpringArmComponent* CameraBoom;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    USplineComponent* CameraDollySpline;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bUseInteractionCamClamp;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bEyeTrackingToCam;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RemainEyeTrackingToCam;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RemainNextCheckEyeTrackingToCam;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RemainNextCheckPlayIdleEventAnim;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bDisableIdleEventAnim;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float MouseWheelLockOnBlockDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FRotator EyeTrackingToCamRot_R;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FRotator EyeTrackingToCamRot_L;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FRotator EyeTrackingToCamRot_Neck;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float EyeTrackingAlpha;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    int32 EyeTrackingTestCounter;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bInitAnimSetSyncData;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    TArray<FName> CuttingBones;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    TArray<FColor> CuttingVertiesColor;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    int32 CuttingMeshLOD;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FName CuttingMeshBreakBoneName;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector CuttingMeshBreakLocation;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float CuttingMeshImpulsePower;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bIsCuttedMesh;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bUseControlCollisionAtSwim;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bActiveFlyingSpline;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bActiveSwimSpline;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bActiveUnderWaterSwimSpline;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bActiveSlopeMovingSpline;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bActiveSlopeMovingSpline2;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bActiveSideRodSpline;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bActiveRodSpline;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bActiveSideToSideSpline;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bActiveBalanceBeamSpline;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bActiveSlidingSlipSpline;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bActiveHoldBalanceBeamSpline;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bActiveWallRunSpline;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float OverrideLockOnMaxDistance;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float OverrideLockOnReleaseDistance;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float OverrideLockOnArmLength;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float OverrideLockOnPitchAdd;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FName LockOnTargetBoneSocketName;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FName LockOnUIDisplayBoneSocketName;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bOverrideLockOnPitchMin;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float OverrideLockOnPitchMinValue;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bOverrideLockOnPitchMax;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float OverrideLockOnPitchMaxValue;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bOverrideLockOnCamBoomHeight;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float OverrideLockOnCamBoomHeight;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bOverrideLockOnCamBoomLeftRight;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float OverrideLockOnCamBoomLeftRight;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FName GaugeDisplayBoneSocketName;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FName CustomLockOnTargetBoneSocketName;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float LockOnPitchMaxAtCustomTargetBoneSocket;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bShortPonyTail;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bApplyShortPonyTailPhysics;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector LockOnJumpToMoveDir;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RemainCustomLockOnTargetDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float CustomLockOnTargetDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float CustomLockOnTargetBlendInDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float CustomLockOnTargetBlendOutDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FName BlendSrcCustomLockOnTargetBoneName;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RemainRunningLockOnRotation;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FName LockOnPitchOffsetBaseBoneSocketName;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UCurveFloat* LockOnPointCurveByDistance;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UCurveFloat* LockOnPointCurveByDir;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UCurveFloat* LockOnPointWeightCurveByDir;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UCurveFloat* AimLockOnPointCurveByDistance;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UCurveFloat* AimLockOnPointCurveByDir;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UCurveFloat* AimLockOnPointWeightCurveByDir;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta = (AllowPrivateAccess = true))
    UCapsuleComponent* OverlapBodyCollision;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta = (AllowPrivateAccess = true))
    UCapsuleComponent* PhysicsCapsuleCollision;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bLockOnRunRotationEnable;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float LockOnRunRotationDegree;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float LockOnRunRotationDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float LockOnRunRotToCharDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bLockOnRunRotationLowerAnim;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector EventDirection;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bFreeCamMode;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bIgnoreSetMeshInfoCorrectionCapsuleZ;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bUseSetMeshInfoCapsuleHeight;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    USplineComponent* CameraDollySplineFlying;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    USplineComponent* CameraDollySplineSwim;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    USplineComponent* CameraDollySplineUnderWaterSwim;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    USplineComponent* CameraDollySplineSlopeMoving;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    USplineComponent* CameraDollySplineSlopeMoving2;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    USplineComponent* CameraDollySplineSideRod;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    USplineComponent* CameraDollySplineRod;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    USplineComponent* CameraDollySplineSideToSide;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    USplineComponent* CameraDollySplineBalanceBeam;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    USplineComponent* CameraDollySplineSlidingSlip;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    USplineComponent* CameraDollySplineHoldBalanceBeam;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta = (AllowPrivateAccess = true))
    USplineComponent* CameraDollySplineWallRun;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bSetExtraSpline;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bSequencerPlacement;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool UseConstructMeshSetting;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bPhotoModeCloseRange;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float SelfieAnimBSValue;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TArray<FSoftObjectPath> NPCSelfieIdlePoseArray;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float NPCSelfieIdlePoseCheckTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TMap<FName, float> PerPoseCloseRangeUpVectorOffset;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TMap<FName, float> PerPoseCloseRangeYawRangeOffset;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RemainMoveInputBlockDuraion;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector CurrentSwimForce;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float CurrentMovingForceDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    int32 MoveInputBlockCount;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float LastMoveRightInput;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float LastMoveSmoothRightInput;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float LastNonZeroMoveRightInput;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float LastMoveFowardInput;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float BlockWallMoveFowardInput;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float BlockWallMoveRightInput;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float PreLastMoveFowardInput;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    int32 DisableLockOnCharacterRotaion;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    int32 DisableLookAtIK;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    int32 DisableHoldBalanceBeamAction;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bSoftDisableLockOnCharacterRotation;

    UPROPERTY(EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    uint64 LastFrameCountFalseSoftDisableLockOnCharacterRotation;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RemainClimbDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bRequestFallStartTransit;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    int32 RequestCancelWallRunFlag;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float PhysWalkingMovingTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bDisableMovingTransit;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bDisableLandingTransit;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bDisableLockonTarget;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bDisableLockOnControl;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float WalkInputDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RunInputDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float PhysWalkInputDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    TArray<FName> OverrideEffectAlias;

    UPROPERTY(EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    TArray<uint32> OverrideEffectID;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float GamePadLTriggerAxisValue;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float GamePadRTriggerAxisValue;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    int32 BlockingModeCount;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RemainJumpToSprintHoldDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RemainHoldLastMoveInputDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RemainBlockJumpDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bEnableJumpToSprintHoldJump;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RemainSlopeDashDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bRunningSlopeAutoMove;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RemainBlockSlopeDashDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RemainBlockStartEventMove;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float SlopeDashInputValue;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    int32 BlockPlayTransitAnimCount;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float DefaultCameraArmLength;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float RotationYawRate;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float RotationYawRateScale;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UCurveFloat* RotationYawRateCurveByWalkSpeed;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UCurveFloat* RotationYawScaleCurveByMoveInputDegree;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UCurveFloat* CameraFovCurveByDistance;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool UsePathWayFloorCheck;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float MoveSmoothRightInputLerpValue;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float FallingRotationYawRate;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float RepeatBlockTurnTime;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float RunTurnDuration;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float WalkTurnDuration;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float IdleTurnDuration;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float SprintTurnDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RemainTurnDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RemainHoldWalkingDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RemainHoldLockOnAtChatDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RemainBlockStartSprint;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RemainBlockStartHoldSwim;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RemainActiveRunStartAfterEvade;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RemainUpdateProceduralDelay;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RemainTurnDeltaRotDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float TurnDeltaRotPower;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float WaitTimeSwimToGroundValue;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bEnableChangeInteraction;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bRequestEnableChangeInteraction;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bEnableMeshCollision;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bDisableMeshCollisionByDistanceToPlayer;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bEnablePhysicsCapsuleCollision;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RemainInteractionActionDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float CurrentInteractionActionDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bInCliffArea;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bCliffActionInArea;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float CliffActionCancelBlockDurationValue;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bInWallArea;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bBlockWallActionInArea;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bInExclusiveWaterVolume;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bInteractionMoveToTargetLoc;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RemainBlockChangeInteraction;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RemainBlockStartSideRod;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RemainBlockStartSlopeMove;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RemainBlockSlopeJumpEnd;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bForceBlockStartSlopeMove;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bCliffAction;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float CurrentCliffActionTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bBlockWallFrontAction;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RemainBlockWallNextAction;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bHuddleUpAction;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bHuddleUpActionOnGround;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bCancelHuddleUpByJump;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector HuddleUpActionTargetLocation;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector HuddleUpActionMidTargetLocation;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool HuddleUpActionToLow;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    int32 HuddleUpActionIndex;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bEnableHuddleUpByJump;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float HuddleUpActionStartSpeed;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float HuddleUpGroundCancelBlockDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float CurrentRopeSwingJumpInputBlockDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector RopeSwingJumpVelocity;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bIdleTurning;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float SpeedForAnimGraph;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float CurrentSpeedForAnimGraph;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bUseOverrideSpeedForAnimGraph;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float OverrideSpeedForAnimGraph;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float LastGetCurrentSpeedForAnimGraph;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float ReturnLastSpeedForAnimGraphTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta = (AllowPrivateAccess = true))
    float AnimControllerSpringWeight;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta = (AllowPrivateAccess = true))
    float AnimControllerFootIKFactor;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta = (AllowPrivateAccess = true))
    float AnimControllerFullBodyIKFactor;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta = (AllowPrivateAccess = true))
    bool bHideWhenSequenceCameraNear;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bSlidePhysWalk;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float SlideSideValue;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RemainBeginSlideSideDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RemainCustomSlideSideValueBlendTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float CurrentWallSlideSideValue;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    int32 AttachedToLevelSequenceRefCount;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    int32 LookAtTargetLevelSequenceRefCount;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bSequencerAnimMode;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    int32 PlayableWhenLevelSequenceRefCount;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bStartMovementNoneWhenLevelSequence;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    int32 DisableRootClothCollision;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bCustomOverrideClothPhysicsAsset;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FString CustomOverrideClothPhysicsMeshPath;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float AverageMoveInputSize;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector AverageMoveInput;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    int32 AverageMoveInputCount;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bRunningSkill;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bRunningSkillForceCancelWhenAttachedToLevelSequence;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bAttackParried;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector FlyingActionLastAccel;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector WireFlyTargetPosition;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector WireSetPosition;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float WireFlyingSpeed;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float WireFlyingAccelSpeed;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float WireFlyingMinSpeed;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float WireFlyingMaxSpeed;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float WireMovingSpeed;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float WireMovingAccelSpeed;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float WireMovingMinSpeed;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float WireMovingMaxSpeed;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float WireMoveReachDistance;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float WireRechargingSec;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float CurrentWireRechargingSec;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float CurrentWireFlyingSpeed;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float CurrentWireMovingSpeed;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector CurrentWireMovingVelocity;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector CurrentWireFlyingPosition;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector CurrentUpVector;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float CurrentRotationPower;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float RotationPowerSensetive;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FRotator CameraVolumeActorOriginRot;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector CameraVolumeActorOriginLoc;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector CameraVolumeBasedScreenPosPivot;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector2D CameraVolumeBasedLastScreenPos;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float CameraVolumeActorOriginFov;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bSetCustomMovingStanceData;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool CurrentCameraVolumeLookAtMode;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float CustomLookAtMaxSpeedScale;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool CustomLookAtForceWalkMode;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool CustomLookAtDisableSprint;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool CustomLookAtDisableJump;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool CustomLookAtBlockSkill;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool CustomLookAtActive;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float CustomCameraLockOnSecondBlendScale;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float CustomCameraLockOnSecondBlendDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float CustomCameraLockOnSecondBlendOutDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float ControllerValueHistoryDuration;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    int32 MaxControllerValueHistoryNum;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    int32 CurrentAddYawControllerValueNum;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    int32 CurrentAddPitchControllerValueNum;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float CustomLookAtControlCameraScale;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bCustomLookAtControlCam;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float CustomLookAtControlCamDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float LookAtCustomTargetBlendScale;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float LookAtCustomTargetDetachDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float LookAtCustomTargetBlendDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RemainLookAtCustomTargetDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    AActor* LookAtCustomTargetActor;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float LookAtCustomTargetDistance;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector LookAtCustomTargetOffset;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector LookAtCustomTargetBackupCameraInfo;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector LookAtCustomTargetStartDirection;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector2D LookAtCustomTargetStartInputValue;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float LookAtCustomTargetStartDirectionCancelSize;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bUseCancelByUserCamControl;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float CancelByUserCamControlTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bSideRodJumpEnableEventMovVolumeToBack;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector SideRodJumpEnableEventMovVolumeClosetLoc;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float CurrentSideRodSearchDegreeValue;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bCurrentStretchSideRodSearch;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bEnableSideRodHuddleUp;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    TWeakObjectPtr<AActor> DisableWallRunActor;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RemainDisableWallRunActorDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RemainPendingJumpDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bPendingRunJump;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float BackupCollisionRadiusForSlopeMove;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float BackupCollisionHalfHeightForSlopeMove;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float BackupRelativeZForSlopeMove;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector TargetUpVector;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bSprint;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bToggledSprint;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bEnableExtraSprint;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float DisableExtraSprintDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float SprintDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bChangeSprintFlag;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bSprintJump;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bWallRunJump;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float OverrideWallRunJumpScale;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bGlide;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bFlyingAction;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bForceCancelFlyingAction;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bFlyingActionMoving;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RemainFlyingActionTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float CurrentFlyingActionTime;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float FlyingActionPrepareDuration;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float FlyingActionLandedMoveBlockSec;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float FlyingActionMaxTime;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float FlyingActionAddTimePerSec;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float FlyingActionCoolTime;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float FlyingActionEnableRemainTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bWallHitAction;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float WallHitRemainTimeValue;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float WallHitBounceVelocity;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float WallHitBounceDelay;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bDrawMoveTracker;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float TargetCameraBoomLength;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float RelativeCameraBoomHeight;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float RelativeCameraBoomLeftRight;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float TargetRelativeCameraBoomHeight;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float TargetRelativeCameraBoomLeftRight;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RemainRequestFlyingActionEvade;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector RequestFlyingActionEvadeAcceleration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector BackupFlyingActionVelocity;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bDisableNormalMoveTransit;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bChangedJump;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float LockOnRotationYawUnit;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float BlockLockOnMoveTargetDuration;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float LockOnMoveTargetMouseMoveSize;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float LockOnMoveTargetPadRateSize;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float LockOnBlendCamHistoryDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bLockOnPitchControlling;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector LockOnStart2DDirection;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bLockOnCheckVisible;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float HideTimeForLockOnCharacter;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, Transient, meta = (AllowPrivateAccess = true))
    int32 FacialAnimTypeIndex;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, Transient, meta = (AllowPrivateAccess = true))
    int32 FacialAnimTypeIndex_PhotoMode;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, Transient, meta = (AllowPrivateAccess = true))
    float FacialAnimPosition_PhotoMode;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, Transient, meta = (AllowPrivateAccess = true))
    bool bHideMaterialParts;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bPrevHideMaterialParts;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FName PoseName_PhotoMode;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bPhotoModeDefaultSnapshot;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bPhotoModeDefaultWeaponSnapshot;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bChangedPose_PhotoMode;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, Transient, meta = (AllowPrivateAccess = true))
    bool bDisableIdleAdditiveAnimWhenAttachedToLevelSeq;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bDefaultDisableIdleAdditiveAnimWhenAttachedToLevelSeq;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bDisableIdleAdditiveAnimFromStance;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float BackupTargetRelativeCameraBoomHeight;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float BackupTargetRelativeCameraBoomLeftRight;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float BackupTargetCamArmLength;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FRotator LockOnPitchControllingRot;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bLockOnAlwaysPitchControl;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bLockOnCameraEnable;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float RunToIdleLFootFrontMoveTime;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float RunToIdleLFootFrontVelocity;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float RunToIdleRFootFrontMoveTime;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float RunToIdleRFootFrontVelocity;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float WalkToIdleLFootFrontMoveTime;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float WalkToIdleLFootFrontVelocity;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float WalkToIdleRFootFrontMoveTime;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float WalkToIdleRFootFrontVelocity;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float ShortMoveToIdleLFootFrontMoveTime;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float ShortMoveToIdleLFootFrontVelocity;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float ShortMoveToIdleRFootFrontMoveTime;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float ShortMoveToIdleRFootFrontVelocity;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float MoveDurationCheckShortMove;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float SprintToIdleMoveTime;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float SprintToIdleVelocity;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float LockOnSprintToIdleMoveTime;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float LockOnSprintToIdleVelocity;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float LockOnRunWalkToIdleMoveTime;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float LockOnRunWalkToIdleVelocity;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float OverrideRunToIdleLFootFrontMoveTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float OverrideRunToIdleLFootFrontVelocity;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float OverrideRunToIdleRFootFrontMoveTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float OverrideRunToIdleRFootFrontVelocity;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float OverrideWalkToIdleLFootFrontMoveTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float OverrideWalkToIdleLFootFrontVelocity;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float OverrideWalkToIdleRFootFrontMoveTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float OverrideWalkToIdleRFootFrontVelocity;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float OverrideShortMoveToIdleLFootFrontMoveTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float OverrideShortMoveToIdleLFootFrontVelocity;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float OverrideShortMoveToIdleRFootFrontMoveTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float OverrideShortMoveToIdleRFootFrontVelocity;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    TArray<float> TransitAnimPriority;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bDisableTransitAnimByStanceVolume;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float LockOnRunAnimRefSpeed;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float LockOnWalkAnimRefSpeed;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float RunAnimRefSpeed;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float WalkAnimRefSpeed;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float ClimbingAnimRefSpeed;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float LockOnCameraApplyVelocityRatio;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float SprintHoldKeyDurationOnMove;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float SprintHoldKeyDurationOnLockOnMove;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RemainSprintKeyHoldDuration;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float GlideHoldKeyDurationOnJump;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RemainGlideKeyHoldDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bWalkingMode;

    UPROPERTY(EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    uint32 ActiveWalkingModeTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bActiveMetaAI;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bArriveMetaAIBehaviorNode;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bDisableInteractionFromMetaAI;

    UPROPERTY(EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    uint64 MetaAIPenetratingMoveFrame;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bMetaAITiredState;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bUseCrowdVelocityLerpPower;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bJoggingRun;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bForceJoggingRun;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bWalkingWhenMoving;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bForceWalkWhenMoving;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bLockOn;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bLockOnAtChat;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FGuid LockOnAtChatGuid;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FGuid LockOnAtChatBlendSpaceID;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector LockOnAtChatPivotLocation;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector LockOnAtChatPivotDirection;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float LockOnAtChatPivotMoveDegRange;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float LockOnAtChatMoveRange;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bUnlockAtChatInOutRange;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float JumpStartZ;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float JumpingTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float FallingTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bSlopeJumping;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    int32 SlopeDollyIndex;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bSlopeJumpOut;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RequestSlopeOutMaxSpeed;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bSlopeJumpingCustomLanding;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float SlopeJumpingCustomLandingDeg;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector SplineForceAtSlopeJump;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bSwimJumping;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector SlopeVelocityBeforeJump;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bSlideSlipJumping;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bSlideSlipFalling;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bSideRodFalling;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bRodJumping;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bSideRodJumping;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bDisableSlopeStartMovingDeadZone;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector vecJumpMoveInput;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bAccelSwimUp;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bAccelSwimDown;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bInputSwimming;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector InputSwimmingAccel;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RemainFlyingActionCoolTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    ASBCharacter* LockOnCharacter;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RemainCustomLockOnCameraBlendTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float CustomLockOnCameraBlendTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float CustomLockOnCameraBlendMultifly;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    TArray<ASBCharacter*> LookAtCandidates;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    ASBCharacter* CameraLookAtTarget;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float CameraLookAtTargetTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    AActor* AnimLookAtTarget;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FName AnimLookAtTargetSocket;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float AnimLookAtTargetZOffset;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector HeadLookAtLocation;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta = (AllowPrivateAccess = true))
    FVector HeadLookAtPosition;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta = (AllowPrivateAccess = true))
    bool bUseHeadLookAtTargetPositionValue;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta = (AllowPrivateAccess = true))
    float HeadLookAtOverrideAlpha;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta = (AllowPrivateAccess = true))
    float BodyLookAtOverrideAlpha;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta = (AllowPrivateAccess = true))
    float Special1LookAtOverrideAlpha;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta = (AllowPrivateAccess = true))
    float Special2LookAtOverrideAlpha;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    AActor* EyeTrackingTarget;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FName EyeTrackingTargetSocket;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta = (AllowPrivateAccess = true))
    FVector2D EyePosition2D;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bEnableEyePositionUpdate;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bFixedBodyLookAtLocation;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector LastBodyLookAtRelativeLocation;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta = (AllowPrivateAccess = true))
    uint8 bSeqDisableDesireRotation : 1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bSeqFinishOnceForceMovement;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bSeqFinishOnceStopActiveMovement;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    TEnumAsByte<EMovementMode> SeqFinishOnceMovement;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bSeqFinishOnceSetPlayerCam;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bSeqFinishOnceSetPlayerCamReset;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bSeqFinishOnceSetPlayerCamResetPitchBaseAlpha;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bSeqFinishOnceSetPlayerCamResetYawReset;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bSeqFinishOnceSetPlayerCamResetForceSetBoom;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    TArray<FName> ActorActiveVolumeNameArray;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bActiveCharacter;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bDisableTickByLastRenderTimeOnScreen;

    UPROPERTY(EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    uint64 LastCheckOcclusionFrameCount;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector OverlapMoveVelocity;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector CurrentOverlapMoveVelocity;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float OverlapMoveVelocityDelayTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bTPSMode;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float LastTPSModeTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bIsActiveTPSAimOffset;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector TPSLookAtDirection;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector TPSInitLookAtDirection;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector TPSDesiredLookAtDirection;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector TPSDesiredDampingVelocity;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float TPSDampingWaitTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float TPSAimSlowDownValue;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bDisableTPSAimSlowDownValue;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    TWeakObjectPtr<ASBCharacter> TPSCollisionHitCharacter;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector TPSCollisionHitLocation;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bTPSFirstTurningTPSLookAt;

    UPROPERTY(EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    uint64 TPSLookAtPinLocationUpdateFrameCount;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector TPSLookAtPinLocation;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector2D NikkeTPSPinScreenPoint;

    UPROPERTY(EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    uint64 TPSLookAtWorldLocationUpdateFrameCount;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector TPSLookAtWorldLocation;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float TPSSwitchableTimeFromCameraVolume;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector TPSDesiredLookAtFixedLocation;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float TPSDesiredLookAtFixedLocationTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float TPSDesiredLookAtFixedLocationCurrentTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bTPSZoomIn;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float TPSCameraSwitchBlendTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FVector TPSAimSlowdownBoundingBoxExtentXYRate;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float BulletMagnetCapsuleRadiusScale;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float BulletMagnetCapsuleHeightScale;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    UNiagaraParameterCollection* NikkeMinigameNiagaraParameterCollection;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta = (AllowPrivateAccess = true))
    bool bIgnoreTPSBodyRotationWhenSequence;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta = (AllowPrivateAccess = true))
    bool bCameraVolumeOnceEnterImmidiate;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float GameOptionControllerCameraNormalHorizentalScale;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float GameOptionControllerCameraNormalVerticalScale;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float GameOptionControllerCameraTPSHorizentalScale;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float GameOptionControllerCameraTPSVerticalScale;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool GameOptionControllerCameraHorizentalInvert;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool GameOptionControllerCameraVerticalInvert;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float GameOptionMouseCameraNormalHorizentalScale;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float GameOptionMouseCameraNormalVerticalScale;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float GameOptionMouseCameraTPSHorizentalScale;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float GameOptionMouseCameraTPSVerticalScale;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool GameOptionMouseCameraHorizentalInvert;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool GameOptionMouseCameraVerticalInvert;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float StartTurningBlockTime;

protected:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector FishingLookAtDirection;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector FishingCastingEnableLocation;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UCurveFloat* FishingCastingDistanceCurve;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RemainFishingReelTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bFishingReel;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bNeedFishingForceTurn;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bEnableSimpleFishing;

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FName LastGunRotationSeqName;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector LastGunRotationDirection;

    UPROPERTY(EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    int32 DisableLookAtCount[4];

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    int32 DisableTPSAimIKCount;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FName DefaultHeadLookAtTargetSocket;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FName DefaultBodyLookAtTargetSocket;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FVector EyeOffsetFromHead;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TEnumAsByte<EAxis::Type> EyeForwardAxis;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool EyeForwardAxisInverse;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TEnumAsByte<EAxis::Type> EyeRightAxis;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool EyeRightAxisInverse;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float EyeBetweenDistance;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float EyeAngleHorizontal;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float EyeAngleVertical;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bActiveWeakPointCollision;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bNotTPSAutoTargeted;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bNotTPSMagnet;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector OldWireFlyingPosition;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool EnableMovementChecker;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta = (AllowPrivateAccess = true))
    USceneComponent* ClimbAttachedComponent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector ClimbAttachedLocalVector;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FName ClimbAttachedSocketName;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FString ResourcePath;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bMovingTarget;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bMovingTargetChangeState;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bLocalMovingTarget;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bIgnoreMoveingTargetUpdateTransfrom;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    TArray<FVector> MovingTargetPath;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bIgnoreMovingTargetPathLeave;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta = (AllowPrivateAccess = true))
    TWeakObjectPtr<USceneComponent> MovingTargetBaseComponent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector vecMovingTargetLocationForBaseComp;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector vecMovingTargetDirectionForBaseComp;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bMovingTargetLinearInterpol;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float MovingTargetDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float MovingTargetDelayDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float MovingTargetRotDelayDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool MovingTargetAnimStopAtMoveInput;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bEventMoveDnamicTarget;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float CurrentMovingTargetTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float CurrentRotTargetTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector MovingTargetStartDirection;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector MovingTargetEndDirection;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float MovingTargetDirectionCustomDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bRotationLinearInterp;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    int32 MovingTargetRotationDirType;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bMovingTargetEndPlayAnim;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bDisableActorCollisionToMovingTarget;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FString MovingTargetEndAnimName;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float MovingTargetEndAnimBlendInTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float MovingTargetEndAnimBlendOutTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float MovingTargetEndAnimTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float MovingTargetEndAnimBlockInputDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float MovingTargetAfterBlockInputDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float MovingTargetCameraInterpolTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FString MovingTargetCustomAnimPath;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float MovingTargetCustomAnimBlendTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float MovingTargetCustomAnimDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bSetMovingTargetCustomAnimTransitID;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bMoveingTargetRefreshMovemodeAtEndMove;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bChangeMovingState;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bLastMoveingState;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float MoveAnimSpeedInterpolAfterAction;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RemainMoveAnimSpeedInterpolAfterAction;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RemainChangeIdleMoveTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float ChangeIdleMoveVelocity;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RemainTurnMoveTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float SlopeLandingMoveTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RemainSlopeLandingMoveTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RemainBlockTurnTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RemainBlockHuddleUpTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float TurnMoveVelocity;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RemainMotionMoveDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bEnableMotionMove;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bUseMotionMoveOnlyVelocityChange;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float MotionMoveDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bWallRun;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float CurrentWallRunTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bUseWallRunYawControl;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float SprintTurnMoveVelocity;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float SprintTurnMoveTime;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float RunTurnMoveVelocity;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float RunTurnMoveTime;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float WalkTurnMoveVelocity;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float WalkTurnMoveTime;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float IdleTurnMoveVelocity;

    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta = (AllowPrivateAccess = true))
    float IdleTurnMoveTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bLockOnMoveSideNormal;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bEnableDoubleJump;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector PendingMoveLockOnTargetVector;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float CurrentLockOnCameraInputX;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float CurrentLockOnCameraInputY;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float CurrentLockOnCameraInputMouseX;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float CurrentLockOnCameraInputMouseY;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RemainBlockLockOnMoveTargetDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bVisibleSwordTrail;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float GravityZScaleWhenActiveSkill;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    int32 UnavailableLockOn;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    TMap<FName, bool> TouchTriggerMap;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    int32 LockOnSprintStartPlayIndex;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FRotator TargetCamRotator;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bBlockChangeMesh;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FTransform MeshOriginRelativeTransform;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float CustomPoseSnapBlendWeight;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bIgnoreCharacterCollision;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bDisableLocationFromOverlapCollision;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bNoSweepOverlapCollisionWhenZeroVelocity;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float RuleMoveAdditiveZFromProjectPointToNavigation;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float AcceptanceRadius;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bUseFlyPathWayForAnimGraphSpeed;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    int32 MoveBackByTargetOverlap;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    int32 MoveBackByTargetOverlapNextFrameMinusValue;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    int32 JumpLock;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bBlockJumpAction;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    int32 BlockJumpActionFrameCount;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    int32 SprintLock;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    int32 MouseLock;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    int32 DisableCollisionOverlapMoving;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bFallingToLowDiff;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bFallingToLowDiffPlayAnim;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    int32 OverrideBlendSpaceUpperOnlyCount;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    int32 OverrideBlendSpaceCount;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bOverriddenBlendSpacePlayerActive;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool IgnoreRenderControl;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bUseOptimizationDisableTick;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bSimpleCharacter;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bUseOptimizationharacterMinLOD1;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bIgnoreOcclusion;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bRenderControl;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    TArray<FName> DisableInputActionStateArray;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bBlockingWhenOverlapMoving;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bCheckRuleMoveWallHitPossible;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    AActor* VehicleActor;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector VehicleActorPrevLocation;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FRotator VehicleActorPrevRotation;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bVehicleTargetActorControlRotation;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector VehicleActorDiffLocation;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector VehicleTargetActorDiffLocation;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector VehicleTargetActorPrevLocation;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector ActorLocationOnVehicleActor;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bBlockSimulatePhysicsFromVehicleTransform;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bLockupSimulatePhysics;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bDisableFootIKWhenRideOnVehicle;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bVehicleActorPhotoModeDiffLocation;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector VehicleActorPhotoModeDiffLocation;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    int32 KeepAllBodiesPhysicsPositionFrame;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    int32 KeepAllBodiesPhysicsPositionZeroBlendWeightFrame;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FName Tribe;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    TArray<FName> CharacterTags;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bBattleState;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bImpossibleAutoLockOn;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bOnAutoLockOnPhase;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bAutoLockOnAtAfterTPS;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FHitResult MoveBlockedByHitInfo;

    UPROPERTY(EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    uint32 BlockMovementFlags;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bPressedTrainingRoomTrigger;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bUseMoveConstraint;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector MoveConstraintForwardDirection;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bMoveConstraintDirXYOnly;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    UCurveFloat* MoveConstraintForwardFactor;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    UCurveFloat* MoveConstraintRightFactor;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector MoveConstraintDirectionStart;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector MoveConstraintDirectionEnd;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool MoveConstraintRightDotCalcuate;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool MoveConstraintEveryUpdate;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bUseJumpConstraint;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float JumpConstraintMaxJump;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float JumpConstraintMaxXY;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FString JumpConstraintJumpFrontPath;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float JumpConstraintUnlockJumpFromSplineProgress;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bUsePhysicsConstraint;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bIgnoreImpartBaseVelocityX;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bIgnoreImpartBaseVelocityY;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bIgnoreImpartBaseVelocityZ;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bOrigImpartBaseVelocityX;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bOrigImpartBaseVelocityY;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bOrigImpartBaseVelocityZ;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    int32 PriorityWhenSameWeightOverlap;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float AlwaysTickDistance;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FName SpawnAreaName;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector SpawnAreaLocation;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FName CharacterBindingSocket;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FVector CharacterBindingRelativeLocation;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UBlendSpaceBase* CharacterBindingIdleBlendSpace;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    UPhysicsAsset* CharacterBindingPhysicsAsset;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    UPhysicsAsset* BodyMeshOriginPhysicsAsset;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float CharacterParticleScale;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bHidePonyTail;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FRotator RotClimbControlOrig;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector RotClimbControlUpVector;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RuleMoveBlockAreaRadius;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RuleMoveBlockAreaZHeight;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector RuleMoveBlockAreaOffset;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RuleMoveBlockTargetCheckRadius;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    int32 DisableRuleMoveBlockArea;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    int32 DisableRuleMove;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    int32 DisableRuleMoveRotation;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    int32 DisableHuddleUpAction;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    int32 DisableEventMove;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bInvalidRuleMoveTarget;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bExcludingRuleMoveIgnoreTarget;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bDisableMoveCollisionOverlap;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bDisableControllerInput;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bIgnoreAttachedSequenceOverlabContrl;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    TSet<FName> LimitedScanVolumeNameSet;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bNoScan;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bScanIgnoreBusy;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool ScanRegistered;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bScanTargeted;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float LandingDamageHeight;

    UPROPERTY(EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    double LandedTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FName CurrentStanceName;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bCharacterHiddenInGame;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bOriginCharacterHiddenInGame;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bLockCharacterHiddenInGame;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bCharacterHiddenInGameUntilEvent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bCharacterHiddenInActorStudio;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bCompletedCreateCharacter;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bAlwaysActorTickWhenHidden;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RecreatePhysicsStateTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    int32 RecordPhysXTaskCount;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    TEnumAsByte<ECollisionChannel> FloorCheckCollisionObjectType;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bIgnoreExistFloor;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bExistFloor;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    TArray<FVector> FloorCheckMoveHistroy;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FName FloorCheckFloorLevelName;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bForceFoldWeapon;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bForceFoldWeaponStance;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector CachedCharacterBoundExtents;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bForceWeaponHide;

    UPROPERTY(EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    uint32 PauseRuleMoveGUID;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    TMap<FName, bool> CustomBoolMap;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    TMap<FName, float> CustomFloatMap;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    TMap<FName, int32> ShowKeyTagMap;

    UPROPERTY(EditAnywhere, Export, Transient, meta = (AllowPrivateAccess = true))
    TArray<TWeakObjectPtr<UPrimitiveComponent>> RuleMoveBlockShapeComponentArray;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector BodyRelativeLocation;

    UPROPERTY(EditAnywhere, Export, Transient, meta = (AllowPrivateAccess = true))
    TArray<TWeakObjectPtr<UFXSystemComponent>> RegisterFXSystemArray;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bIgnoreHiddenInGame;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bItemInteractionToggle;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bItemInteractionAllow;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bGrabPivotChange;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bGrabRotateLockChange;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bProcessedMoveState;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta = (AllowPrivateAccess = true))
    USpotLightComponent* DroneSpotLightComp;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FRotator InitialDroneLightRotation;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float DroneLocationAddZ;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta = (AllowPrivateAccess = true))
    USceneComponent* InteractionOriginComponent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta = (AllowPrivateAccess = true))
    USceneComponent* InteractionPointComponent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta = (AllowPrivateAccess = true))
    USceneComponent* QuestMarkerComponent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector CharacterFixedLocation;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bCharacterFixedLocationOnGround;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bCheckCharacterFixedLocationOnGround;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float RecorverSequenceLookAtIKDelayTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bInteractionPauseMetaAI;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bActiveLevelSeqLookAtIK;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    int32 SelectedSystemMenu;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta = (AllowPrivateAccess = true))
    bool bIgnoreKeepAllBodiesPhysics;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta = (AllowPrivateAccess = true))
    bool bDisableAutoResetPhysics;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta = (AllowPrivateAccess = true))
    int32 AutoResetPhyiscsBasedVelocity;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta = (AllowPrivateAccess = true))
    bool bDisableKeepAllBodiesPhysics;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta = (AllowPrivateAccess = true))
    bool bResetPhysicsWithWeight;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bUseAutoKeepAllBodiesPhysics;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FName KeepAllBodiesPhysicsTargetBone;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float KeepAllBodiesPhysicsDist;

private:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bSupportRagdollPoseSnapshot;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FName PoseSnapshotAdditionalCheckBone;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float UnderWaterLinearDamping;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float UnderWaterAngularDamping;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bPhysicsForceReInitWhenInitActor;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector LastWaterCheckLocation;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bUnderWater;

protected:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    TMap<int32, FGuid> GrabTransitGuidMap;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float GrabTransitEndBlockMoveDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float GrabActiveDist;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float GrabActiveYawDiff;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector GrabLastForward;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector GrabLastLocation;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FVector GrabLastDeltaLoc;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float GrabIKAlpha;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    UCurveFloat* CurveGrabIK;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float CurveGrabStartTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float CurveGrabLength;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float LastSetComponentTickInterval;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FRotator ParallelTick_SetActorRotation;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bPressedInteractionActionInput;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bEnableInteractionBlock;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bRunningInteractionGraph;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bEnableInteractionMove;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    int32 NeedPonytailClothConfigUpdate;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    TArray<FName> EquipmentDataList;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bInitialCurve;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    UCurveFloat* JumpToSprintMoveSpeedCurveData;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    UCurveFloat* SlopeJumpToLandMoveSpeedCurveData;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    UCurveFloat* SwimToGroundMoveSpeedCurveData;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    UCurveFloat* JumpToSprintShortMoveSpeedCurveData;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    UCurveFloat* JumpHighToMoveControlDurationData;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    TMap<FName, int32> ActionBindSkillCmdStateMap;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FName CurrentBulletItemAlias;

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

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bManualResetPhysics;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bResetPhyiscsWithControlWeight;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    float LastSwimmingTime;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FTransform CapsuleComponentPreviousTransform;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    FTransform CapsuleComponentCurrentTransform;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bNeedInitializeAnimation;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bRegisterSequentialTick;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    int32 SequenceAnimImmidateUpdateCount;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    bool bDisableKawaiiPhysicsResetWhenAttachedToLevelSeq;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, Transient, meta = (AllowPrivateAccess = true))
    float KawaiiPhysicsResetTargetAlpha;

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta = (AllowPrivateAccess = true))
    TSet<FName> SBActivatedLevelStreamingVolumes;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bUseSliceSkeletalMesh;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    bool bForceMipLevelsToBeResidentWhenSequencer;

private:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float SignificanceManagerOptimizationScale;

public:

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION(BlueprintCallable)
    void WeaponForceHide(bool bHide);

    UFUNCTION(BlueprintCallable)
    void UpdateEyePosition(bool inReset);

    UFUNCTION(BlueprintCallable)
    void StartFlyingAction();

    UFUNCTION(BlueprintCallable)
    void StartClimbing(FHitResult Hit);

    UFUNCTION(BlueprintCallable)
    void SetOverridePonytailClothPhysicsAsset(UPhysicsAsset* inClothPhysicsAsset);

    UFUNCTION(BlueprintCallable)
    void SetOverrideClothPhysicsAsset(const FString& inMeshPath, bool inApplyHair, bool inFromBodyMesh);

    UFUNCTION(BlueprintCallable)
    void SetMoveToTargetLocation(FVector InTargetLocation, FVector InTargetDirection, float InMoveSpeedPerSec, float InMinimumDistToTarget, USceneComponent* pBaseComp, float InAfterBlockMoveInputDuration);

    UFUNCTION(BlueprintCallable)
    void SetMoveInputBlockDuration(float InDuration);

    UFUNCTION(BlueprintCallable)
    void SetMoveInputBlock(bool inMoveBlock);

    UFUNCTION(BlueprintCallable)
    void SetLockupSimulatePhysics(bool inLockupSimulatePhysics);

    UFUNCTION(BlueprintCallable)
    void SetKinematicForShortPonytail(bool bFlag);

    UFUNCTION(BlueprintCallable)
    void SetKeepAllBodiesPhysicsTransform(int32 inKeepFrame);

    UFUNCTION(BlueprintCallable)
    void SetGlobalMaterialScalarParameterValue(FName InParameterName, float InValue);

    UFUNCTION(BlueprintCallable)
    void SetEnableCollision(bool bEnable);

    UFUNCTION(BlueprintCallable)
    void SetDroneSpotLight(USpotLightComponent* inSpotLightComponent);

    UFUNCTION(BlueprintCallable)
    void SetDollyCamMode(bool bFlag);

    UFUNCTION(BlueprintCallable)
    void SetCustomFloat(FName inCustom, float InValue);

    UFUNCTION(BlueprintCallable)
    void SetCustomBool(FName inCustom, bool InValue);

    UFUNCTION(BlueprintCallable)
    void SetClothAdditiveWindDirection(FVector inAdditiveWindDirection);

    UFUNCTION(BlueprintCallable)
    void SetCamOverrideFovMode(float NewFOV, float BlendTime);

    UFUNCTION(BlueprintCallable)
    void SetCameraLagSpeed(float InSpeed);

    UFUNCTION(BlueprintCallable)
    bool SetBlackboardVectorValue(FName InName, FVector InValue);

    UFUNCTION(BlueprintCallable)
    bool SetBlackboardIntValue(FName InName, int32 InValue);

    UFUNCTION(BlueprintCallable)
    bool SetBlackboardFloatValue(FName InName, float InValue);

    UFUNCTION(BlueprintCallable)
    void SetActivateFootIK(const FString& CallStack, bool bInActive, float InBlendTime, float InTargetValue, float InApplyDelayTime, bool bInForceApply, float InPriority);

    UFUNCTION(BlueprintCallable)
    void SetActivateFeetIK(bool bInActive);

    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerRequest_DoJump(bool inbJump, bool inbJumpDir, FVector inJumpDir);

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerMoveWrapper(float Timestamp, FVector_NetQuantize10 InAccel, FVector_NetQuantize100 ClientLoc, uint8 CompressedMoveFlags, uint8 ClientRoll, uint32 View, UPrimitiveComponent* ClientMovementBase, FName ClientBaseBoneName, uint8 ClientMovementMode);

    UFUNCTION(Reliable, Server, WithValidation)
    void ServerMoveNoBaseWrapper(float Timestamp, FVector_NetQuantize10 InAccel, FVector_NetQuantize100 ClientLoc, uint8 CompressedMoveFlags, uint8 ClientRoll, uint32 View, uint8 ClientMovementMode);

    UFUNCTION(BlueprintCallable)
    float RopeSwingPendulumAnglePerAlpha();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReturnToDefault();

    UFUNCTION(BlueprintCallable)
    void RegisterFXSystem(UFXSystemComponent* inFXSystem);

    UFUNCTION(BlueprintCallable)
    void OnToggleClimbCam();

    UFUNCTION(BlueprintCallable)
    void OnRep_BroadcastSpawnInfo();

    UFUNCTION(BlueprintCallable)
    void OnFinishedLevelSequence();

    UFUNCTION(BlueprintCallable)
    void OnCollisionOriginHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

    UFUNCTION(BlueprintCallable)
    void OnCollisionOriginEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

    UFUNCTION(BlueprintCallable)
    void OnCollisionOriginBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    UFUNCTION(BlueprintCallable)
    void OnCapsuleComponentEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

    UFUNCTION(BlueprintCallable)
    void OnCapsuleComponentBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyShowEvent(FName EventTagName, FName CustomNameValue);

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyBP_SliceMesh(FName SliceBone, FName AttachBone0, const FVector& RelativeCapLocation0, FName AttachBone1, const FVector& RelativeCapLocation1);

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyBP_ReleaseActor();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyBP_ReInitActor();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyBP_PostInit(const TArray<FTransform>& TargetPoints);

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NotifyBP_InitActor();

    UFUNCTION(BlueprintCallable)
    bool IsWireMoving();

    UFUNCTION(BlueprintCallable)
    bool IsWallRunJumpScaleOverrided(float& OutValue);

    UFUNCTION(BlueprintCallable)
    bool IsWallRunJump();

    UFUNCTION(BlueprintCallable)
    bool IsWallRun();

    UFUNCTION(BlueprintCallable)
    bool IsWallHitAction();

    UFUNCTION(BlueprintCallable)
    bool IsVisibleSwordTrail();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsValidTachyWingSnapshotDataPath() const;

    UFUNCTION(BlueprintCallable)
    bool IsValidMoveRightSmoothValue(bool inIgnoreGamePad);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsValidHairSnapshotDataPath() const;

    UFUNCTION(BlueprintCallable)
    bool IsUseSlopeMovingCamera();

    UFUNCTION(BlueprintCallable)
    bool IsUnderWaterSwimming();

    UFUNCTION(BlueprintCallable)
    bool IsTPSMode();

    UFUNCTION(BlueprintCallable)
    bool IsSwimJumping();

    UFUNCTION(BlueprintCallable)
    bool IsSprintJump();

    UFUNCTION(BlueprintCallable)
    bool IsSprint();

    UFUNCTION(BlueprintCallable)
    bool IsSlopeMoving();

    UFUNCTION(BlueprintCallable)
    bool IsSlopeJumpOut();

    UFUNCTION(BlueprintCallable)
    bool IsSlopeJumping();

    UFUNCTION(BlueprintCallable)
    bool IsSlideSlipJumping();

    UFUNCTION(BlueprintCallable)
    bool IsSlideSlipFalling();

    UFUNCTION(BlueprintCallable)
    bool IsSideRodWallless();

    UFUNCTION(BlueprintCallable)
    bool IsSideRodJumping();

    UFUNCTION(BlueprintCallable)
    bool IsSideRodFalling();

    UFUNCTION(BlueprintCallable)
    bool IsShowCharacter();

    UFUNCTION(BlueprintCallable)
    bool IsShortPonyTail();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsRunSpiderNavWay() const;

    UFUNCTION(BlueprintCallable)
    bool IsRunningSkill();

    UFUNCTION(BlueprintCallable)
    bool IsRunningInteraction();

    UFUNCTION(BlueprintCallable)
    bool IsRunHuddleUpAction();

    UFUNCTION(BlueprintCallable)
    bool IsRun();

    UFUNCTION(BlueprintCallable)
    bool IsRopeSwing();

    UFUNCTION(BlueprintCallable)
    bool IsRopeMoving();

    UFUNCTION(BlueprintCallable)
    bool IsRodJumping();

    UFUNCTION(BlueprintCallable)
    bool IsRagdollSimulate(bool isAllBodies);

    UFUNCTION(BlueprintCallable)
    bool IsPlayJumpTransitAnim();

    UFUNCTION(BlueprintCallable)
    bool IsPlayingRunInteraction();

    UFUNCTION(BlueprintCallable)
    bool IsPlayableWhenLevelSequence();

    UFUNCTION(BlueprintCallable)
    bool IsPhotoModeFacialAnimationEnabled();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPhotoModeDefaultWeaponSnapshot() const;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPhotoModeDefaultSnapshot() const;

    UFUNCTION(BlueprintCallable)
    bool IsOverrideBlendSpaceUpper();

    UFUNCTION(BlueprintCallable)
    bool IsOverriddenBlendSpacePlayerActive();

    UFUNCTION(BlueprintCallable)
    bool IsNeedPlayTurnAnim();

    UFUNCTION(BlueprintCallable)
    bool IsMovingTargetOn();

    UFUNCTION(BlueprintCallable)
    bool IsMoving();

    UFUNCTION(BlueprintCallable)
    bool IsMoveInputBlock();

    UFUNCTION(BlueprintCallable)
    bool IsMoveBlockedByWall();

    UFUNCTION(BlueprintCallable)
    bool IsMoveBackByTargetOverlap();

    UFUNCTION(BlueprintCallable)
    bool IsMotionMoving();

    UFUNCTION(BlueprintCallable)
    bool IsMetaAITiredState();

    UFUNCTION(BlueprintCallable)
    bool IsLockOn();

    UFUNCTION(BlueprintCallable)
    bool IsJumping();

    UFUNCTION(BlueprintCallable)
    bool IsJoggingRun();

    UFUNCTION(BlueprintCallable)
    bool IsHoldSwimming();

    UFUNCTION(BlueprintCallable)
    bool IsHoldBalanceBeam();

    UFUNCTION(BlueprintCallable)
    bool IsHidePonyTail();

    UFUNCTION(BlueprintCallable)
    bool IsGrabObjectMoving();

    UFUNCTION(BlueprintCallable)
    bool IsGlide();

    UFUNCTION(BlueprintCallable)
    bool IsFlyingAction();

    UFUNCTION(BlueprintCallable)
    bool IsFishingReel();

    UFUNCTION(BlueprintCallable)
    bool IsExistFloor();

    UFUNCTION(BlueprintCallable)
    bool IsEventMovingSlidingState();

    UFUNCTION(BlueprintCallable)
    bool IsEventMoving();

    UFUNCTION(BlueprintCallable)
    bool IsEnableKneeIK();

    UFUNCTION(BlueprintCallable)
    bool IsDoubleJump();

    UFUNCTION(BlueprintCallable)
    bool IsDisableLookAtEye();

    UFUNCTION(BlueprintCallable)
    bool IsDisableIdleAdditiveAnim();

    UFUNCTION(BlueprintCallable)
    bool IsDisableFootIKWhenRideOnVehicle();

    UFUNCTION(BlueprintCallable)
    bool IsCurrentStretchSideRodSearch();

    UFUNCTION(BlueprintCallable)
    bool IsClimbing();

    UFUNCTION(BlueprintCallable)
    bool IsBlockingMode();

    UFUNCTION(BlueprintCallable)
    bool IsbDoWallJump();

    UFUNCTION(BlueprintCallable)
    bool IsBattle();

    UFUNCTION(BlueprintCallable)
    bool IsAttackParried();

    UFUNCTION(BlueprintCallable)
    bool IsAttachedToLevelSequenceWithoutPlayable();

    UFUNCTION(BlueprintCallable)
    bool IsAllowLookAtTargetWhenLevelSequence();

    UFUNCTION(BlueprintCallable)
    bool IsActiveTPSAimOffset();

    UFUNCTION(BlueprintCallable)
    bool IsActiveOverlapMove();

    UFUNCTION(BlueprintCallable)
    bool IsActiveFullBodyIK_ByName(const FString& Name);

    UFUNCTION(BlueprintCallable)
    bool IsActiveFullBodyIK();

    UFUNCTION(BlueprintCallable)
    bool IsActiveFootIK();

    UFUNCTION(BlueprintCallable)
    bool IsActiveFeetIK();

    UFUNCTION(BlueprintCallable)
    bool IsActiveCustomMovingStanceData();

    UFUNCTION(BlueprintCallable)
    bool IsActiveBoneBlend();

    UFUNCTION(BlueprintCallable)
    bool IsAccelSwimUp();

    UFUNCTION(BlueprintCallable)
    bool IsAccelSwimDown();

    UFUNCTION(BlueprintCallable)
    float GetWallSlideSideValue();

    UFUNCTION(BlueprintCallable)
    FVector GetWallRunNormal();

    UFUNCTION(BlueprintCallable)
    FVector GetWallRunDir();

    UFUNCTION(BlueprintCallable)
    FVector GetTPSLookAtWorldLocation(bool inReCheckHitLocation);

    UFUNCTION(BlueprintCallable)
    FVector GetTPSLookAtLocalSpaceDirection();

    UFUNCTION(BlueprintCallable)
    FVector2D GetTPSLookAtBlendSpaceXY();

    UFUNCTION(BlueprintCallable)
    float GetSprintSpeedScale();

    UFUNCTION(BlueprintCallable)
    bool GetSequencerAnimMode();

    UFUNCTION(BlueprintCallable)
    float GetSelfieAnimBSValue();

    UFUNCTION(BlueprintCallable)
    float GetSBSpeedForAnimGraph();

    UFUNCTION(BlueprintCallable)
    USBSkeletalMeshComponent* GetSBSkeletalMeshComponent(TEnumAsByte<ESBSkelMeshSlot> Slot);

    UFUNCTION(BlueprintCallable)
    FVector GetSBCharacterRightVector();

    UFUNCTION(BlueprintCallable)
    float GetRunInputDuration();

    UFUNCTION(BlueprintCallable)
    float GetPoseSnapBlendWeight();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetPoseName_PhotoMode() const;

    UFUNCTION(BlueprintCallable)
    FName GetPonytailMeshName();

    UFUNCTION(BlueprintCallable)
    UAnimSequence* GetPhotoModeFacialAnimation();

    UFUNCTION(BlueprintCallable)
    TEnumAsByte<EPhysicalSurface> GetOverrideFootStepPhySurface(TEnumAsByte<EPhysicalSurface> inDefaultSurfacee);

    UFUNCTION(BlueprintCallable)
    float GetMoveInputDirectionAngle();

    UFUNCTION(BlueprintCallable)
    ASBCharacter* GetLookAtTargetCharacter();

    UFUNCTION(BlueprintCallable)
    ASBCharacter* GetLockOnTargetCharacter();

    UFUNCTION(BlueprintCallable)
    float GetKneeIKSearchDistanceForwardR();

    UFUNCTION(BlueprintCallable)
    float GetKneeIKSearchDistanceForwardL();

    UFUNCTION(BlueprintCallable)
    float GetKneeIKSearchDistanceBackwardR();

    UFUNCTION(BlueprintCallable)
    float GetKneeIKSearchDistanceBackwardL();

    UFUNCTION(BlueprintCallable)
    float GetKneeIKOffset_RToe();

    UFUNCTION(BlueprintCallable)
    float GetKneeIKOffset_RKnee();

    UFUNCTION(BlueprintCallable)
    float GetKneeIKOffset_LToe();

    UFUNCTION(BlueprintCallable)
    float GetKneeIKOffset_LKnee();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    float GetKawaiiPhysicsAlpha();

    UFUNCTION(BlueprintCallable)
    float GetIdleAdditiveAnimAlpha();

    UFUNCTION(BlueprintCallable)
    float GetGrabIKAlpha();

    UFUNCTION(BlueprintCallable)
    FVector GetGlobalMaterialVectorParameterValue(FName InParameterName);

    UFUNCTION(BlueprintCallable)
    float GetGlobalMaterialScalarParameterValue(FName InParameterName);

    UFUNCTION(BlueprintCallable)
    float GetGamePadRTriggerAxisValue();

    UFUNCTION(BlueprintCallable)
    float GetGamePadLTriggerAxisValue();

    UFUNCTION(BlueprintCallable)
    float GetFullBodyIkActiveHitPointAngle();

    UFUNCTION(BlueprintCallable)
    FVector GetFowardVector(bool bActorFoward);

    UFUNCTION(BlueprintCallable)
    float GetFootIKAlphaValue();

    UFUNCTION(BlueprintCallable)
    float GetFishingRodDirection();

    UFUNCTION(BlueprintCallable)
    float GetFishingLookAtBlendSpaceX();

    UFUNCTION(BlueprintCallable)
    float GetFeetIKTraceScale();

    UFUNCTION(BlueprintCallable)
    float GetFeetIKAlphaValue();

    UFUNCTION(BlueprintCallable)
    int32 GetFacialIdleAnimType();

    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetFacialAnimType_PhotoMode() const;

    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetFacialAnimPosition_PhotoMode() const;

    UFUNCTION(BlueprintCallable)
    bool GetEyeTrackingToCam();

    UFUNCTION(BlueprintCallable)
    FVector2D GetEyePosition2D();

    UFUNCTION(BlueprintCallable)
    int32 GetEventMoveSideValue();

    UFUNCTION(BlueprintCallable)
    float GetEventMoveIKActivateTime();

    UFUNCTION(BlueprintCallable)
    bool GetDollyCamMode(bool bFlag);

    UFUNCTION(BlueprintCallable)
    float GetCustomPoseSnapBlendWeight();

    UFUNCTION(BlueprintCallable)
    float GetCustomFloat(FName inCustom);

    UFUNCTION(BlueprintCallable)
    bool GetCustomBool(FName inCustom);

    UFUNCTION(BlueprintCallable)
    FVector GetCustomBlendSpaceInput();

    UFUNCTION(BlueprintCallable)
    FName GetCurrentStanceName();

    UFUNCTION(BlueprintCallable)
    float GetCurrentSideRodSearchDegreeValue();

    UFUNCTION(BlueprintCallable)
    float GetCurrentRotaionPower();

    UFUNCTION(BlueprintCallable)
    float GetCurrentCustomAnimByMeshSlotAlpha(TEnumAsByte<ESBSkelMeshSlot> InMeshSlotType);

    UFUNCTION(BlueprintCallable)
    float GetCurrentCustomAnimAlpha_Upper(int32 inCustomAnimIndex);

    UFUNCTION(BlueprintCallable)
    float GetCurrentCustomAnimAlpha_Lower(int32 inCustomAnimIndex);

    UFUNCTION(BlueprintCallable)
    float GetCurrentCustomAnimAlpha(int32 inCustomAnimIndex);

    UFUNCTION(BlueprintCallable)
    float GetCurrentCustomAnimAddtiveAlpha_Upper();

    UFUNCTION(BlueprintCallable)
    float GetCurrentCustomAnimAddtiveAlpha();

    UFUNCTION(BlueprintCallable)
    float GetCurrentCameraLagSpeed();

    UFUNCTION(BlueprintCallable)
    FName GetCurrentBulletItemAlias();

    UFUNCTION(BlueprintCallable)
    float GetCamOverrideFovMode();

    UFUNCTION(BlueprintCallable)
    float GetCameraZoom();

    UFUNCTION(BlueprintCallable)
    FName GetBodyMeshName();

    UFUNCTION(BlueprintCallable)
    bool GetBlackboardValue(FName InName, int32& outIntValue, float& outFloatValue, FVector& outVectorValue);

    UFUNCTION(BlueprintCallable)
    bool GetArriveMetaAIBehaviorNode();

    UFUNCTION(BlueprintCallable)
    float GetAnimControllerSpringWeight();

    UFUNCTION(BlueprintCallable)
    float GetAnimControllerFullbodyIKFactor();

    UFUNCTION(BlueprintCallable)
    FVector GetActorBottomLocation();

    UFUNCTION(BlueprintCallable)
    void ForceAllClothNextUpdateTeleportAndReset();

    UFUNCTION(BlueprintCallable)
    void ExitVehicle();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void EventUnderWater(FVector inHitLocation);

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void EventImmidateTickForEditor();

    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Event_ChangeBattleState(bool bIsBattle);

    UFUNCTION(BlueprintCallable)
    void EnterVehicle(AActor* Vehicle, bool inBlockSimulatePhysicsFromTransform, bool inControlRotation, bool bInDisableFootIKWhenRideOnVehicle);

    UFUNCTION(BlueprintCallable)
    void EndFlyingAction();

    UFUNCTION(BlueprintCallable)
    void DeactiveCustomMovingStanceData();

    UFUNCTION(BlueprintCallable)
    void ClearNeedPlayTurnAnimFlag();

    UFUNCTION(BlueprintCallable)
    bool CheckMoveRightSmoothValue(float inUnderValue, bool inIgnoreGamePad);

    UFUNCTION(BlueprintCallable)
    void ChangeAttachTarget(TEnumAsByte<ESBSkelMeshSlot> OwnerSlot, TEnumAsByte<ESBSkelMeshSlot> TargetSlot, FName AttachSocketName, float InBlendTime, float InPriority);

    UFUNCTION(BlueprintCallable)
    void CancelClimbing();

    UFUNCTION(BlueprintCallable)
    void CalcHitEventDirection(FVector ForceOrigin, FVector ForceVelocity);

    UFUNCTION(BlueprintCallable)
    float CalcAnimSpeedByWalkSpeed();

    UFUNCTION(BlueprintCallable)
    float CalcAnimSpeedByRunSpeed();

    UFUNCTION(BlueprintCallable)
    float CalcAnimSpeedByClimbSpeed();

    UFUNCTION(BlueprintCallable)
    void ApplyKeepAllBodiesPhysicsTransform();

    UFUNCTION(BlueprintCallable)
    void AddCameraZoom(float Value);

    // Fix for true pure virtual functions not being implemented
    UFUNCTION(BlueprintCallable)
    bool PlaySingleShow(const FString& inShowPath, bool inFullPath, FVector InTargetLocation) PURE_VIRTUAL(PlaySingleShow, return false;);

    UFUNCTION(BlueprintCallable)
    void ActorStopCustomAnim(FGuid InAnimGuid, FName inComponentTag, float InOutBlendTime) PURE_VIRTUAL(ActorStopCustomAnim, );

    UFUNCTION(BlueprintCallable)
    FGuid ActorPlayCustomAnimSequenceMeshSlot(TEnumAsByte<ESBSkelMeshSlot> InSlotIndex, UAnimSequence* pAnimSeqAsset, FName inComponentTag, float InPlayStartTime, float InPlayEndTime, float InPlayRate, float InBlendInTime, float InBlendOutTime, bool bInLoop, float Priority, bool bClearAllAnim) PURE_VIRTUAL(ActorPlayCustomAnimSequenceMeshSlot, return FGuid{};);

    UFUNCTION(BlueprintCallable)
    FGuid ActorPlayCustomAnimSequence(UAnimSequence* pAnimSeqAsset, FName inComponentTag, float InPlayStartTime, float InPlayEndTime, float InPlayRate, float InBlendInTime, float InBlendOutTime, bool bInLoop, float Priority, bool bClearAllAnim) PURE_VIRTUAL(ActorPlayCustomAnimSequence, return FGuid{};);

    UFUNCTION(BlueprintCallable)
    FGuid ActorPlayCustomAnimNameMeshSlot(TEnumAsByte<ESBSkelMeshSlot> InSlotIndex, const FString& InAnimName, FName inComponentTag, float InPlayStartTime, float InPlayEndTime, float InPlayRate, float InBlendInTime, float InBlendOutTime, bool bInLoop, float Priority, bool bClearAllAnim) PURE_VIRTUAL(ActorPlayCustomAnimNameMeshSlot, return FGuid{};);

    UFUNCTION(BlueprintCallable)
    FGuid ActorPlayCustomAnimName(const FString& InAnimName, FName inComponentTag, float InPlayStartTime, float InPlayEndTime, float InPlayRate, float InBlendInTime, float InBlendOutTime, bool bInLoop, float Priority, bool bClearAllAnim) PURE_VIRTUAL(ActorPlayCustomAnimName, return FGuid{};);

    UFUNCTION(BlueprintCallable)
    bool IsPoolingActor() PURE_VIRTUAL(IsPoolingActor, return false;);
};
