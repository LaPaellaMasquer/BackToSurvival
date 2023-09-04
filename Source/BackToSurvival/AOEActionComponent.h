// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectileActionComponent.h"
#include "AOEActionDataAsset.h"
#include "AOEActionComponent.generated.h"

/**
 * 
 */
UCLASS()
class BACKTOSURVIVAL_API UAOEActionComponent : public UProjectileActionComponent
{
	GENERATED_BODY()

private:
	UAOEActionDataAsset* dataAOE;
	TArray<ACharacterPawn*> targets;
	FVector targetLocation;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
public:

	bool SetGoal(FHitResult goal) override;

	int Action() override;

	virtual void ApplyAction(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	UFUNCTION(BlueprintCallable)
	float GetRadiusEffect();

};
