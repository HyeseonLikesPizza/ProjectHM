// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "ProjectHM.h"
#include "GameFramework/GameModeBase.h"
#include "ProjectHMGameMode.generated.h"

UCLASS(minimalapi)
class AProjectHMGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AProjectHMGameMode();

	class UDataTable* GetItemDB() const { return ItemDB;}

protected:

	UPROPERTY(EditDefaultsOnly)
	class UDataTable* ItemDB;



};



