// Fill out your copyright notice in the Description page of Project Settings.

#include "ComplexPredicate.h"
#include "UtilityAI.h"

bool UComplexPredicate::ExpressionValue_Implementation(const TScriptInterface<IAgent>& Agent)
{
	Super::Evaluate(Agent);
	if (Expression == nullptr)
	{
		Expression = AssignExpression(Agent);
	}
	return Expression && Expression->Evaluate(Agent);
}

UExpression* UComplexPredicate::AssignExpression_Implementation(const TScriptInterface<IAgent>& Agent) const
{
	UE_LOG(UtilityAI_Predicates, Error, TEXT("There is no expression defined for predicate %s"), *GetName());
	return nullptr;
}
