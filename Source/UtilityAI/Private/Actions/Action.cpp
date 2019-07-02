// Fill out your copyright notice in the Description page of Project Settings.

#include "Action.h"
#include "Agent.h"
#include "Condition.h"
#include "UtilityAIConstants.h"

float UAction::Evaluate(const TScriptInterface<IAgent>& Agent)
{
	auto Result = UUtilityAIConstants::MinActionRating();
	for (auto& Condition : Conditions)
	{
		Result += Condition.Evaluate(Agent);
	}
	return FMath::Clamp(Result, UUtilityAIConstants::MinActionRating(), UUtilityAIConstants::MaxActionRating());
}

void UAction::Run_Implementation(const TScriptInterface<IAgent>& Agent) const
{
}

bool UAction::IgnoreIfCalledTwice() const
{
	return bIgnoreIfCalledTwice;
}
