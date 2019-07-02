// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BrainAsset.generated.h"

class IAgent;
class UAction;
/**
 * 
 */
UCLASS(BlueprintType, Abstract, Blueprintable)
class UTILITYAI_API UBrainAsset : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	UAction* SelectAction(const TScriptInterface<IAgent>& Agent);

	void CreateActions(const TScriptInterface<IAgent>& Agent);

private:
	UPROPERTY(EditAnywhere, meta=(InlineEditConditionToggle))
	bool bHasMinValueToAct = false;

	UPROPERTY(EditAnywhere, meta=(EditCondition="bHasMinValueToAct"))
	float MinValueToAct = 0.0f;

	UPROPERTY(EditAnywhere, meta = (InlineEditConditionToggle))
	bool bHasSkipOtherActionsValue = false;

	UPROPERTY(EditAnywhere, meta = (EditCondition = "bHasSkipOthersValue"))
	float SkipOtherActionsValue = 0.95f;

	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<UAction>> ActionClasses;

	UPROPERTY()
	TArray<UAction*> Actions;

	UPROPERTY()
	UAction* LastAction;

	bool ShouldSkipOtherActions(float Value) const;
	bool ShouldSkipRepeatingAction(UAction* Action) const;
	bool ShouldSkipLowRankedAction(float Value) const;
};
