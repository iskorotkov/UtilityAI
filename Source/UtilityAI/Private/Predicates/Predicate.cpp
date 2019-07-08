// Fill out your copyright notice in the Description page of Project Settings.

#include "Predicate.h"

bool UPredicate::Evaluate_Implementation(const TScriptInterface<IAgent>& Agent)
{
	const auto Value = Super::Evaluate(Agent);
	// TODO: temporary code
	OnEvaluated.Broadcast(GetName(), false);
	return Value;
}

void UPredicate::GetPredicatesRecursively(FPredicatesContainerRef Predicates)
{
	Predicates.Add(this);
}
