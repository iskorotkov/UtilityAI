// Fill out your copyright notice in the Description page of Project Settings.

#include "ActionsLogWidget.h"
#include "BrainAsset.h"
#include "CommonWidgets/DataRowWidget.h"

void UActionsLogWidget::SetBrain(UBrainAsset* Brain)
{
	Super::SetBrain(Brain);
	Brain->OnActionSelected.AddDynamic(this, &UActionsLogWidget::AddActionToLog);
}

void UActionsLogWidget::Reset_Implementation()
{
	if (const auto Brain = GetAssignedBrain())
	{
		Brain->OnActionSelected.RemoveDynamic(this, &UActionsLogWidget::AddActionToLog);
	}
	Super::Reset_Implementation();
}

void UActionsLogWidget::OnEnableLoggingChanged(const bool bIsChecked)
{
	bIsLoggingEnabled = bIsChecked;
}

void UActionsLogWidget::OnEnableIgnoreRepeatingChanged(const bool bIsChecked)
{
	bIsIgnoreRepeatingEnabled = bIsChecked;
}

void UActionsLogWidget::AddActionToLog(const FString Name, const float Value)
{
	if (!IsLoggingEnabled()
		|| IsIgnoreRepeatingEnabled() && LastAction == Name)
	{
		return;
	}
	LastAction = Name;
	auto DataRow = AddDataRow();
	check(DataRow);
	DataRow->SetName(FText::FromString(Name));
	DataRow->SetValue(FText::AsNumber(Value));
}

bool UActionsLogWidget::IsLoggingEnabled() const
{
	return bIsLoggingEnabled;
}

bool UActionsLogWidget::IsIgnoreRepeatingEnabled() const
{
	return bIsIgnoreRepeatingEnabled;
}
