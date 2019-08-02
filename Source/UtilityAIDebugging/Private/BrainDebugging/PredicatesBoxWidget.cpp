// Fill out your copyright notice in the Description page of Project Settings.

#include "PredicatesBoxWidget.h"
#include "BrainAsset.h"
#include "CommonWidgets/DataRowWidget.h"
#include "UtilityAIStatics.h"
#include "Predicate.h"
#include "Statics/ObjectNamesStatics.h"

UPredicatesBoxWidget::UPredicatesBoxWidget(const FObjectInitializer& ObjectInitializer)
{
	SuccessStatus = FText::FromString("Succeeded");
	FailureStatus = FText::FromString("Failed");
}

void UPredicatesBoxWidget::SetBrain(UBrainAsset* Brain)
{
	Super::SetBrain(Brain);
	const auto Predicates = UUtilityAIStatics::GetPredicates(Brain);
	for (const auto Predicate : Predicates)
	{
		auto DataRow = AddDataRow();
		const auto Name = Predicate->GetName();
		const auto PrettyName = UObjectNamesStatics::StripObjectName(Name);
		check(DataRow);
		DataRow->SetName(FText::FromString(PrettyName));
		DataRows.Add(Name, DataRow);
		Predicate->OnEvaluated.AddDynamic(this, &UPredicatesBoxWidget::UpdateRow);
	}
}

void UPredicatesBoxWidget::Reset_Implementation()
{
	DataRows.Empty();
	if (const auto Brain = GetAssignedBrain())
	{
		const auto Predicates = UUtilityAIStatics::GetPredicates(Brain);
		for (const auto Predicate : Predicates)
		{
			Predicate->OnEvaluated.RemoveDynamic(this, &UPredicatesBoxWidget::UpdateRow);
		}
	}
	Super::Reset_Implementation();
}

void UPredicatesBoxWidget::UpdateRow(const FString Name, const bool Result)
{
	DataRows[Name]->SetValue(Result ? SuccessStatus : FailureStatus);
}
