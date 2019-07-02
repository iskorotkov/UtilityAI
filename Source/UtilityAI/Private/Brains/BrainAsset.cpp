// Fill out your copyright notice in the Description page of Project Settings.

#include "BrainAsset.h"
#include "Action.h"
#include "SubclassOf.h"

UAction* UBrainAsset::SelectAction_Implementation(const TScriptInterface<IAgent>& Agent)
{
	UAction* Action = nullptr;
	// TODO: magic number (introduce UtilityAIConstants class)
	auto Value = -1.f;
	CreateActions(Agent);
	for (const auto A : Actions)
	{
		check(A);
		const auto V = A->Evaluate(Agent);
		if (V > Value)
		{
			Value = V;
			Action = A;
		}
	}
	if (Action == LastAction 
		&& Action 
		&& Action->IgnoreIfCalledTwice())
	{
		return nullptr;
	}
	LastAction = Action;
	return Action;
}

void UBrainAsset::CreateActions(const TScriptInterface<IAgent>& Agent)
{
	if (ActionClasses.Num() > Actions.Num())
	{
		for (const auto& Class : ActionClasses)
		{
			Actions.Add(NewObject<UAction>(Agent.GetObject(), Class));
		}
	}
}
