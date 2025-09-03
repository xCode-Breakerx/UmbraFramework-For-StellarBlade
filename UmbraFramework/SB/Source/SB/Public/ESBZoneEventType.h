#pragma once
#include "CoreMinimal.h"
#include "ESBZoneEventType.generated.h"

UENUM(BlueprintType)

enum ESBZoneEventType
{
    ZoneEvent_Spawn,
    ZoneEvent_PlayLevelSeq,
    ZoneEvent_AttachActorEffect,
    ZoneEvent_ZoneControl,
    ZoneEvent_AcquireQuest,
    ZoneEvent_Despawn,
    ZoneEvent_Theater,
    ZoneEvent_Item,
    ZoneEvent_AIDecorator,
    ZoneEvent_ZoneObjControl,
    ZoneEvent_ZoneEnvControl,
    ZoneEvent_UIAction,
    ZoneEvent_EffectVolumeControl,
    ZoneEvent_ItemAction,
    ZoneEvent_Interaction,
    ZoneEvent_StartMatchMaking,
    ZoneEvent_StopMatchMaking,
    ZoneEvent_RequestPathWay,
    ZoneEvent_AreaControlVolumeControl,
    ZoneEvent_ReturnToSinglePlay,
    ZoneEvent_ActorBattleState,
    ZoneEvent_GuideAction,
    ZoneEvent_ZonePhaseEvent,
    ZoneEvent_ActorActive,
    ZoneEvent_InteractCamp,
    ZoneEvent_LaserControl,
    ZoneEvent_PlayerWarp,
    ZoneEvent_MetaAI,
    ZoneEvent_ActivateHint,
    ZoneEvent_CompleteHint,
    ZoneEvent_ZoneEventActorControl,
    ZoneEvent_ChangeZone,
    ZoneEvent_FinishBossChallenge,
    ZoneEvent_NikkeNextWave,
};
