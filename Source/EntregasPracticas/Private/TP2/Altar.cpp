// Fill out your copyright notice in the Description page of Project Settings.


#include "TP2/Altar.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AAltar::AAltar()
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
}

// Called when the game starts or when spawned
void AAltar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAltar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAltar::OnInteract_Implementation(AEntregasPracticasCharacter* Actor)
{
	IInteractInterface::OnInteract_Implementation(Actor);
	
	if (bPuedeActivarse)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, "Empezando a Cargar");
		bPuedeActivarse = false;
	
		GetWorldTimerManager().SetTimer(AltarTimerHandle, this, &AAltar::TimerAltar, 0.2F, true);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, "Se llamo al timer");
	}
}

void AAltar::TimerAltar()
{
	ContadorAltar += 0.1f;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Contador: %.0f"), ContadorAltar*100.f));
	
	if (ContadorAltar >= 1){
		GetWorldTimerManager().ClearTimer(AltarTimerHandle);
		
		AltarCargado.Broadcast();
		
		Destroy();
	}
}
