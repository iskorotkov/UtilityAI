// Fill out your copyright notice in the Description page of Project Settings.

#include "Action.h"
#include "Agent.h"
#include "Condition.h"
#include "UtilityAIConstants.h"
#include "Value.h"

UAction::UAction()
{
	BaseValue = UUtilityAIConstants::MinActionRating();
}

float UAction::Evaluate(const TScriptInterface<IAgent>& Agent)
{
	auto Result = UUtilityAIConstants::MinActionRating();
	for (auto& Condition : Conditions)
	{
		Result += Condition.Evaluate(Agent, this);
	}
	InstantiateValueClasses();
	for (auto Value : Values)
	{
		Result += Value->Evaluate(Agent);
	}
	Result = FMath::Clamp(Result, UUtilityAIConstants::MinActionRating(), UUtilityAIConstants::MaxActionRating());
	OnEvaluated.Broadcast(GetName(), Result);
	return Result;
}

void UAction::Run_Implementation(const TScriptInterface<IAgent>& Agent)
{
	OnRun.Broadcast(GetName());
}

bool UAction::IgnoreIfCalledTwice() const
{
	return bIgnoreIfCalledTwice;
}

const TArray<FCondition>& UAction::GetConditions() const
{
	return Conditions;
}

void UAction::InstantiateValueClasses()
{
	for (const auto ValueClass : ValueClasses)
	{
		Values.Add(NewObject<UValue>(this, ValueClass));
	}
}
