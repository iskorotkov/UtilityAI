// Fill out your copyright notice in the Description page of Project Settings.

#include "Expression.h"
#include "UtilityAI.h"

bool UExpression::Evaluate_Implementation(const TScriptInterface<IAgent>& Agent)
{
	UE_LOG(UtilityAI, Error, TEXT("Expression %s has no overriden evaluate behavior"), *GetName());
	return false;
}

TSet<UPredicate*> UExpression::GetPredicatesRecursively_Implementation() const
{
	return TSet<UPredicate*>();
}
