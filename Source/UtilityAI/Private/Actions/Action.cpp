// Fill out your copyright notice in the Description page of Project Settings.

#include "Action.h"
#include "Agent.h"
#include "Condition.h"
#include "UtilityAIConstants.h"
#include "UtilityAI.h"

UAction::UAction()
{
	BaseValue = UUtilityAIConstants::MinActionRating();
}

float UAction::Evaluate(const TScriptInterface<IAgent>& Agent)
{
	auto Result = UUtilityAIConstants::MinActionRating();
	for (auto& Condition : Conditions)
	{
		Result += Condition.Evaluate(Agent);
	}
	Result = FMath::Clamp(Result, UUtilityAIConstants::MinActionRating(), UUtilityAIConstants::MaxActionRating());
	return Result;
}

void UAction::Run_Implementation(const TScriptInterface<IAgent>& Agent) const
{
	UE_LOG(UtilityAI_Actions, Warning, TEXT("Action %s that has no overriden behavior has been run"), *GetName());
}

bool UAction::IgnoreIfCalledTwice() const
{
	return bIgnoreIfCalledTwice;
}
