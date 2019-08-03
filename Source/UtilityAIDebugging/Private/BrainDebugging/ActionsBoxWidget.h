// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BrainDebuggingSection.h"
#include "ActionsBoxWidget.generated.h"

class UBrainAsset;
class UDataRowWidget;
/**
 * 
 */
UCLASS()
class UActionsBoxWidget : public UBrainDebuggingSection
{
	GENERATED_BODY()

public:
	void SetBrain(UBrainAsset* Brain) override;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	UDataRowWidget* AddDataRow();
	
	void Reset_Implementation() override;

private:
	TMap<FString, UDataRowWidget*> DataRows;

	UFUNCTION()
	void UpdateRow(FString Name, float Value);
};
