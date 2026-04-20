// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/ItemPuerta.h"

#include "Components/ComponenteDeFragmentos.h"
#include "EntregasPracticas/EntregasPracticasCharacter.h"


// Sets default values
AItemPuerta::AItemPuerta()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AItemPuerta::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItemPuerta::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AItemPuerta::OnInteract_Implementation(AEntregasPracticasCharacter* Actor)
{
	IInteractInterface::OnInteract_Implementation(Actor);
	if (Actor -> bHasKey==true)
	{
		Destroy();
	}
}

