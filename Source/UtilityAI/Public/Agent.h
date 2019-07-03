// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Agent.generated.h"

class UAgentData;
class UBehaviorTree;
// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UAgent : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class UTILITYAI_API IAgent
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void RunBehavior(const UBehaviorTree* Behavior);

	// TODO: is there an easier way to create and access agent data object?
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	UAgentData* GetAgentData();
};
