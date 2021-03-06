// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MessageBusDemo : ModuleRules
{
	public MessageBusDemo(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
		
		PrivateIncludePathModuleNames.AddRange(
			new string[] {
				"Messaging",
				"MessagingCommon",
			}
		);
	}
}
