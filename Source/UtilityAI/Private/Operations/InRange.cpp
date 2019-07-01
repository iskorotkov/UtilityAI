// Fill out your copyright notice in the Description page of Project Settings.

#include "InRange.h"

bool UInRange::Evaluate_Implementation(const TScriptInterface<IAgent>& Agent)
{
	if (ArgsNum() < 2)
	{
		// TODO: log error - not enough arguments passed
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
