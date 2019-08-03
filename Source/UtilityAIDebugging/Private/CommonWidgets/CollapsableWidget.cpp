// Fill out your copyright notice in the Description page of Project Settings.

#include "CollapsableWidget.h"

bool UCollapsableWidget::IsCollapsed() const
{
	return bIsCollapsed;
}

void UCollapsableWidget::OnCollapseButtonClicked()
{
	if (IsCollapsed())
	{
		ExpandContent();
	}
	else
	{
		CollapseContent();
	}
	bIsCollapsed = !bIsCollapsed;
}
