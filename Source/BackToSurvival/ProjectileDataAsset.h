// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ProjectileDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class BACKTOSURVIVAL_API UProjectileDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
	float mass;

	UPROPERTY(EditAnywhere)
	float max_force;

	UPROPERTY(EditAnywhere)
	float max_speed;
};
