// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ActionDataAsset.h"
#include "GameplayTagContainer.h"
#include "ActionComponentBase.generated.h"


UCLASS(Abstract)
class BACKTOSURVIVAL_API UActionComponentBase : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UActionComponentBase();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere)
	UActionDataAsset* actionStats;

	UFUNCTION(BlueprintCallable)
	virtual int Action();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void PlayAnim();

	UFUNCTION(BlueprintCallable)
	virtual bool SetGoal(FHitResult goal);

	UFUNCTION(BlueprintCallable)
	uint8 GetCost();

	UFUNCTION(BlueprintCallable)
	float GetRange();

	UFUNCTION(BlueprintCallable)
	bool isEffectOnOpponent(int opponentLife, int opponentMaxLife, FGameplayTag opponentTeam, FGameplayTag ownerTeam);
};
