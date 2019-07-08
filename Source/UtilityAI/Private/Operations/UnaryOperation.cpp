// Fill out your copyright notice in the Description page of Project Settings.

#include "UnaryOperation.h"

void UUnaryOperation::GetPredicatesRecursively(FPredicatesContainerRef Predicates)
{
	return Operand->GetPredicatesRecursively(Predicates);
}

UExpression* UUnaryOperation::First() const
{
	return Operand;
}

bool UUnaryOperation::FirstResult(const TScriptInterface<IAgent>& Agent) const
{
	return First()->Evaluate(Agent);
}

void UUnaryOperation::Init(UExpression* F)
{
	Operand = F;
}
