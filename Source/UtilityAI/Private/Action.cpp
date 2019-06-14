// Fill out your copyright notice in the Description page of Project Settings.

#include "Action.h"
#include "Agent.h"

float UAction::Evaluate() const
{
	return 0.f;
}

void UAction::Run(TScriptInterface<IAgent> Agent) const
{
	Agent->RunBehavior(Behavior);
}
