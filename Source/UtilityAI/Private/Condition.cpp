// Fill out your copyright notice in the Description page of Project Settings.

#include "Condition.h"
#include "Agent.h"
#include "Predicate.h"
#include "SubclassOf.h"

float FCondition::Evaluate(const TScriptInterface<IAgent>& Agent)
{
	if (Predicate == nullptr)
	{
		Predicate = NewObject<UPredicate>(Agent.GetObject(), PredicateClass);
	}
	return Predicate && Predicate->Evaluate(Agent) ? SuccessValue : FailureValue;
}

FString FCondition::GetName() const
{
	return Name;
}

UPredicate* FCondition::GetPredicate() const
{
	return Predicate;
}
