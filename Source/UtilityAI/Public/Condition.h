// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Expression.h"
#include "Condition.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Abstract)
class UTILITYAI_API UCondition : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	virtual bool Evaluate() const;

private:
	UPROPERTY()
	UExpression* Expression;
};
