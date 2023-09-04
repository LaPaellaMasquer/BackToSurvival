// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SteerComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BACKTOSURVIVAL_API USteerComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	FVector velocity;

	FVector Truncate(FVector v, float m);

	FVector Compute(FVector pos, FVector velocity);

public:
	UPROPERTY(EditAnywhere)
	float mass;

	UPROPERTY(EditAnywhere)
	float max_force;
	
	UPROPERTY(EditAnywhere)
	float max_speed;

	// Sets default values for this component's properties
	USteerComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	FVector Seek(const FVector& position, const FVector& target);

	UFUNCTION(BlueprintCallable)
	FVector Flee(const FVector& position, const FVector& target);

	UFUNCTION(BlueprintCallable)
	FVector Pursuit(const FVector& position, const FVector& target, const FVector& velocity_target);

	UFUNCTION(BlueprintCallable)
	FVector Evasion(const FVector& position, const FVector& target, const FVector& velocity_target);

	UFUNCTION(BlueprintCallable)
	FVector Arrival(const FVector& position, const double slowing_d, const FVector& target);

	UFUNCTION(BlueprintCallable)
	inline FVector GetVelocity() const;
};
