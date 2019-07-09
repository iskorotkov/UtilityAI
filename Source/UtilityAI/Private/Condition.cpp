// Fill out your copyright notice in the Description page of Project Settings.

#include "Condition.h"
#include "Agent.h"
#include "Predicate.h"
#include "SubclassOf.h"

void FCondition::EnsurePredicateIsCreated(const TScriptInterface<IAgent>& Agent) const
{
	if (Predicate == nullptr)
	{
		Predicate = NewObject<UPredicate>(Agent.GetObject(), PredicateClass);
	}
}

float FCondition::Evaluate(const TScriptInterface<IAgent>& Agent)
{
	EnsurePredicateIsCreated(Agent);
	return Predicate && Predicate->Evaluate(Agent) ? SuccessValue : FailureValue;
}

FString FCondition::GetName() const
{
	return Name;
}

UPredicate* FCondition::GetPredicate(const TScriptInterface<IAgent>& Agent) const
{
	EnsurePredicateIsCreated(Agent);
	return Predicate;
}
