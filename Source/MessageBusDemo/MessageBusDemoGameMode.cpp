// Copyright Epic Games, Inc. All Rights Reserved.

#include "MessageBusDemoGameMode.h"
#include "MessageBusDemoHUD.h"
#include "MessageBusDemoCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMessageBusDemoGameMode::AMessageBusDemoGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AMessageBusDemoHUD::StaticClass();
}
