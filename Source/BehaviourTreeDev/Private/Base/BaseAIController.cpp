// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseAIController.h"

ABaseAIController::ABaseAIController()
{
	BehaviorTreeToUse = CreateDefaultSubobject<UBehaviorTree>(TEXT("BehaviorTree"));
	BlackboardToUse = CreateDefaultSubobject<UBlackboardData>(TEXT("BlackboardData"));
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));
}

void ABaseAIController::BeginPlay()
{
	Super::BeginPlay();
	if (!ensure(BlackboardToUse))
		return;
	UseBlackboard(BlackboardToUse, BlackboardComp);

	if (!ensure(BehaviorTreeToUse))
		return;
	RunBehaviorTree(BehaviorTreeToUse);

	if (!ensure(AIPerception))
		return;
	AIPerception->OnTargetPerceptionUpdated.AddDynamic(this, &ABaseAIController::SenseStuff);
	TArray<AActor*> ActorsSensed;
	AIPerception->GetKnownPerceivedActors(HearingSense, ActorsSensed);
}

void ABaseAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void ABaseAIController::Possess(APawn *Pawn)
{
	Super::Possess(Pawn);

	if (Pawn)
	{
		BlackboardComp->InitializeBlackboard(*BehaviorTreeToUse->BlackboardAsset);

		/* Initialize blackboard keys and values */
	}
}

/* Perception */
void ABaseAIController::SenseStuff(AActor *UpdatedActor, FAIStimulus Stimulus)
{

}