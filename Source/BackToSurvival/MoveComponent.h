// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "NavigationSystem.h"
#include "MoveComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BACKTOSURVIVAL_API UMoveComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	const float MIN_DIST = 100;

	// the % of orange range surface
	const float orange_surface_percent = 0.30f;

	UNavigationSystemV1* navSys;

	// default max range
	float max_range;

	// current max range
	float orange_range;

	// current range which allow actions
	float blue_range;


public:
	UMoveComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// modify the default max range
	void SetMaxRange(float newRange);

	// reset orange range to default max range
	UFUNCTION(BlueprintCallable)
	void ResetOrangeRange();

	// modify the current ranges
	UFUNCTION(BlueprintCallable)
	void SetOrangeRange(float newRange);

	UFUNCTION(BlueprintCallable)
	float GetOrangeRange();

	UFUNCTION(BlueprintCallable)
	float GetBlueRange();

	//compute the cost to the location
	UFUNCTION(BlueprintCallable)
	int CostMoveTo(FVector location);
};
