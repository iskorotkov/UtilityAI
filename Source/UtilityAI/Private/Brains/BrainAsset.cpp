// Fill out your copyright notice in the Description page of Project Settings.

#include "BrainAsset.h"
#include "Action.h"
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

bool UBrainAsset::ShouldCreateActions() const
{
	return Actions.Num() == 0;
}

UAction* UBrainAsset::GetBestEvaluatedAction(const TScriptInterface<IAgent>& Agent)
{
	UAction* BestAction = nullptr;
	auto BestValue = UUtilityAIConstants::AbsoluteMin();
	for (const auto Action : Actions)
	{
		check(Action);
		const auto Value = Action->Evaluate(Agent);
		OnActionRanked.Broadcast(Action->GetName(), Value);
		if (Value > BestValue)
		{
			BestValue = Value;
			BestAction = Action;
			if (ShouldSkipOtherActions(BestValue))
			{
				OnOtherActionsSkipped.Broadcast(BestAction->GetName(), Value);
				break;
			}
		}
	}
	if (BestAction)
	{
		OnActionSelected.Broadcast(BestAction->GetName(), BestValue);
		if (ShouldSkipRepeatingAction(BestAction))
		{
			OnRepeatingActionSkipped.Broadcast(BestAction->GetName(), BestValue);
			return nullptr;
		}
		if (ShouldSkipLowRankedAction(BestValue))
		{
			OnLowRankedActionSkipped.Broadcast(BestAction->GetName(), BestValue);
			LastAction = nullptr;
			return nullptr;
		}
	}
	else
	{
		// TODO: remove constants
		OnActionSelected.Broadcast("None", 0.f);
	}
	LastAction = BestAction;
	return BestAction;
}

UAction* UBrainAsset::SelectAction(const TScriptInterface<IAgent>& Agent)
{
	if (ShouldCreateActions())
	{
		CreateActions();
	}
	ExecutePreActions(Agent);
	const auto BestAction = GetBestEvaluatedAction(Agent);
	ExecutePostActions(Agent);
	return BestAction;
}

void UBrainAsset::CreateActions()
{
	for (const auto& Class : ActionClasses)
	{
		Actions.Add(NewObject<UAction>(this, Class));
	}
	for (const auto& Class : PreActionClasses)
	{
		PreActions.Add(NewObject<UAction>(this, Class));
	}
	for (const auto& Class : PostActionClasses)
	{
		PostActions.Add(NewObject<UAction>(this, Class));
	}
}

void UBrainAsset::ExecutePreActions(const TScriptInterface<IAgent>& Agent) const
{
	for (const auto Action : PreActions)
	{
		Action->Run(Agent);
	}
}

void UBrainAsset::ExecutePostActions(const TScriptInterface<IAgent>& Agent) const
{
	for (const auto Action : PostActions)
	{
		Action->Run(Agent);
	}
}

const TArray<UAction*>& UBrainAsset::GetActions()
{
	if (ShouldCreateActions())
	{
		CreateActions();
	}
	return Actions;
}
