// Fill out your copyright notice in the Description page of Project Settings.

#include "ValuesBoxWidget.h"
#include "ActionsBoxWidget.h"
#include "Statics/ObjectNamesStatics.h"
#include "BrainAsset.h"
#include "CommonWidgets/DataRowWidget.h"
#include "UtilityAIStatics.h"
#include "Value.h"

void UValuesBoxWidget::SetBrain(UBrainAsset* Brain)
{
	Super::SetBrain(Brain);
	const auto Values = UUtilityAIStatics::GetValues(Brain);
	for (const auto Value : Values)
	{
		Value->OnEvaluated.AddDynamic(this, &UValuesBoxWidget::UpdateRow);
		const auto Name = Value->GetName();
		const auto PrettyName = UObjectNamesStatics::StripObjectName(Name);
		auto DataRow = AddDataRow();
		check(DataRow);
		DataRows.Add(Name, DataRow);
		DataRow->SetName(FText::FromString(PrettyName));
	}
}

void UValuesBoxWidget::Reset_Implementation()
{
	DataRows.Empty();
	if (const auto Brain = GetAssignedBrain())
	{
		const auto Values = UUtilityAIStatics::GetValues(Brain);
		for (const auto Value : Values)
		{
			Value->OnEvaluated.RemoveDynamic(this, &UValuesBoxWidget::UpdateRow);
		}
	}
	Super::Reset_Implementation();
}

void UValuesBoxWidget::UpdateRow(const FString Name, const float Value)
{
	DataRows[Name]->SetValue(FText::AsNumber(Value));
}
