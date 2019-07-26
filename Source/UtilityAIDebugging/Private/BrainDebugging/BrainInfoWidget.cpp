// Fill out your copyright notice in the Description page of Project Settings.

#include "BrainInfoWidget.h"
#include "BrainAsset.h"

void UBrainInfoWidget::SetBrain(UBrainAsset* Brain)
{
	Brain->OnActionSelected.AddDynamic(this, &UBrainInfoWidget::ReactOnActionSelected);
}

void UBrainInfoWidget::ReactOnActionSelected(const FString Name, const float Value)
{
	OnActionSelected(Name, Value);
}
