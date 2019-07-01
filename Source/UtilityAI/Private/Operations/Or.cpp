// Fill out your copyright notice in the Description page of Project Settings.

#include "Or.h"

bool UOr::Evaluate_Implementation(const TScriptInterface<IAgent>& Agent)
{
	return FirstResult(Agent) || SecondResult(Agent);
}
