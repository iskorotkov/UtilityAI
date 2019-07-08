// Fill out your copyright notice in the Description page of Project Settings.

#include "BinaryOperation.h"

void UBinaryOperation::GetPredicatesRecursively(FPredicatesContainerRef Predicates)
{
	Operand1->GetPredicatesRecursively(Predicates);
	Operand2->GetPredicatesRecursively(Predicates);
}

UExpression* UBinaryOperation::First() const
{
	return Operand1;
}

UExpression* UBinaryOperation::Second() const
{
	return Operand2;
}

bool UBinaryOperation::FirstResult(const TScriptInterface<IAgent>& Agent) const
{
	return First()->Evaluate(Agent);
}

bool UBinaryOperation::SecondResult(const TScriptInterface<IAgent>& Agent) const
{
	return Second()->Evaluate(Agent);
}

void UBinaryOperation::Init(UExpression* F, UExpression* S)
{
	Operand1 = F;
	Operand2 = S;
}
