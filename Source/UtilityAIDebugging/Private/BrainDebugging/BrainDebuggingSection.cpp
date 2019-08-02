// Fill out your copyright notice in the Description page of Project Settings.

#include "BrainDebuggingSection.h"
#include "BrainAsset.h"

void UBrainDebuggingSection::SetBrain(UBrainAsset* Brain)
{
	check(Brain);
	Reset();
	AssignedBrain = Brain;
}

UBrainAsset* UBrainDebuggingSection::GetAssignedBrain() const
{
	return AssignedBrain;
}

void UBrainDebuggingSection::Reset_Implementation()
{
	AssignedBrain = nullptr;
}
