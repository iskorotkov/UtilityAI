// Fill out your copyright notice in the Description page of Project Settings.

#include "DataRowWidget.h"
#include "TextBlock.h"

void UDataRowWidget::Init(UTextBlock* NameText, UTextBlock* ValueText)
{
	Name = NameText;
	Value = ValueText;
}

void UDataRowWidget::SetName(const FText Text)
{
	Name->SetText(Text);
}

void UDataRowWidget::UpdateValue(const FText Text)
{
	Value->SetText(Text);
}
