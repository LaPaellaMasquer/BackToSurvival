// Fill out your copyright notice in the Description page of Project Settings.


#include "AOEActionComponent.h"

void UAOEActionComponent::BeginPlay()
{
	Super::BeginPlay();

	dataAOE = Cast<UAOEActionDataAsset>(actionStats);
}

bool UAOEActionComponent::SetGoal(FHitResult goal)
{
	bool res = FVector3d::Distance(goal.Location, GetOwner()->GetActorLocation()) <= dataAOE->action_range + dataAOE->actionRadius;

	if (res) {
		FHitResult obstacle;

		FCollisionShape MySphere = FCollisionShape::MakeSphere(dataAOE->actionRadius);
		TArray<FHitResult> OutResults;
		res = GetWorld()->SweepMultiByChannel(OutResults, goal.Location, goal.Location, FQuat::Identity, ECC_WorldStatic, MySphere);
		if (res) {
			targets.Empty();

			for (int i = 0; i < OutResults.Num(); i++)
			{
				if (OutResults[i].GetActor() != GetOwner() && OutResults[i].GetActor()->GetClass()->IsChildOf(ACharacterPawn::StaticClass())) 
				{
					ACharacterPawn* hitCharacter = Cast<ACharacterPawn>(OutResults[i].GetActor());
					if (isEffectOnOpponent(hitCharacter->lifeManager->GetPv(), hitCharacter->lifeManager->GetMaxPv(), hitCharacter->tag, ownerCharacter->tag)) 
					{
						targets.Add(hitCharacter);
					}
				}
			}

			targetLocation = goal.Location;

			res = targets.Num() != 0;
		}
	}
	return res;
}

void UAOEActionComponent::ApplyAction(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	for (int i = 0; i < targets.Num(); i++) {
		targets[i]->lifeManager->Hit(actionStats->effect_Pv);
		int oldRange = targets[i]->moveManager->GetOrangeRange();
		targets[i]->moveManager->SetOrangeRange(oldRange - oldRange * actionStats->effect_Movement_Percent);
	}
	OverlappedComponent->GetOwner()->Destroy();
}

int UAOEActionComponent::Action()
{
	FActorSpawnParameters spawnParams;
	spawnParams.Owner = GetOwner();
	FRotator rotator;
	AProjectile* projectile;

	projectile = GetWorld()->SpawnActor<AProjectile>(projectileToSpawn, ownerMesh->GetSocketLocation(socketProjectileSpawnName), rotator, spawnParams);
	projectile->SetGoal(targetLocation);
	projectile->collider->OnComponentBeginOverlap.AddDynamic(this, &UAOEActionComponent::ApplyAction);
	
	return actionStats->cost_pa;
}

float UAOEActionComponent::GetRadiusEffect()
{
	return dataAOE->actionRadius;
}

