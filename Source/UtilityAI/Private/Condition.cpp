// Fill out your copyright notice in the Description page of Project Settings.

#include "Condition.h"
#include "Agent.h"
#include "Predicate.h"

UObject* FCondition::GetPredicateOuter() const
{
	return Cast<UObject>(GetTransientPackage());
}

void FCondition::EnsurePredicateIsCreated() const
{
	if (Predicate == nullptr)
	{
		Predicate = NewObject<UPredicate>(GetPredicateOuter(), PredicateClass);
	}
}

float FCondition::Evaluate(const TScriptInterface<IAgent>& Agent)
{
	EnsurePredicateIsCreated();
	return Predicate && Predicate->Evaluate(Agent) ? SuccessValue : FailureValue;
}

FString FCondition::GetName() const
{
	return Name;
}

UPredicate* FCondition::GetPredicate() const
{
	EnsurePredicateIsCreated();
	return Predicate;
}
