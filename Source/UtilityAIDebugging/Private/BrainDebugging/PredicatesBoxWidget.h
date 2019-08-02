// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BrainDebuggingSection.h"
#include "PredicatesBoxWidget.generated.h"

class UBrainAsset;
class UDataRowWidget;
/**
 * 
 */
UCLASS()
class UPredicatesBoxWidget : public UBrainDebuggingSection
{
	GENERATED_BODY()

public:
	UPredicatesBoxWidget(const FObjectInitializer& ObjectInitializer);

	void SetBrain(UBrainAsset* Brain) override;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	UDataRowWidget* AddDataRow();

	void Reset_Implementation() override;

private:
	UPROPERTY(EditAnywhere)
	FText SuccessStatus;

	UPROPERTY(EditAnywhere)
	FText FailureStatus;

	TMap<FString, UDataRowWidget*> DataRows;

	UFUNCTION()
	void UpdateRow(FString Name, bool Result);
};
