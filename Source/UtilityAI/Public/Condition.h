// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Condition.generated.h"

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
	float Evaluate();

protected:
	UFUNCTION(BlueprintNativeEvent)
	UExpression* GetExpression() const;
	virtual UExpression* GetExpression_Implementation() const;

private:
	UPROPERTY(VisibleAnywhere)
	UExpression* Expression;

	UPROPERTY(VisibleAnywhere)
	float SuccessValue = 0.1f;

	UPROPERTY(VisibleAnywhere)
	float FailureValue = 0.0f;
};
