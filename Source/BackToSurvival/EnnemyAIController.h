// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AIPerceptionTypes.h"
#include "EnnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class BACKTOSURVIVAL_API AEnnemyAIController : public AAIController
{
	GENERATED_BODY()

private:

public:
	UPROPERTY(EditAnywhere)
	UAIPerceptionComponent* perception;
	
	UPROPERTY(EditAnywhere)
	UAISenseConfig_Sight* sight;

	AEnnemyAIController();

	UFUNCTION(BlueprintCallable)
	TArray<AActor*> GetActorsInSightRadius(float radius);
};
