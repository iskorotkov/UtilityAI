// Fill out your copyright notice in the Description page of Project Settings.

#include "And.h"

bool UAnd::ExpressionValue_Implementation(const TScriptInterface<IAgent>& Agent)
{
	return FirstResult(Agent) && SecondResult(Agent);
}
