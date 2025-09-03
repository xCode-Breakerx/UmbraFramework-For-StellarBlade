// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FBlueprintRecompilerModule : public IModuleInterface
{
public:

    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

    void         PluginButtonClicked();

private:

    void                             RegisterMenus();
    void                             RecompileAllBlueprints();

    TSharedPtr<class FUICommandList> PluginCommands;
};
