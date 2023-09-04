// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LifeComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeathSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHitSignature);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BACKTOSURVIVAL_API ULifeComponent : public UActorComponent
{
	GENERATED_BODY()

private :
	float pv_max;
	float pv;

public:	
	UPROPERTY(BlueprintAssignable)
	FOnDeathSignature OnDeath;

	UPROPERTY(BlueprintAssignable)
	FOnHitSignature OnHit;

	// Sets default values for this component's properties
	ULifeComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void SetMaxPv(float max);

	UFUNCTION(BlueprintCallable)
	float GetPv();

	UFUNCTION(BlueprintCallable)
	float GetMaxPv();

	UFUNCTION(BlueprintCallable)
	void Hit(float effect);
};
