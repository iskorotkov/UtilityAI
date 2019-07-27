// Fill out your copyright notice in the Description page of Project Settings.

#include "ActionsBoxWidget.h"
#include "BrainAsset.h"
#include "DataRowWidget.h"
#include "Action.h"

void UActionsBoxWidget::SetBrain(UBrainAsset* Brain)
{
	const auto& Actions = Brain->GetActions();
	for (const auto Action : Actions)
	{
		const auto ActionName = Action->GetName();
		auto DataRow = AddDataRow();
		check(DataRow);
		DataRows.Add(ActionName, DataRow);
		DataRow->SetName(FText::FromString(ActionName));
		Action->OnEvaluated.AddDynamic(this, &UActionsBoxWidget::UpdateRow);
	}
}

void UActionsBoxWidget::UpdateRow(const FString Name, const float Value)
{
	DataRows[Name]->SetValue(FText::AsNumber(Value));
}
