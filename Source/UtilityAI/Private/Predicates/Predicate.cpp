// Fill out your copyright notice in the Description page of Project Settings.

#include "Predicate.h"
#include "UtilityAI.h"

bool UPredicate::ExpressionValue_Implementation(const TScriptInterface<IAgent>& Agent)
{
	// TODO: method that could be accidentally overriden
	return false;
}

bool UPredicate::Evaluate(const TScriptInterface<IAgent>& Agent)
{
	const auto Value = Super::Evaluate(Agent);
	OnEvaluated.Broadcast(GetName(), Value);
	return Value;
}

void UPredicate::GetPredicatesRecursively(FPredicatesContainerRef Predicates)
{
	Predicates.Add(this);
}
