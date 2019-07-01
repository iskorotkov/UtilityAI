// Fill out your copyright notice in the Description page of Project Settings.

#include "MultiOperation.h"

UExpression* UMultiOperation::Nth(int N) const
{
	return Ops[N];
}

const TArray<UExpression*>& UMultiOperation::Operands() const
{
	return Ops;
}

bool UMultiOperation::NthResult(const TScriptInterface<IAgent>& Agent, int N) const
{
	return Nth(N)->Evaluate(Agent);
}

TArray<bool> UMultiOperation::OperandsResult(const TScriptInterface<IAgent>& Agent) const
{
	TArray<bool> Results;
	for (const auto Op : Ops)
	{
		const auto Evaluated = Op->Evaluate(Agent);
		Results.Add(Evaluated);
	}
	return Results;
}
