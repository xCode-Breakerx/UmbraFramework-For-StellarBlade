// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class BlueprintRecompiler : ModuleRules
{
	public BlueprintRecompiler(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;


		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"UnrealEd",
				"EditorStyle",
				"EditorWidgets",
				"ToolMenus",
				"Slate",
				"SlateCore",
				"BlueprintGraph",
				"KismetCompiler",
				"AssetRegistry",
				"AssetTools",
				"PluginUtils",
				"PluginBrowser",
				"Projects"
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"EditorStyle",
				"EditorWidgets",
				"GraphEditor",
				"Kismet",
				"KismetCompiler",
				"PropertyEditor",
				"RenderCore",
				"ContentBrowser",
				"WorkspaceMenuStructure",
				"AssetRegistry",
				"AssetTools"
			}
		);
	}
}