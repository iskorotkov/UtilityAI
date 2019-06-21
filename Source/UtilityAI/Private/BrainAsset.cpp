// Fill out your copyright notice in the Description page of Project Settings.

#include "BrainAsset.h"
#include "Action.h"

UAction* UBrainAsset::SelectAction_Implementation() const
{
	UAction* Action = nullptr;
	// TODO: magic number (introduce UtilityAIConstants class)
	auto Value = 0.f;
	for (const auto A : Actions)
	{
		check(A);
		const auto V = A->Evaluate();
		if (V > Value)
		{
			Value = V;
			Action = A;
		}
	}
	return Action;
}
