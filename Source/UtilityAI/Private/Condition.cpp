// Fill out your copyright notice in the Description page of Project Settings.

#include "Condition.h"
#include "Agent.h"
#include "Predicate.h"

void FCondition::EnsurePredicateIsCreated(UObject* Outer)
{
	check(Outer);
	if (!Predicate.IsValid())
	{
		Predicate.Reset(NewObject<UPredicate>(Outer, PredicateClass));
	}
	check(Predicate.IsValid());
}

float FCondition::Evaluate(const TScriptInterface<IAgent>& Agent, UObject* OuterAction)
{
	EnsurePredicateIsCreated(OuterAction);
	return Predicate->Evaluate(Agent) ? SuccessValue : FailureValue;
}

FString FCondition::GetName() const
{
	return Name;
}

UPredicate* FCondition::GetPredicate(UObject* Outer)
{
	EnsurePredicateIsCreated(Outer);
	return Predicate.Get();
}

UPredicate* FCondition::GetPredicateIfCreated() const
{
	return Predicate.Get();
}
