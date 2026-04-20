// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/ItemFragmenteLlave.h"

#include "Components/ComponenteDeFragmentos.h"
#include "Components/SphereComponent.h"
#include "EntregasPracticas/EntregasPracticasCharacter.h"


// Sets default values
AItemFragmenteLlave::AItemFragmenteLlave()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	RootComponent = SphereCollision;

	SphereMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SphereMesh"));
	SphereMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AItemFragmenteLlave::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItemFragmenteLlave::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AItemFragmenteLlave::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	
	Super::NotifyActorBeginOverlap(OtherActor);
	
	AEntregasPracticasCharacter* MyCharacter = Cast<AEntregasPracticasCharacter>(OtherActor);
}

void AItemFragmenteLlave::AgregarFragmentos(AActor* OtherActor)
{

	auto Comp = OtherActor->FindComponentByClass<UComponenteDeFragmentos>();
	if (Comp) {
		Comp->AgregarFragmentos();
		Destroy();
	}
}

void AItemFragmenteLlave::OnInteract_Implementation(AEntregasPracticasCharacter* Actor)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, "Interactuando");
	OnInteractable.Broadcast(this);
	AgregarFragmentos(Actor);
}

