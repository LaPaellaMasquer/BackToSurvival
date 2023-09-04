// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionComponentBase.h"

// Sets default values for this component's properties
UActionComponentBase::UActionComponentBase()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UActionComponentBase::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UActionComponentBase::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

int UActionComponentBase::Action()
{
	unimplemented();
	return -1;
}

bool UActionComponentBase::SetGoal(FHitResult goal)
{
	unimplemented();
	return false;
}

uint8 UActionComponentBase::GetCost()
{
	return actionStats->cost_pa;
}

float UActionComponentBase::GetRange()
{
	return actionStats->action_range;
}

bool UActionComponentBase::isEffectOnOpponent(int opponentLife, int opponentMaxLife, FGameplayTag opponentTeam, FGameplayTag ownerTeam)
{
	return opponentLife > 0 && ((actionStats->effect_Pv > 0 && opponentTeam == ownerTeam && opponentLife < opponentMaxLife) || (actionStats->effect_Pv <= 0 && opponentTeam != ownerTeam));
}

