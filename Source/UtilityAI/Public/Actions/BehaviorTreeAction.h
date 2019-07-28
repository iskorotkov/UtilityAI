// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Action.h"
#include "BehaviorTreeAction.generated.h"

class UBehaviorTree;
/**
 * 
 */
UCLASS(BlueprintType, Blueprintable, Abstract)
class UTILITYAI_API UBehaviorTreeAction : public UAction
{
	GENERATED_BODY()

public:
	void Run_Implementation(const TScriptInterface<IAgent>& Agent) override;

private:
	UPROPERTY(EditAnywhere)
	UBehaviorTree* Behavior;
};
