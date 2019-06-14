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
UCLASS(BlueprintType, Abstract)
class UTILITYAI_API UAction : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	virtual float Evaluate() const;

	UFUNCTION(BlueprintCallable)
	virtual void Run(TScriptInterface<IAgent> Agent) const;

	// TODO: override GetDesc()

private:
	UPROPERTY()
	TArray<UCondition*> Conditions;

	UPROPERTY(EditAnywhere)
	UBehaviorTree* Behavior;
};
