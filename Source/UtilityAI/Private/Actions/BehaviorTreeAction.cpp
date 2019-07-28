// Fill out your copyright notice in the Description page of Project Settings.

#include "BehaviorTreeAction.h"
#include "Agent.h"

void UBehaviorTreeAction::Run_Implementation(const TScriptInterface<IAgent>& Agent)
{
	Agent->RunBehavior(Behavior);
}
