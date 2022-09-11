// Fill out your copyright notice in the Description page of Project Settings.

#include "GameplayController.h"
#include "ProjectHMGameMode.h"

void AGameplayController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	InputComponent->BindAction("Use", IE_Pressed, this, &AGameplayController::Interact);
}

void AGameplayController::CraftItem(FInventoryItem ItemA, FInventoryItem ItemB, AGameplayController* Controller)
{

	for (auto Craft : ItemB.CraftCombinations)
	{
		if (Craft.ComponentID == ItemA.ItemID)
		{
			if (Craft.bDestroyItemA)
			{
				Inventory.RemoveSingle(ItemA);
			}
			if (Craft.bDestroyItemB)
			{
				Inventory.RemoveSingle(ItemB);
			}

			AddItemToInventoryByID(Craft.ProductID);
			ReloadInventory();
		}
	}

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