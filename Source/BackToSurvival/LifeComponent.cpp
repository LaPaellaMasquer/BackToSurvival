// Fill out your copyright notice in the Description page of Project Settings.


#include "LifeComponent.h"

// Sets default values for this component's properties
ULifeComponent::ULifeComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void ULifeComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void ULifeComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void ULifeComponent::SetMaxPv(float max)
{
	pv_max = max;
	pv = max;
}

float ULifeComponent::GetPv()
{
	return pv;
}

float ULifeComponent::GetMaxPv()
{
	return pv_max;
}

void ULifeComponent::Hit(float effect)
{
	pv += effect;

	
	if (pv <= 0) {
		pv = 0;
		if (OnHit.IsBound()) OnHit.Broadcast();
		if(OnDeath.IsBound()) OnDeath.Broadcast();
		return;
	}

	if(OnHit.IsBound()) OnHit.Broadcast();
	if (pv > pv_max) {
		pv = pv_max;
	}


}

