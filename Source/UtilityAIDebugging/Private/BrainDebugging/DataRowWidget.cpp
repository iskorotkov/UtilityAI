// Fill out your copyright notice in the Description page of Project Settings.

#include "DataRowWidget.h"
#include "TextBlock.h"

void UDataRowWidget::Init(UTextBlock* NameText, UTextBlock* ValueText)
{
	NameWidget = NameText;
	ValueWidget = ValueText;
}

void UDataRowWidget::SetName(const FText Text)
{
	NameWidget->SetText(Text);
}

void UDataRowWidget::SetValue(const FText Text)
{
	ValueWidget->SetText(Text);
}
