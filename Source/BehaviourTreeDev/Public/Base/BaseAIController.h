// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

//BehaviorTree
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"

//Perception
#include "Perception/AISenseConfig.h"
#include "Perception/AISense_Sight.h"
#include "Perception/AIPerceptionComponent.h"

#include "AIController.h"
#include "BaseAIController.generated.h"

/**
 * 
 * AI Controller:
 * Contains:
 * - Behavior Tree data (BT, BB and keys)
 * - Perception data 
 * 
 */
UCLASS()
class BEHAVIOURTREEDEV_API ABaseAIController : public AAIController
{
	GENERATED_BODY()

/* Attributes */
public:

	/* Blackboard data */
	UPROPERTY(EditDefaultsOnly, Category = "AI | BehaviorTree")
	UBlackboardData *BlackboardToUse;

	UPROPERTY(EditDefaultsOnly, Category = "AI | BehaviorTree")
	UBehaviorTree *BehaviorTreeToUse;

	UPROPERTY()
	UBlackboardComponent *BlackboardComp;

	/* Perception */

	UPROPERTY(VisibleAnywhere, Category = "AI | Perception")
	UAIPerceptionComponent *AIPerception;

	UPROPERTY(EditDefaultsOnly, Category = "AI | Perception")
	TSubclassOf<UAISense> HearingSense;

	UPROPERTY(EditDefaultsOnly, Category = "AI | Perception")
	TSubclassOf<UAISense> SightSense;

	/* Blackboard keys */

/* Methods */
public:

	ABaseAIController();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	virtual void Possess(APawn *Pawn) override;

	/* Perception */
	UFUNCTION()
	void SenseStuff(AActor *UpdatedActor, FAIStimulus Stimulus);
};
