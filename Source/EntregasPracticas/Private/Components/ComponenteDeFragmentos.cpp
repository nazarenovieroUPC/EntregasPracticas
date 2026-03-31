// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/ComponenteDeFragmentos.h"

// Sets default values for this component's properties
UComponenteDeFragmentos::UComponenteDeFragmentos()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UComponenteDeFragmentos::AgregarFragmentos()
{
	FragmentosContados++;
}

void UComponenteDeFragmentos::MostrarFragmentos()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Cyan, FString::Printf(TEXT("Fragmentos: %d")));
	}
}


// Called when the game starts
void UComponenteDeFragmentos::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UComponenteDeFragmentos::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

