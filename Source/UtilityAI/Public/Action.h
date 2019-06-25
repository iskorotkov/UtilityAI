// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Action.generated.h"

class UCondition;
class IAgent;
/**
 * 
 */
UCLASS(BlueprintType, Blueprintable, Abstract, EditInlineNew)
class UTILITYAI_API UAction : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	float Evaluate(const TScriptInterface<IAgent>& Agent) const;

	UFUNCTION(BlueprintNativeEvent)
	void Run(const TScriptInterface<IAgent>& Agent) const;
	virtual void Run_Implementation(const TScriptInterface<IAgent>& Agent) const;

	// TODO: override GetDesc()

private:
	UPROPERTY(EditAnywhere, Instanced)
	TArray<UCondition*> Conditions;
};
