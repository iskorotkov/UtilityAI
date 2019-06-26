// Fill out your copyright notice in the Description page of Project Settings.

#include "ComplexPredicate.h"

bool UComplexPredicate::Evaluate_Implementation(const TScriptInterface<IAgent>& Agent)
{
	if (Expression == nullptr)
	{
		Expression = AssignExpression(Agent);
	}
	return Expression && Expression->Evaluate(Agent);
}

UExpression* UComplexPredicate::AssignExpression_Implementation(const TScriptInterface<IAgent>& Agent) const
{
	return nullptr;
}
