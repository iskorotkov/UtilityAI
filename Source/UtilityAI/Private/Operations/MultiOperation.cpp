// Fill out your copyright notice in the Description page of Project Settings.

#include "MultiOperation.h"

const TArray<UExpression*>& UMultiOperation::Operands() const
{
	return Ops;
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
