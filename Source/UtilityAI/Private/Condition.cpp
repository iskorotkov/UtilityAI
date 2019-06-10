// Fill out your copyright notice in the Description page of Project Settings.

#include "Condition.h"

void UCondition::SetExpression(UExpression* Expr)
{
	check(Expr);
	Expression = Expr;
}
