// Fill out your copyright notice in the Description page of Project Settings.


#include "TP2/AltarCargadoComponent.h"
#include "TP2/Altar.h"


// Sets default values for this component's properties
UAltarCargadoComponent::UAltarCargadoComponent()
{

}


// Called when the game starts
void UAltarCargadoComponent::BeginPlay()
{
	Super::BeginPlay();
	AltaresACargar = AltaresTotales.Num();
	
	for (AAltar* AltarActual : AltaresTotales)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, AltarActual->GetName() + ": ");
		AltarActual->AltarCargado.AddDynamic(this, &UAltarCargadoComponent::AlCargarAltar);
	}
}

void UAltarCargadoComponent::AlCargarAltar()
{
	AltaresRecogidos++;
	
	if (AltaresRecogidos == AltaresACargar)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, "Se Destruyo la puerta!");
		GetOwner() -> Destroy();
	}
}

