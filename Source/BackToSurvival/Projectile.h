// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/ShapeComponent.h"
#include "SteerComponent.h"
#include "ProjectileDataAsset.h"
#include "Projectile.generated.h"



UCLASS()
class BACKTOSURVIVAL_API AProjectile : public APawn
{
	GENERATED_BODY()
	
private:
	FVector target;

public:
	UPROPERTY(EditAnywhere)
	UProjectileDataAsset* projectilePhysic;

	UPROPERTY(EditAnywhere)
	USteerComponent* steerComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* collider;

	// Sets default values for this pawn's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void SetGoal(FVector goal);
};
