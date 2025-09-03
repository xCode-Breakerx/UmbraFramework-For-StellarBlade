// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "BlueprintRecompilerStyle.h"

class FBlueprintRecompilerCommands : public TCommands<FBlueprintRecompilerCommands>
{
public:

    FBlueprintRecompilerCommands()
        : TCommands<FBlueprintRecompilerCommands>(TEXT("BlueprintRecompiler"), NSLOCTEXT("Contexts", "BlueprintRecompiler", "BlueprintRecompiler Plugin"), NAME_None, FBlueprintRecompilerStyle::GetStyleSetName())
    {
    }

    virtual void RegisterCommands() override;

public:

    TSharedPtr<FUICommandInfo> OpenPluginWindow;
};