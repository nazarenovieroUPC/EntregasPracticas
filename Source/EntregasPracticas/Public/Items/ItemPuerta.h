// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"
#include "Interfaces/InteractInterface.h"
#include "ItemPuerta.generated.h"

UCLASS()
class ENTREGASPRACTICAS_API AItemPuerta : public AItemBase, public IInteractInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AItemPuerta();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION(BlueprintCallable)
	virtual void OnInteract_Implementation(AEntregasPracticasCharacter* Actor) override;
};
