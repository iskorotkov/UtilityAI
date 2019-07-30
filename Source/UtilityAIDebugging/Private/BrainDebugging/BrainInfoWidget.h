// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BrainInfoWidget.generated.h"

class UBrainAsset;
/**
 * 
 */
UCLASS()
class UBrainInfoWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetBrain(UBrainAsset* Brain);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnActionSelected(const FString& Name, float Value);

	UFUNCTION(BlueprintNativeEvent)
	void Reset();

private:
	UFUNCTION()
	void ReactOnActionSelected(FString Name, float Value);
};
