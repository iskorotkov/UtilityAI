// Fill out your copyright notice in the Description page of Project Settings.

#include "BrainAsset.h"
#include "Action.h"
#include "SubclassOf.h"
#include "UtilityAIConstants.h"

bool UBrainAsset::ShouldSkipOtherActions(const float Value) const
{
	if (bHasSkipOtherActionsValue && Value > SkipOtherActionsValue)
	{
		return true;
	}
	return false;
}

bool UBrainAsset::ShouldSkipRepeatingAction(UAction* Action) const
{
	return Action == LastAction
	&& Action
	&& Action->IgnoreIfCalledTwice();
}

bool UBrainAsset::ShouldSkipLowRankedAction(const float Value) const
{
	return bHasMinValueToAct && MinValueToAct > Value;
}

UAction* UBrainAsset::SelectAction(const TScriptInterface<IAgent>& Agent)
{
	UAction* BestAction = nullptr;
	auto BestValue = UUtilityAIConstants::AbsoluteMin();
	CreateActions(Agent);
	for (const auto Action : Actions)
	{
		check(Action);
		const auto Value = Action->Evaluate(Agent);
		if (Value > BestValue)
		{
			BestValue = Value;
			BestAction = Action;
			if (ShouldSkipOtherActions(BestValue))
			{
				break;
			}
		}
	}
	if (ShouldSkipRepeatingAction(BestAction))
	{
		return nullptr;
	}
	if (ShouldSkipLowRankedAction(BestValue))
	{
		LastAction = nullptr;
		return nullptr;
	}
	LastAction = BestAction;
	return BestAction;
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
