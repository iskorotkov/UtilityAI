// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "CollapsableWidget.generated.h"

/**
 * 
 */
UCLASS()
class UCollapsableWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	bool IsCollapsed() const;

protected:
	UFUNCTION(BlueprintCallable)
	void OnCollapseButtonClicked();

	UFUNCTION(BlueprintImplementableEvent)
	void CollapseContent();

	UFUNCTION(BlueprintImplementableEvent)
	void ExpandContent();

private:
	UPROPERTY()
	bool bIsCollapsed = false;
};
