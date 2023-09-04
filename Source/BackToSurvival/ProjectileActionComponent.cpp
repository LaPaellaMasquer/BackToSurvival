// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileActionComponent.h"

// Sets default values for this component's properties
UProjectileActionComponent::UProjectileActionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UProjectileActionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UProjectileActionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

int UProjectileActionComponent::Action()
{
	FActorSpawnParameters spawnParams;
	spawnParams.Owner = GetOwner();
	FRotator rotator;
	AProjectile* projectile = GetWorld()->SpawnActor<AProjectile>(projectileToSpawn, ownerMesh->GetSocketLocation(socketProjectileSpawnName), rotator, spawnParams);
	projectile->SetGoal(targetCharacter->GetActorLocation());
	projectile->collider->OnComponentBeginOverlap.AddDynamic(this, &UProjectileActionComponent::ApplyAction);
	
	return actionStats->cost_pa;
}

void UProjectileActionComponent::ApplyAction(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::Action();
	OverlappedComponent->GetOwner()->Destroy();
}

