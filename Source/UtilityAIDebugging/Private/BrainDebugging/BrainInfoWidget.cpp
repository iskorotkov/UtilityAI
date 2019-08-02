// Fill out your copyright notice in the Description page of Project Settings.

#include "BrainInfoWidget.h"
#include "BrainAsset.h"

void UBrainInfoWidget::SetBrain(UBrainAsset* Brain)
{
	Super::SetBrain(Brain);
	if (Brain)
	{
		Brain->OnActionSelected.AddDynamic(this, &UBrainInfoWidget::ReactOnActionSelected);
	}
}

void UBrainInfoWidget::Reset_Implementation()
{
	if (const auto Brain = GetAssignedBrain())
	{
		Brain->OnActionSelected.RemoveDynamic(this, &UBrainInfoWidget::ReactOnActionSelected);
	}
	Super::Reset_Implementation();
}

void UBrainInfoWidget::ReactOnActionSelected(const FString Name, const float Value)
{
	OnActionSelected(Name, Value);
}
