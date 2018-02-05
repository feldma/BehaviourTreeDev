// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseAIController.h"

ABaseAIController::ABaseAIController()
{
	BehaviorTreeToUse = CreateDefaultSubobject<UBehaviorTree>(TEXT("BehaviorTree"));
	BlackboardToUse = CreateDefaultSubobject<UBlackboardData>(TEXT("BlackboardData"));
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));
}
