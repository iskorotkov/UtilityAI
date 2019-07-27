// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PredicatesBoxWidget.generated.h"

class UBrainAsset;
class UDataRowWidget;
/**
 * 
 */
UCLASS()
class UPredicatesBoxWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPredicatesBoxWidget(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintCallable)
	void SetBrain(UBrainAsset* Brain);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	UDataRowWidget* AddDataRow();

private:
	UPROPERTY(EditAnywhere)
	FText SuccessStatus;

	UPROPERTY(EditAnywhere)
	FText FailureStatus;

	TMap<FString, UDataRowWidget*> DataRows;

	UFUNCTION()
	void UpdateRow(FString Name, bool Result);
};
