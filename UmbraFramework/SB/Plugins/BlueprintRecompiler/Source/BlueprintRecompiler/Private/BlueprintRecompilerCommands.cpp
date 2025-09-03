// Fill out your copyright notice in the Description page of Project Settings.

#include "BlueprintRecompilerCommands.h"

#define LOCTEXT_NAMESPACE "FBlueprintRecompilerModule"

void FBlueprintRecompilerCommands::RegisterCommands()
{
    UI_COMMAND(OpenPluginWindow, "Recompile All Blueprints", "Mark all blueprints dirty and force recompilation", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
