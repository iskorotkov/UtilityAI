// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Condition.h"
#include "StrongObjectPtr.h"
#include "Action.generated.h"

class UValue;
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

public:
	UAction();

	FActionSignature OnEvaluated;

	FActionRunSignature OnRun;

	UFUNCTION(BlueprintCallable)
	void Execute(const TScriptInterface<IAgent>& Agent);

	UFUNCTION(BlueprintCallable)
	float Evaluate(const TScriptInterface<IAgent>& Agent);

	UFUNCTION(BlueprintCallable)
	bool IgnoreIfCalledTwice() const;

	UFUNCTION(BlueprintCallable)
	const TArray<FCondition>& GetConditions() const;

protected:
	UFUNCTION(BlueprintNativeEvent)
	void Run(const TScriptInterface<IAgent>& Agent);
	virtual void Run_Implementation(const TScriptInterface<IAgent>& Agent);

private:
	UPROPERTY(EditAnywhere, AdvancedDisplay)
	float BaseValue;

	UPROPERTY(EditAnywhere, AdvancedDisplay)
	bool bIgnoreIfCalledTwice = false;

	UPROPERTY(EditAnywhere)
	TArray<FCondition> Conditions;

	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<UValue>> ValueClasses;

	TArray<TStrongObjectPtr<UValue>> Values;

	void InstantiateValueClasses();
};
