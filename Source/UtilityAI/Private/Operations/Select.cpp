// Fill out your copyright notice in the Description page of Project Settings.

#include "Select.h"

bool USelect::Evaluate_Implementation(const TScriptInterface<IAgent>& Agent)
{
	return FirstResult(Agent) ? SecondResult(Agent) : ThirdResult(Agent);
}
