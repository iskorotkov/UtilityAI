// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Condition.generated.h"

class UExpression;
/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class UTILITYAI_API UCondition : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	float Evaluate() const;
	virtual float Evaluate_Implementation() const;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SetExpression(UExpression* Expr);
	virtual void SetExpression_Implementation(UExpression* Expr);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SetValues(float Success, float Failure);
	virtual void SetValues_Implementation(float Success, float Failure);

private:
	UPROPERTY(VisibleAnywhere)
	UExpression* Expression;

	UPROPERTY(VisibleAnywhere)
	float SuccessValue = 0.1f;

	UPROPERTY(VisibleAnywhere)
	float FailureValue = 0.0f;
};
