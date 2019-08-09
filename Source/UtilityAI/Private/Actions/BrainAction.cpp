// Fill out your copyright notice in the Description page of Project Settings.

#include "BrainAction.h"
#include "UtilityAI.h"
#include "BrainAsset.h"

void UBrainAction::Run_Implementation(const TScriptInterface<IAgent>& Agent)
{
	Super::Run_Implementation(Agent);
	if (!BrainClass)
	{
		UE_LOG(UtilityAI_Actions, Warning, TEXT("Action %s has no associated brain asset"), *GetName());
		return;
	}
	if (const auto Action = GetBrain()->SelectAction(Agent))
	{
		Action->Execute(Agent);
	}
}

UBrainAsset* UBrainAction::GetBrain()
{
	if (!Brain)
	{
		Brain = NewObject<UBrainAsset>(this, BrainClass);
		check(Brain);
	}
	return Brain;
}
