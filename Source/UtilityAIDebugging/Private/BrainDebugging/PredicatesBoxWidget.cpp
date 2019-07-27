// Fill out your copyright notice in the Description page of Project Settings.

#include "PredicatesBoxWidget.h"
#include "BrainAsset.h"
#include "DataRowWidget.h"
#include "UtilityAIStatics.h"
#include "Predicate.h"

UPredicatesBoxWidget::UPredicatesBoxWidget(const FObjectInitializer& ObjectInitializer) : UUserWidget(ObjectInitializer)
{
	SuccessStatus = FText::FromString("Succeeded");
	FailureStatus = FText::FromString("Failed");
}

void UPredicatesBoxWidget::SetBrain(UBrainAsset* Brain)
{
	check(Brain);
	const auto Predicates = UUtilityAIStatics::GetPredicates(Brain);
	for (const auto Predicate : Predicates)
	{
		auto DataRow = AddDataRow();
		const auto Name = Predicate->GetName();
		check(DataRow);
		DataRow->SetName(FText::FromString(Name));
		DataRows.Add(Name, DataRow);
		Predicate->OnEvaluated.AddDynamic(this, &UPredicatesBoxWidget::UpdateRow);
	}
}

void UPredicatesBoxWidget::UpdateRow(const FString Name, const bool Result)
{
	// TODO: replace constants with properties
	DataRows[Name]->SetValue(Result ? SuccessStatus : FailureStatus);
}
