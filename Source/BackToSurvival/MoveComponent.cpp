// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveComponent.h"

UMoveComponent::UMoveComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UMoveComponent::BeginPlay()
{
	Super::BeginPlay();

	navSys = UNavigationSystemV1::GetCurrent(GetWorld());
	// ...
}

void UMoveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UMoveComponent::SetMaxRange(float newRange)
{
	max_range = newRange;
	SetOrangeRange(max_range);
}

void UMoveComponent::ResetOrangeRange()
{
	SetOrangeRange(max_range);
}


void UMoveComponent::SetOrangeRange(float newRange)
{
	orange_range = newRange;
	blue_range = orange_range - (orange_range * orange_surface_percent);
}

float UMoveComponent::GetOrangeRange()
{
	return orange_range;
}

float UMoveComponent::GetBlueRange()
{
	return blue_range;
}

int UMoveComponent::CostMoveTo(FVector location)
{
	float pathLength;
	navSys->GetPathLength(GetOwner()->GetActorLocation(), location, pathLength);
	
	if (pathLength <= MIN_DIST) {
		return 0;
	}

	if (pathLength <= blue_range) {
		return 1;
	}
	
	if (pathLength <= orange_range) {
		return 2;
	}

	return 0;
}
