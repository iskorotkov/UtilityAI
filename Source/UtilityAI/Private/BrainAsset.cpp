// Fill out your copyright notice in the Description page of Project Settings.

#include "BrainAsset.h"
#include "Action.h"

UAction* UBrainAsset::SelectAction() const
{
	return nullptr;
}

void UBrainAsset::SetActions(const TArray<UAction*>& NewActions)
{
	// TODO: avoid copying Actions array
	Actions = NewActions;
}
