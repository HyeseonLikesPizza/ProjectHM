// Fill out your copyright notice in the Description page of Project Settings.

#include "Interactable.h"
#include "ProjectHMGameMode.h"
#include "GameplayController.h"

void AGameplayController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	InputComponent->BindAction("Use", IE_Pressed, this, &AGameplayController::Interact);
}

void AGameplayController::AddItemToInventoryByID(FName ID)
{
	AProjectHMGameMode* GameMode = Cast<AProjectHMGameMode>(GetWorld()->GetAuthGameMode());
	UDataTable* ItemTable = GameMode->GetItemDB();

	FInventoryItem* ItemToAdd = ItemTable->FindRow<FInventoryItem>(ID, "");

	if (ItemToAdd )
	{
		Inventory.Add(*ItemToAdd);
		ReloadInventory();
	}

}

void AGameplayController::Interact()
{
	//UE_LOG(Warning, TEXT("Interact"));

	if (CurrentInteractable)
	{
		CurrentInteractable->Interact(this);
	}
}