// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "Action.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Abstract)
class UTILITYAI_API UAction : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	virtual float Evaluate() const = 0;

	UFUNCTION(BlueprintCallable)
	virtual void Run(/*TODO: pass AI agent*/) const = 0;

	// TODO: override GetDesc()

private:
	UPROPERTY()
	TArray<UCondition*> Conditions;

	UPROPERTY(EditAnywhere)
	UBehaviorTree* Behavior;
};
