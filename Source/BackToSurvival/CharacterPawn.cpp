// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterPawn.h"

// Sets default values
ACharacterPawn::ACharacterPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	lifeManager = CreateDefaultSubobject<ULifeComponent>("Life manager");
	AddOwnedComponent(lifeManager);

	paManager = CreateDefaultSubobject<UPAComponent>("PA manager");
	AddOwnedComponent(paManager);

	moveManager = CreateDefaultSubobject<UMoveComponent>("Move manager");
	AddOwnedComponent(moveManager);

	AIControllerClass = TSubclassOf<AEnnemyAIController>();
}

// Called when the game starts or when spawned
void ACharacterPawn::BeginPlay()
{
	Super::BeginPlay();

	lifeManager->SetMaxPv(stats->max_pv);

	paManager->SetMaxPA(stats->max_pa);
	paManager->RefillPA();

	moveManager->SetMaxRange(stats->max_radius);

	SpawnDefaultController();

	lifeManager->OnHit.AddUniqueDynamic(this, &ACharacterPawn::SendOncharacterHit);
}

void ACharacterPawn::SendOncharacterHit()
{
	if (OnCharacterHit.IsBound()) {
		OnCharacterHit.Broadcast(this);
	}
}

// Called every frame
void ACharacterPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACharacterPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UMoveComponent* ACharacterPawn::GetMovement()
{
	return moveManager;
}

ULifeComponent* ACharacterPawn::GetLife()
{
	return lifeManager;
}

UPAComponent* ACharacterPawn::GetPA()
{
	return paManager;
}

