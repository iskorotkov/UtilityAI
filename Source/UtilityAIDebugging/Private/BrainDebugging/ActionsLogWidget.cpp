// Fill out your copyright notice in the Description page of Project Settings.

#include "ActionsLogWidget.h"
#include "BrainAsset.h"
#include "DataRowWidget.h"

void UActionsLogWidget::SetBrain(UBrainAsset* Brain)
{
	check(Brain);
	Brain->OnActionSelected.AddDynamic(this, &UActionsLogWidget::AddActionToLog);
}

void UActionsLogWidget::AddActionToLog(const FString Name, const float Value)
{
	auto DataRow = AddDataRow();
	check(DataRow);
	DataRow->SetName(FText::FromString(Name));
	DataRow->SetValue(FText::AsNumber(Value));
}
