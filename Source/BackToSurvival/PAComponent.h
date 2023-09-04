// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PAComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BACKTOSURVIVAL_API UPAComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	uint8 max_pa;
	uint8 current_pa;

public:	

	// Sets default values for this component's properties
	UPAComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void SetMaxPA(int pa);

	UFUNCTION(BlueprintCallable)
	bool HasEnoughPA(uint8 actionCost);

	UFUNCTION(BlueprintCallable)
	uint8 GetCurrentPA();

	UFUNCTION(BlueprintCallable)
	void RefillPA();

	UFUNCTION(BlueprintCallable)
	bool DecreasePA(int PA);

};
