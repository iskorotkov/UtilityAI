// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BrainDebuggingSection.h"
#include "ActionsLogWidget.generated.h"

class UBrainAsset;
class UDataRowWidget;
/**
 * 
 */
UCLASS()
class UActionsLogWidget : public UBrainDebuggingSection
{
	GENERATED_BODY()

public:
	void SetBrain(UBrainAsset* Brain) override;

protected:
	void Reset_Implementation() override;

	UFUNCTION(BlueprintCallable)
	void OnEnableLoggingChanged(bool bIsChecked);

	UFUNCTION(BlueprintCallable)
	void OnEnableIgnoreRepeatingChanged(bool bIsChecked);

	UFUNCTION(BlueprintImplementableEvent)
	UDataRowWidget* AddDataRow();

	UFUNCTION()
	void AddActionToLog(FString Name, float Value);

	UFUNCTION(BlueprintCallable)
	bool IsLoggingEnabled() const;

	UFUNCTION(BlueprintCallable)
	bool IsIgnoreRepeatingEnabled() const;

private:
	bool bIsLoggingEnabled = true;
	bool bIsIgnoreRepeatingEnabled = false;

	FString LastAction;
};
