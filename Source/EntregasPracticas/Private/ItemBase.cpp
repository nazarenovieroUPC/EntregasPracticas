// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemBase.h"
#include "Components/SphereComponent.h"
#include <EntregasPracticas/EntregasPracticasCharacter.h>
#include "Components/ComponenteDeFragmentos.h"

// Sets default values
AItemBase::AItemBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	RootComponent = SphereCollision;

	SphereMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SphereMesh"));
	SphereMesh->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AItemBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItemBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AItemBase::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	
	AEntregasPracticasCharacter* MyCharacter = Cast<AEntregasPracticasCharacter>(OtherActor);

	if (MyCharacter) 
	{
		MyCharacter->MostrarMensaje();
	}
}

void AItemBase::AgregarFragmentos(AActor* OtherActor)
{
	auto Comp = OtherActor->FindComponentByClass<UComponenteDeFragmentos>();
	if (Comp) {
		Comp->AgregarFragmentos();
		Destroy();
	}
}


