// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActionDataAsset.h"
#include "AOEActionDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class BACKTOSURVIVAL_API UAOEActionDataAsset : public UActionDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	float actionRadius;
	
};
