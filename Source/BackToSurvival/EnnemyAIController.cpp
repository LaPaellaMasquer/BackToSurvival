// Fill out your copyright notice in the Description page of Project Settings.


#include "EnnemyAIController.h"

AEnnemyAIController::AEnnemyAIController()
{
	sight = CreateDefaultSubobject<UAISenseConfig_Sight>("Sight");
	sight->PeripheralVisionAngleDegrees = 360;
	sight->DetectionByAffiliation.bDetectEnemies = 0;
	sight->DetectionByAffiliation.bDetectFriendlies = 0;
	sight->DetectionByAffiliation.bDetectNeutrals = 1;

	perception = CreateDefaultSubobject<UAIPerceptionComponent>("Perception");
	perception->ConfigureSense(*sight);
}

TArray<AActor*, FDefaultAllocator> AEnnemyAIController::GetActorsInSightRadius(float radius)
{
	perception->SetSenseEnabled(TSubclassOf<UAISense_Sight>(), false);
	sight->SightRadius = radius;
	sight->LoseSightRadius = radius + 0.1;
	perception->SetSenseEnabled(TSubclassOf<UAISense_Sight>(), true);
	perception->RequestStimuliListenerUpdate();

	TArray<AActor*> res;
	perception->GetCurrentlyPerceivedActors(TSubclassOf<UAISense_Sight>(), res);

	return res;
}
