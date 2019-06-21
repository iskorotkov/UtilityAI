// Fill out your copyright notice in the Description page of Project Settings.

#include "BrainAsset.h"
#include "Action.h"

UAction* UBrainAsset::SelectAction_Implementation() const
{
	return nullptr;
}

void UBrainAsset::SetActions(const TArray<UAction*>& NewActions)
{
	// TODO: avoid copying Actions array
	Actions = NewActions;
}

TArray<UAction*> UBrainAsset::GetActions_Implementation() const
{
	return TArray<UAction*>();
}

void UBrainAsset::PostInitProperties()
{
	Super::PostInitProperties();
	if (Actions.Num() == 0)
	{
		// TODO: avoid array copying
		Actions = GetActions();
	}
}
