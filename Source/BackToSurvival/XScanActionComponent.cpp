// Fill out your copyright notice in the Description page of Project Settings.


#include "XScanActionComponent.h"

// Sets default values for this component's properties
UXScanActionComponent::UXScanActionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UXScanActionComponent::BeginPlay()
{
	Super::BeginPlay();
	verify((ownerCharacter = Cast<ACharacterPawn>(GetOwner())) != nullptr);

	// ...
	
}


// Called every frame
void UXScanActionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UXScanActionComponent::SetGoal(FHitResult goal)
{	
	bool res = goal.GetActor() && goal.GetActor()->GetClass()->IsChildOf(ACharacterPawn::StaticClass()) && FVector3d::Distance(goal.GetActor()->GetActorLocation(), GetOwner()->GetActorLocation()) < actionStats->action_range;

	if(res) {
		FHitResult obstacle;
		ownerMesh->GetSocketLocation(socketHeadName);
		res = GetWorld()->LineTraceSingleByChannel(obstacle, ownerMesh->GetSocketLocation(socketHeadName), goal.GetActor()->GetActorLocation(), ECC_PhysicsBody);
		if (res) {
			res = goal.GetActor() == obstacle.GetActor();
			if (res) {
				targetCharacter = Cast<ACharacterPawn>(obstacle.GetActor());
				res = isEffectOnOpponent(targetCharacter->lifeManager->GetPv(), targetCharacter->lifeManager->GetMaxPv(), targetCharacter->tag, ownerCharacter->tag);
			}
		}
	}

	return res;
}

int UXScanActionComponent::Action()
{
	targetCharacter->lifeManager->Hit(actionStats->effect_Pv);
	int oldRange = targetCharacter->moveManager->GetOrangeRange();
	targetCharacter->moveManager->SetOrangeRange(oldRange - oldRange * actionStats->effect_Movement_Percent);

	return actionStats->cost_pa;
}

