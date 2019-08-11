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

void UAction::Execute(const TScriptInterface<IAgent>& Agent)
{
	OnRun.Broadcast(GetName());
	Run(Agent);
}

float UAction::Evaluate(const TScriptInterface<IAgent>& Agent)
{
	auto Result = BaseValue;
	for (auto& Condition : Conditions)
	{
		Result += Condition.Evaluate(Agent, this);
	}
	InstantiateValueClasses();
	for (auto Value : Values)
	{
		check(Value.IsValid());
		Result += Value->Evaluate(Agent);
	}
	Result = FMath::Clamp(Result, UUtilityAIConstants::MinActionRating(), UUtilityAIConstants::MaxActionRating());
	OnEvaluated.Broadcast(GetName(), Result);
	return Result;
}

void UAction::Run_Implementation(const TScriptInterface<IAgent>& Agent)
{
}

bool UAction::IgnoreIfCalledTwice() const
{
	return bIgnoreIfCalledTwice;
}

const TArray<FCondition>& UAction::GetConditions() const
{
	return Conditions;
}

// TODO: Return by const ref
TArray<UValue*> UAction::GetValues() const
{
	TArray<UValue*> Results;
	for (const auto ValuePtr : Values)
	{
		Results.Add(ValuePtr.Get());
	}
	return Results;
}

void UAction::InstantiateValueClasses()
{
	if (Values.Num() > 0)
	{
		return;
	}
	for (const auto ValueClass : ValueClasses)
	{
		Values.Emplace(NewObject<UValue>(this, ValueClass));
	}
}
