// Fill out your copyright notice in the Description page of Project Settings.

#include "Condition.h"
#include "Expression.h"
#include "Agent.h"

float UCondition::Evaluate(const TScriptInterface<IAgent>& Agent)
{
	if (!Expression)
	{
		Expression = GetExpression();
	}
	return Expression && Expression->Evaluate(Agent) ? SuccessValue : FailureValue;
}

UExpression* UCondition::GetExpression_Implementation() const
{
	return nullptr;
}
