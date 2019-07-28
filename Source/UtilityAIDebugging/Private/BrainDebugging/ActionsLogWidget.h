// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ActionsLogWidget.generated.h"

class UBrainAsset;
class UDataRowWidget;
/**
 * 
 */
UCLASS()
class UActionsLogWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetBrain(UBrainAsset* Brain);

	UFUNCTION(BlueprintNativeEvent)
	void Reset();

protected:
	UFUNCTION(BlueprintImplementableEvent)
	UDataRowWidget* AddDataRow();

	UFUNCTION()
	void AddActionToLog(FString Name, float Value);
};
