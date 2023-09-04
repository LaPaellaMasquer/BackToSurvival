// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ActionDataAsset.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class BACKTOSURVIVAL_API UActionDataAsset : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	uint8 cost_pa;

	UPROPERTY(EditAnywhere)
	float effect_Pv;

	UPROPERTY(EditAnywhere)
	float effect_Movement_Percent;

	UPROPERTY(EditAnywhere)
	float action_range;
};
