// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "Condition.h"
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
	virtual float Evaluate() const;

	// TODO: pass AI agent
	UFUNCTION(BlueprintCallable)
	virtual void Run() const;

	// TODO: override GetDesc()

private:
	UPROPERTY()
	TArray<UCondition*> Conditions;

	UPROPERTY(EditAnywhere)
	UBehaviorTree* Behavior;
};
