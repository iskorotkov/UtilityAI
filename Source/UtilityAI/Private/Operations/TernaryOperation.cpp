// Fill out your copyright notice in the Description page of Project Settings.

#include "TernaryOperation.h"

TSet<UPredicate*> UTernaryOperation::GetPredicates_Implementation() const
{
	auto Predicates = Operand1->GetPredicates();
	Predicates.Append(Operand2->GetPredicates());
	Predicates.Append(Operand3->GetPredicates());
	return Predicates;
}

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

void UTernaryOperation::Init(UExpression* F, UExpression* S, UExpression* T)
{
	Operand1 = F;
	Operand2 = S;
	Operand3 = T;
}
