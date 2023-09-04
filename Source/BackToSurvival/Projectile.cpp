// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	steerComp = CreateDefaultSubobject<USteerComponent>("Steer Component");
	AddOwnedComponent(steerComp);
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();

	steerComp->mass = projectilePhysic->mass;
	steerComp->max_force = projectilePhysic->max_force;
	steerComp->max_speed = projectilePhysic->max_speed;

}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SetActorLocation(steerComp->Seek(GetActorLocation(), target));
}

// Called to bind functionality to input
void AProjectile::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	//Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AProjectile::SetGoal(FVector goal)
{
	target = goal;
}

