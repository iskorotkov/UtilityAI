// Fill out your copyright notice in the Description page of Project Settings.

#include "UtilityAIBrainComponent.h"
#include "BrainAsset.h"
#include "Action.h"

UUtilityAIBrainComponent::UUtilityAIBrainComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UUtilityAIBrainComponent::Act_Implementation() const
{
	OnBeforeAct.Broadcast();
	const TScriptInterface<IAgent> Agent = GetOwner();
	if (const auto Action = Asset->SelectAction(Agent))
	{
		OnActionRun.Broadcast(Action->GetName());
		Action->Run(Agent);
	}
	OnAfterAct.Broadcast();
}

void UUtilityAIBrainComponent::BeginPlay()
{
	Super::BeginPlay();
	Asset = NewObject<UBrainAsset>(this, BrainAssetClass, TEXT("Brain Asset"));
}
