// Fill out your copyright notice in the Description page of Project Settings.

#include "InRange.h"
#include "UtilityAI.h"

bool UInRange::ExpressionValue_Implementation(const TScriptInterface<IAgent>& Agent)
{
	if (ArgsNum() < 2)
	{
		UE_LOG(UtilityAI_Operations, Error, TEXT("Operation %s hasn't enought arguments passed. Passes: %d, required: %d"), *GetName(), ArgsNum(), 2);
		return false;
	}
	const auto Lower = NthArg(0);
	const auto Upper = NthArg(1);
	const auto Results = OperandsResults(Agent);
	auto Count = 0;
	for (const auto Value : Results)
	{
		if (Value)
		{
			++Count;
		}
	}
	return Lower <= Count && Count < Upper;
}
