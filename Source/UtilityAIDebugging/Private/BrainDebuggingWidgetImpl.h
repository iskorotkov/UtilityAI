// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ComboBoxString.h"
#include "BrainDebuggingWidgetImpl.generated.h"

class UUtilityAIBrainComponent;
class UBrainAsset;
/**
 * 
 */
UCLASS(BlueprintType)
class UBrainDebuggingWidgetImpl : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SelectActor();

	UFUNCTION(BlueprintCallable)
	TArray<FString> GetBrainOptions() const;

	UFUNCTION(BlueprintCallable)
	void SelectBrain(FString SelectedItem);

private:
	UPROPERTY()
	AActor* SelectedActor;

	UPROPERTY()
	UBrainAsset* SelectedBrain;

	TArray<UBrainAsset*> ActorBrains;
	TArray<FString> ActorBrainsNames;

	void ExtractComponentInfo(UUtilityAIBrainComponent* BrainComponent);
};
