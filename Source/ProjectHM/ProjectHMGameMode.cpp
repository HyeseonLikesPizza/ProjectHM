// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProjectHMGameMode.h"
#include "ProjectHMCharacter.h"
#include "UObject/ConstructorHelpers.h"

AProjectHMGameMode::AProjectHMGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
