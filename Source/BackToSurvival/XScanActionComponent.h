// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CharacterPawn.h"
#include "ActionComponentBase.h"
#include "XScanActionComponent.generated.h"


UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BACKTOSURVIVAL_API UXScanActionComponent : public UActionComponentBase
{
	GENERATED_BODY()

protected:
	ACharacterPawn* targetCharacter;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkeletalMeshComponent* ownerMesh;

	UPROPERTY(EditAnywhere)
	FName socketHeadName;

	ACharacterPawn* ownerCharacter;

	// Sets default values for this component's properties
	UXScanActionComponent();

protected:

	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	bool SetGoal(FHitResult goal) override;

	int Action() override;
};
