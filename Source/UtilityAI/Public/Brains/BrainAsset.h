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

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FActionSignature, FString, ActionName, float, Value);

public:
	FActionSignature OnActionRanked;
	FActionSignature OnActionSelected;
	FActionSignature OnLowRankedActionSkipped;
	FActionSignature OnRepeatingActionSkipped;
	FActionSignature OnOtherActionsSkipped;

	UFUNCTION(BlueprintCallable)
	UAction* SelectAction(const TScriptInterface<IAgent>& Agent);

	UFUNCTION(BlueprintCallable)
	const TArray<UAction*>& GetActions();

private:
	UPROPERTY(EditAnywhere, AdvancedDisplay, meta=(InlineEditConditionToggle))
	bool bHasMinValueToAct = false;

	UPROPERTY(EditAnywhere, AdvancedDisplay, meta=(EditCondition=bHasMinValueToAct))
	float MinValueToAct = 0.05f;

	UPROPERTY(EditAnywhere, AdvancedDisplay, meta = (InlineEditConditionToggle))
	bool bHasSkipOtherActionsValue = false;

	UPROPERTY(EditAnywhere, AdvancedDisplay, meta = (EditCondition = bHasSkipOtherActionsValue))
	float SkipOtherActionsValue = 0.95f;

	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<UAction>> ActionClasses;

	UPROPERTY(EditAnywhere, AdvancedDisplay)
	TArray<TSubclassOf<UAction>> PreActionClasses;

	UPROPERTY(EditAnywhere, AdvancedDisplay)
	TArray<TSubclassOf<UAction>> PostActionClasses;

	TArray<UAction*> Actions;
	TArray<UAction*> PreActions;
	TArray<UAction*> PostActions;

	UPROPERTY()
	UAction* LastAction;

	void CreateActions();
	void ExecutePreActions(const TScriptInterface<IAgent>& Agent) const;
	void ExecutePostActions(const TScriptInterface<IAgent>& Agent) const;

	bool ShouldSkipOtherActions(float Value) const;
	bool ShouldSkipRepeatingAction(UAction* Action) const;
	bool ShouldSkipLowRankedAction(float Value) const;
	bool ShouldCreateActions() const;

	UAction* GetBestEvaluatedAction(const TScriptInterface<IAgent>& Agent);
};
