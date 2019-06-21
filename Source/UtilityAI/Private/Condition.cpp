// Fill out your copyright notice in the Description page of Project Settings.

#include "Condition.h"
#include "Expression.h"

float UCondition::Evaluate()
{
	if (!Expression)
	{
		Expression = GetExpression();
	}
	return Expression && Expression->Evaluate() ? SuccessValue : FailureValue;
}

UExpression* UCondition::GetExpression_Implementation() const
{
	return nullptr;
}
