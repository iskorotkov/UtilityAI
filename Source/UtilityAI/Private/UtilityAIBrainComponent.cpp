// Fill out your copyright notice in the Description page of Project Settings.

#include "UtilityAIBrainComponent.h"
#include "BrainAsset.h"

UUtilityAIBrainComponent::UUtilityAIBrainComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UUtilityAIBrainComponent::Act() const
{
	const auto Action = Asset->SelectAction();
	check(Action);
	const auto Owner = GetOwner();
	Action->Run(Owner);
}
