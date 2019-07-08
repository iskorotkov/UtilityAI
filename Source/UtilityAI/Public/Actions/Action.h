// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Condition.h"
#include "Action.generated.h"

class IAgent;
/**
 * 
 */
UCLASS(BlueprintType, Blueprintable, Abstract)
class UTILITYAI_API UAction : public UObject
{
	GENERATED_BODY()

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FActionSignature, FString, ActionName, float, Value);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FActionRunSignature, FString, ActionName);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FConditionSignature, FString, ConditionName, float, Value);

public:
	UAction();

	FActionSignature OnEvaluated;

	FActionRunSignature OnRun;

	FConditionSignature OnConditionEvaluated;

	UFUNCTION(BlueprintCallable)
	float Evaluate(const TScriptInterface<IAgent>& Agent);

	UFUNCTION(BlueprintNativeEvent)
	void Run(const TScriptInterface<IAgent>& Agent) const;
	virtual void Run_Implementation(const TScriptInterface<IAgent>& Agent) const;

	UFUNCTION(BlueprintCallable)
	bool IgnoreIfCalledTwice() const;

	UFUNCTION(BlueprintCallable)
	const TArray<FCondition>& GetConditions() const;

private:
	UPROPERTY(EditAnywhere, AdvancedDisplay)
	float BaseValue;

	UPROPERTY(EditAnywhere, AdvancedDisplay)
	bool bIgnoreIfCalledTwice = false;

	UPROPERTY(EditAnywhere)
	TArray<FCondition> Conditions;
};
