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
UCLASS(BlueprintType, Blueprintable)
class UTILITYAI_API UAction : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	float Evaluate() const;

	UFUNCTION(BlueprintCallable)
	void Run(const TScriptInterface<IAgent>& Agent) const;

	UFUNCTION(BlueprintCallable)
	void SetConditions(const TArray<UCondition*>& NewConditions);

	// TODO: override GetDesc()

protected:
	UFUNCTION(BlueprintNativeEvent)
	TArray<UCondition*> GetConditions() const;
	virtual TArray<UCondition*> GetConditions_Implementation() const;

	void PostInitProperties() override;

private:
	UPROPERTY(VisibleAnywhere)
	TArray<UCondition*> Conditions;

	UPROPERTY(EditAnywhere)
	UBehaviorTree* Behavior;
};
