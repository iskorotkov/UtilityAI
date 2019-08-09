// Fill out your copyright notice in the Description page of Project Settings.

#include "Expression.h"
#include "UtilityAI.h"

bool UExpression::ExpressionValue_Implementation(const TScriptInterface<IAgent>& Agent)
{
	return false;
}

bool UExpression::Evaluate(const TScriptInterface<IAgent>& Agent)
{
	return ExpressionValue(Agent);
}

void UExpression::GetPredicatesRecursively(FPredicatesContainerRef Predicates)
{
}
