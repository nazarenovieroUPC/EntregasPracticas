// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ComponenteDeFragmentos.generated.h"


UCLASS(Blueprintable, BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ENTREGASPRACTICAS_API UComponenteDeFragmentos : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UComponenteDeFragmentos();

	UPROPERTY(BlueprintReadWrite)
	int FragmentosContados = 0;

	UFUNCTION(BlueprintCallable)
	void AgregarFragmentos();

	UFUNCTION(BlueprintCallable)
	void MostrarFragmentos();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
