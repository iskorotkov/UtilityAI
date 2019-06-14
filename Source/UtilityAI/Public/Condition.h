// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Condition.generated.h"

class UExpression;
/**
 * 
 */
UCLASS(BlueprintType)
class UTILITYAI_API UCondition : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	virtual float Evaluate() const;

	UFUNCTION(BlueprintCallable)
	virtual void SetExpression(UExpression* Expr);

private:
	UPROPERTY()
	UExpression* Expression;

	UPROPERTY(EditAnywhere)
	float SuccessValue = 0.1f;

	UPROPERTY(EditAnywhere)
	float FailureValue = 0.0f;
};
