// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BrainDebuggingSection.h"
#include "BrainInfoWidget.generated.h"

class UBrainAsset;
/**
 * 
 */
UCLASS()
class UBrainInfoWidget : public UBrainDebuggingSection
{
	GENERATED_BODY()

public:
	void SetBrain(UBrainAsset* Brain) override;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnActionSelected(const FString& Name, float Value);

	void Reset_Implementation() override;

private:
	UFUNCTION()
	void ReactOnActionSelected(FString Name, float Value);
};
