// Fill out your copyright notice in the Description page of Project Settings.

#include "Value.h"
#include "Agent.h"

float UValue::Evaluate(const TScriptInterface<IAgent>& Agent)
{
	const auto Value = Multiplier * GetValue(Agent);
	OnEvaluated.Broadcast(GetName(), Value);
	return Value;
}

float UValue::GetValue_Implementation(const TScriptInterface<IAgent>& Agent)
{
	return 0.f;
}
