// Fill out your copyright notice in the Description page of Project Settings.

#include "TernaryOperation.h"

UExpression* UTernaryOperation::First() const
{
	return Operand1;
}

UExpression* UTernaryOperation::Second() const
{
	return Operand2;
}

UExpression* UTernaryOperation::Third() const
{
	return Operand3;
}

bool UTernaryOperation::FirstResult(const TScriptInterface<IAgent>& Agent) const
{
	return First()->Evaluate(Agent);
}

bool UTernaryOperation::SecondResult(const TScriptInterface<IAgent>& Agent) const
{
	return Second()->Evaluate(Agent);
}

bool UTernaryOperation::ThirdResult(const TScriptInterface<IAgent>& Agent) const
{
	return Third()->Evaluate(Agent);
}
