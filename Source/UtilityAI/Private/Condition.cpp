// Fill out your copyright notice in the Description page of Project Settings.

#include "Condition.h"
#include "Agent.h"
#include "Predicate.h"

float FCondition::Evaluate(const TScriptInterface<IAgent>& Agent) const
{
	return Predicate && Predicate->Evaluate(Agent) ? SuccessValue : FailureValue;
}
