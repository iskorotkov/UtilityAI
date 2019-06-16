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
	UFUNCTION(BlueprintCallable)
	virtual float Evaluate() const;

	UFUNCTION(BlueprintCallable)
	virtual void Run(TScriptInterface<IAgent> Agent) const;

	UFUNCTION(BlueprintCallable)
	virtual void SetConditions(const TArray<UCondition*>& NewConditions);

	// TODO: override GetDesc()

private:
	UPROPERTY()
	TArray<UCondition*> Conditions;

	UPROPERTY(EditAnywhere)
	UBehaviorTree* Behavior;
};
