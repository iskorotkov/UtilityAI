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
	UFUNCTION(BlueprintCallable)
	float Evaluate() const;

	UFUNCTION(BlueprintCallable)
	void SetExpression(UExpression* Expr);

	UFUNCTION(BlueprintCallable)
	void SetValues(float Success, float Failure);

protected:
	UFUNCTION(BlueprintNativeEvent)
	UExpression* GetExpression() const;
	virtual UExpression* GetExpression_Implementation() const;

	void PostInitProperties() override;

private:
	UPROPERTY(VisibleAnywhere)
	UExpression* Expression;

	UPROPERTY(VisibleAnywhere)
	float SuccessValue = 0.1f;

	UPROPERTY(VisibleAnywhere)
	float FailureValue = 0.0f;
};
