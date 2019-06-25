// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Condition.generated.h"

class IAgent;
class UExpression;
/**
 * 
 */
UCLASS(BlueprintType, Blueprintable, Abstract, EditInlineNew)
class UTILITYAI_API UCondition : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	float Evaluate(const TScriptInterface<IAgent>& Agent);

protected:
	UFUNCTION(BlueprintNativeEvent)
	UExpression* GetExpression() const;
	virtual UExpression* GetExpression_Implementation() const;

private:
	UExpression* Expression;

	UPROPERTY(EditAnywhere)
	float SuccessValue = 0.1f;

	UPROPERTY(EditAnywhere)
	float FailureValue = 0.0f;
};
