// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ActionsBoxWidget.generated.h"

class UBrainAsset;
class UDataRowWidget;
/**
 * 
 */
UCLASS()
class UActionsBoxWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetBrain(UBrainAsset* Brain);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	UDataRowWidget* AddDataRow();

private:
	TMap<FString, UDataRowWidget*> DataRows;

	UFUNCTION()
	void UpdateRow(FString Name, float Value);
};
