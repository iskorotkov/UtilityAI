// Fill out your copyright notice in the Description page of Project Settings.

#include "Predicate.h"

bool UPredicate::Evaluate_Implementation(const TScriptInterface<IAgent>& Agent)
{
	Super::Evaluate(Agent);
	// TODO: temporary code
	OnEvaluated.Broadcast(GetName(), false);
}

TSet<UPredicate*> UPredicate::GetPredicatesRecursively_Implementation() const
{
	TSet<UPredicate*> Predicates;
	Predicates.Emplace(this);
	return Predicates;
}
