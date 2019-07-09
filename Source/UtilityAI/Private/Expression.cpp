// Fill out your copyright notice in the Description page of Project Settings.

#include "Expression.h"
#include "UtilityAI.h"

bool UExpression::ExpressionValue_Implementation(const TScriptInterface<IAgent>& Agent)
{
	UE_LOG(UtilityAI, Error, TEXT("Expression %s has no overriden evaluate behavior"), *GetName());
	return false;
}

bool UExpression::Evaluate(const TScriptInterface<IAgent>& Agent)
{
	return ExpressionValue(Agent);
}

void UExpression::GetPredicatesRecursively(FPredicatesContainerRef Predicates)
{
	UE_LOG(UtilityAI, Error, TEXT("Expression %s does not provide any way to access underlying predicates"), *GetName());
}
