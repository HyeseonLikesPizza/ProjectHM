// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ProjectHM.h"
#include "ProjectHMCharacter.h"
#include "Interactable.h"
#include "Components/ActorComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameplayController.generated.h"



UCLASS()
class PROJECTHM_API AGameplayController : public APlayerController
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintImplementableEvent)
	void ReloadInventory();

	UFUNCTION(BlueprintCallable, Category = "Utils")
	void CraftItem(FInventoryItem ItemA, FInventoryItem ItemB, AGameplayController* Controller);

	UFUNCTION(BlueprintCallable, Category = "Utils")
	void ChangeInventoryPosition(FInventoryItem ToItem, FInventoryItem FromItem);

	UFUNCTION(BlueprintCallable, Category = "Utils")
	void DropItem(int SlotIndex);

	UFUNCTION(BlueprintCallable, Category = "Utils")
	void AddItemToInventoryByID(FName ID);

	// 플레이어가 현재 바라보고있는 상호작용 액터
	// 상호작용 액터를 바라보고 있지 않을때 nullptr이 된다.
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	class AInteractable* CurrentInteractable;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	TArray<FInventoryItem> Inventory;


protected:
	void Interact();
	virtual void SetupInputComponent() override;
	
};
