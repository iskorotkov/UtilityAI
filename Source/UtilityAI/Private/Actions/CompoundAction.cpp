// Fill out your copyright notice in the Description page of Project Settings.


#include "CompoundAction.h"

void UCompoundAction::Run_Implementation(const TScriptInterface<IAgent>& Agent)
{
	Super::Run_Implementation(Agent);
	PrepareActions();
	RunActions(Agent);
}

void UCompoundAction::PrepareActions()
{
	if (Actions.Num() > 0)
	{
		return;
	}
	for (const auto ActionClass : ActionsClasses)
	{
		Actions.Emplace(NewObject<UAction>(GetOuter(), ActionClass));
	}
}

void UCompoundAction::RunActions(const TScriptInterface<IAgent>& Agent)
{
	for (const auto Action : Actions)
	{
		check(Action.IsValid());
		Action->Run(Agent);
	}
}
