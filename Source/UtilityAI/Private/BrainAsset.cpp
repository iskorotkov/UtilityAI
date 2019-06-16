// Fill out your copyright notice in the Description page of Project Settings.

#include "BrainAsset.h"
#include "Action.h"

UAction* UBrainAsset::SelectAction_Implementation() const
{
	return nullptr;
}

void UBrainAsset::SetActions_Implementation(const TArray<UAction*>& NewActions)
{
	// TODO: avoid copying Actions array
	Actions = NewActions;
}
