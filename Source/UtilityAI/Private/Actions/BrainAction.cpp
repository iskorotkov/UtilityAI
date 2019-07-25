// Fill out your copyright notice in the Description page of Project Settings.

#include "BrainAction.h"
#include "UtilityAI.h"
#include "BrainAsset.h"

void UBrainAction::Run_Implementation(const TScriptInterface<IAgent>& Agent) const
{
	Super::Run(Agent);
	if (Brain == nullptr)
	{
		UE_LOG(UtilityAI_Actions, Warning, TEXT("Action %s has no associated brain asset"), *GetName());
		return;
	}
	if (const auto Action = Brain->SelectAction(Agent))
	{
		Action->Run(Agent);
	}
}

UBrainAsset* UBrainAction::GetBrain()
{
	return Brain;
}
