// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Action.generated.h"

class UBehaviorTree;
class UCondition;
class IAgent;
/**
 * 
 */
UCLASS(BlueprintType)
class UTILITYAI_API UAction : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	float Evaluate() const;
	virtual float Evaluate_Implementation() const;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Run(const TScriptInterface<IAgent>& Agent) const;
	virtual void Run_Implementation(const TScriptInterface<IAgent>& Agent) const;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SetConditions(const TArray<UCondition*>& NewConditions);
	void SetConditions_Implementation(const TArray<UCondition*>& NewConditions);

	// TODO: override GetDesc()

private:
	UPROPERTY()
	TArray<UCondition*> Conditions;

	UPROPERTY(EditAnywhere)
	UBehaviorTree* Behavior;
};
