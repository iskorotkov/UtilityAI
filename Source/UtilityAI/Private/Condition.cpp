// Fill out your copyright notice in the Description page of Project Settings.

#include "Condition.h"
#include "Expression.h"

float UCondition::Evaluate() const
{
	return Expression && Expression->Evaluate() ? SuccessValue : FailureValue;
}

void UCondition::SetExpression(UExpression* Expr)
{
	Expression = Expr;
}
