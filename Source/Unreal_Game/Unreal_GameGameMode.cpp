// Copyright Epic Games, Inc. All Rights Reserved.

#include "Unreal_GameGameMode.h"
#include "Unreal_GameCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUnreal_GameGameMode::AUnreal_GameGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
