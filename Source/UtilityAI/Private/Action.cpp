// Fill out your copyright notice in the Description page of Project Settings.

#include "Action.h"
#include "Agent.h"
#include "Condition.h"

float UAction::Evaluate() const
{
	auto Result = 0.f;
	for (const auto& Condition : Conditions)
	{
		Result += Condition->Evaluate();
	}
	return FMath::Clamp(Result, 0.f, 1.f);
}

void UAction::Run(const TScriptInterface<IAgent>& Agent) const
{
	Agent->RunBehavior(Behavior);
}

void UAction::SetConditions(const TArray<UCondition*>& NewConditions)
{
	Conditions = NewConditions;
}

TArray<UCondition*> UAction::GetConditions_Implementation() const
{
	return TArray<UCondition*>();
}

void UAction::PostInitProperties()
{
	Super::PostInitProperties();
	if (Conditions.Num() == 0)
	{
		Conditions = GetConditions();
	}
}
