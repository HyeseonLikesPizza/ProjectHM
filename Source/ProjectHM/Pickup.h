// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ProjectHM.h"
#include "Interactable.h"
#include "Pickup.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTHM_API APickup : public AInteractable
{
	GENERATED_BODY()
	
public:

	APickup();

protected:

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* PickupMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName ItemID;
	
};
