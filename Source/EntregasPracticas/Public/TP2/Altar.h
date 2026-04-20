// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"
#include "Components/BoxComponent.h"
#include "EntregasPracticas/EntregasPracticasCharacter.h"
#include "Interfaces/InteractInterface.h"
#include "Altar.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAltarCargado);

UCLASS()
class ENTREGASPRACTICAS_API AAltar : public AItemBase, public IInteractInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAltar();
	
	UPROPERTY(BlueprintReadWrite)
	float ContadorAltar = 0.f;
	
	UPROPERTY(BlueprintReadWrite)
	bool bPuedeActivarse = true;
	
	UPROPERTY(BlueprintReadWrite)
	FTimerHandle AltarTimerHandle;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable)
	FAltarCargado AltarCargado;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UBoxComponent> BoxCollision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> MeshAltar;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION(BlueprintCallable)
	virtual void OnInteract_Implementation(AEntregasPracticasCharacter* Actor) override;
	
	UFUNCTION(BlueprintCallable)
	virtual void TimerAltar();
};
