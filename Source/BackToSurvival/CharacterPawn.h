// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "StatsDataAsset.h"
#include "ActionComponentBase.h"
#include "LifeComponent.h"
#include "PAComponent.h"
#include "MoveComponent.h"
#include "GameplayTagContainer.h"
#include "EnnemyAIController.h"
#include "CharacterPawn.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCharacterHitSignature, class ACharacterPawn*, characterHit);

UCLASS(Blueprintable)
class BACKTOSURVIVAL_API ACharacterPawn : public ACharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayTag tag;

	UPROPERTY(EditAnywhere)
	UStatsDataAsset* stats;

	UPROPERTY(EditAnywhere)
	ULifeComponent* lifeManager;

	UPROPERTY(EditAnywhere)
	UPAComponent* paManager;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UActionComponentBase* action1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UActionComponentBase* action2;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UMoveComponent* moveManager;

	UPROPERTY(BlueprintReadWrite)
	bool actionUsed;

	UPROPERTY(BlueprintReadWrite)
	bool moveUsed;

	UPROPERTY(BlueprintAssignable)
	FOnCharacterHitSignature OnCharacterHit;

	// Sets default values for this pawn's properties
	ACharacterPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	ULifeComponent* GetLife();

	UFUNCTION(BlueprintCallable)
	UPAComponent* GetPA();

	UFUNCTION(BlueprintCallable)
	UMoveComponent* GetMovement();

	UFUNCTION()
	void SendOncharacterHit();


};
