// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"
#include "Interfaces/InteractInterface.h"
#include "ItemFragmenteLlave.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInteractable, AActor*, Actor);

UCLASS()
class ENTREGASPRACTICAS_API AItemFragmenteLlave : public AItemBase, public IInteractInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AItemFragmenteLlave();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite);
	TObjectPtr<USphereComponent> SphereCollision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite);
	TObjectPtr<UStaticMeshComponent> SphereMesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable)
	FOnInteractable OnInteractable;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	UFUNCTION(BlueprintCallable)
	void AgregarFragmentos(AActor* OtherActor);
	
	UFUNCTION(BlueprintCallable)
	virtual void OnInteract_Implementation(AEntregasPracticasCharacter* Actor) override;
	
};
