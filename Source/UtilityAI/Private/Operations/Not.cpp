// Fill out your copyright notice in the Description page of Project Settings.

#include "Not.h"

bool UNot::ExpressionValue_Implementation(const TScriptInterface<IAgent>& Agent)
{
	return !FirstResult(Agent);
}
