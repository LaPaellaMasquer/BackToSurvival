// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Projectile.h"
#include "XScanActionComponent.h"
#include "ProjectileActionComponent.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BACKTOSURVIVAL_API UProjectileActionComponent : public UXScanActionComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UProjectileActionComponent();

protected:
	UPROPERTY(EditAnywhere)
	TSubclassOf<AProjectile> projectileToSpawn;

	UPROPERTY(EditAnywhere)
	FName socketProjectileSpawnName;

	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	int Action() override;
	
	UFUNCTION()
	virtual void ApplyAction(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
