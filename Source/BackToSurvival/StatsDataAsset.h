// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "StatsDataAsset.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class BACKTOSURVIVAL_API UStatsDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
	float max_pv;

	UPROPERTY(EditAnywhere)
	int max_pa = 2;

	UPROPERTY(EditAnywhere)
	int max_radius;

};
