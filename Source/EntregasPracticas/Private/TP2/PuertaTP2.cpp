// Fill out your copyright notice in the Description page of Project Settings.


#include "TP2/PuertaTP2.h"
#include "TP2/Altar.h"


// Sets default values
APuertaTP2::APuertaTP2()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	BoxCollision = CreateDefaultSubobject<UBoxComponent>("BoxCollison");
	RootComponent = BoxCollision;
	BoxCollision->SetLineThickness(5);
	BoxCollision->SetBoxExtent(FVector(150, 150, 150));
	BoxCollision->SetHiddenInGame(false);
	
	MeshAltar = CreateDefaultSubobject<UStaticMeshComponent>("MeshAltar");
	MeshAltar->SetupAttachment(RootComponent);
	
	AltarCargadoComponent = CreateDefaultSubobject<UAltarCargadoComponent>("AltarCargado");
}

// Called when the game starts or when spawned
void APuertaTP2::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APuertaTP2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APuertaTP2::OnInteract_Implementation(AEntregasPracticasCharacter* Actor)
{
	IInteractInterface::OnInteract_Implementation(Actor);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "No se puede abrir. Debes activar los altares.");
}


