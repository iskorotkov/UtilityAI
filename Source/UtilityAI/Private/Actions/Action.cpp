// Fill out your copyright notice in the Description page of Project Settings.

#include "Action.h"
#include "Agent.h"
#include "Condition.h"
#include "UtilityAIConstants.h"

UAction::UAction()
{
	BaseValue = UUtilityAIConstants::MinActionRating();
}

float UAction::Evaluate(const TScriptInterface<IAgent>& Agent)
{
	auto Result = UUtilityAIConstants::MinActionRating();
	for (auto& Condition : Conditions)
	{
		const auto Value = Condition.Evaluate(Agent);
		OnConditionEvaluated.Broadcast(Condition.GetName(), Value);
		Result += Value;
	}
	Result = FMath::Clamp(Result, UUtilityAIConstants::MinActionRating(), UUtilityAIConstants::MaxActionRating());
	OnEvaluated.Broadcast(GetName(), Result);
	return Result;
}

void UAction::Run_Implementation(const TScriptInterface<IAgent>& Agent) const
{
	OnRun.Broadcast(GetName());
}

bool UAction::IgnoreIfCalledTwice() const
{
	return bIgnoreIfCalledTwice;
}
