// Fill out your copyright notice in the Description page of Project Settings.

#include "BrainAsset.h"
#include "Action.h"
#include "SubclassOf.h"
#include "UtilityAIConstants.h"
#include "UtilityAI.h"

bool UBrainAsset::ShouldSkipOtherActions(const float Value) const
{
	return bHasSkipOtherActionsValue && Value > SkipOtherActionsValue;
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

UAction* UBrainAsset::GetBestEvaluatedAction(const TScriptInterface<IAgent>& Agent)
{
	UAction* BestAction = nullptr;
	auto BestValue = UUtilityAIConstants::AbsoluteMin();
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

UAction* UBrainAsset::SelectAction(const TScriptInterface<IAgent>& Agent)
{
	CreateActions(Agent);
	ExecutePreActions(Agent);
	const auto BestAction = GetBestEvaluatedAction(Agent);
	ExecutePostActions(Agent);
	return BestAction;
}

void UBrainAsset::CreateActions(const TScriptInterface<IAgent>& Agent)
{
	if (Actions.Num() == 0)
	{
		for (const auto& Class : ActionClasses)
		{
			Actions.Add(NewObject<UAction>(Agent.GetObject(), Class));
		}
	}
	if (PreActions.Num() == 0)
	{
		for (const auto& Class : PreActionClasses)
		{
			PreActions.Add(NewObject<UAction>(Agent.GetObject(), Class));
		}
	}
	if (PostActions.Num() == 0)
	{
		for (const auto& Class : PostActionClasses)
		{
			PostActions.Add(NewObject<UAction>(Agent.GetObject(), Class));
		}
	}
}

void UBrainAsset::ExecutePreActions(const TScriptInterface<IAgent>& Agent)
{
	for (const auto Action : PreActions)
	{
		Action->Run(Agent);
	}
}

void UBrainAsset::ExecutePostActions(const TScriptInterface<IAgent>& Agent)
{
	for (const auto Action : PostActions)
	{
		Action->Run(Agent);
	}
}
