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

public:
	UAction();

	UFUNCTION(BlueprintCallable)
	float Evaluate(const TScriptInterface<IAgent>& Agent);

	UFUNCTION(BlueprintNativeEvent)
	void Run(const TScriptInterface<IAgent>& Agent) const;
	virtual void Run_Implementation(const TScriptInterface<IAgent>& Agent) const;

	UFUNCTION(BlueprintCallable)
	bool IgnoreIfCalledTwice() const;

private:
	UPROPERTY(EditAnywhere)
	float BaseValue;

	UPROPERTY(EditAnywhere)
	bool bIgnoreIfCalledTwice = false;

	UPROPERTY(EditAnywhere)
	TArray<FCondition> Conditions;
};
