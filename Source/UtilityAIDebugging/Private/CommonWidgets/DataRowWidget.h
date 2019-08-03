// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DataRowWidget.generated.h"

class UTextBlock;
/**
 * 
 */
UCLASS()
class UDataRowWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetName(FText Text);

	UFUNCTION(BlueprintCallable)
	void SetValue(FText Text);

protected:
	UFUNCTION(BlueprintCallable)
	void Init(UTextBlock* NameText, UTextBlock* ValueText);

private:
	UPROPERTY()
	UTextBlock* NameWidget;

	UPROPERTY()
	UTextBlock* ValueWidget;
};
