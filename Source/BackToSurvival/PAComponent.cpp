// Fill out your copyright notice in the Description page of Project Settings.


#include "PAComponent.h"

// Sets default values for this component's properties
UPAComponent::UPAComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPAComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPAComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UPAComponent::SetMaxPA(int pa)
{
	max_pa = pa;
}

bool UPAComponent::HasEnoughPA(uint8 actionCost)
{
	return actionCost <= current_pa;
}

uint8 UPAComponent::GetCurrentPA()
{
	return current_pa;
}

void UPAComponent::RefillPA()
{
	current_pa = max_pa;
}

bool UPAComponent::DecreasePA(int PA)
{
	current_pa -= PA;
	if (current_pa < 0) {
		current_pa = 0;
		return false;
	}
	else {
		return true;
	}
}

