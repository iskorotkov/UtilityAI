// Fill out your copyright notice in the Description page of Project Settings.

#include "Condition.h"
#include "Expression.h"

float UCondition::Evaluate_Implementation() const
{
	return Expression && Expression->Evaluate() ? SuccessValue : FailureValue;
}

void UCondition::SetExpression_Implementation(UExpression* Expr)
{
	Expression = Expr;
}

void UCondition::SetValues_Implementation(const float Success, const float Failure)
{
	SuccessValue = Success;
	FailureValue = Failure;
}
