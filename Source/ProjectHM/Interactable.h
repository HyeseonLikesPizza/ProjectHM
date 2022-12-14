// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ProjectHM.h"
#include "GameFramework/Actor.h"
#include "Interactable.generated.h"

UCLASS()
class PROJECTHM_API AInteractable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractable();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// 플레이어가 상호작용 액터와 상호작용 할 때 호출되는 함수
	// 블루프린트로 구현
	UFUNCTION(BlueprintImplementableEvent)
	void Interact(APlayerController* Controller);

	UPROPERTY(EditDefaultsOnly)
	FString Name;

	UPROPERTY(EditDefaultsOnly)
	FString Action;

	UFUNCTION(BlueprintCallable, Category = "Pickup")
	FString GetUseText() const { return FString::Printf(TEXT("%s : Press E to %s"), *Name, *Action); };



};
