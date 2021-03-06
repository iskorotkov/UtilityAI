// Fill out your copyright notice in the Description page of Project Settings.

#include "MultiOperation.h"

void UMultiOperation::GetPredicatesRecursively(FPredicatesContainerRef Predicates)
{
	for (const auto& Expr : Operands())
	{
		Expr->GetPredicatesRecursively(Predicates);
	}
}

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

TArray<bool> UMultiOperation::OperandsResults(const TScriptInterface<IAgent>& Agent) const
{
	TArray<bool> Results;
	for (const auto Op : Ops)
	{
		const auto Evaluated = Op->Evaluate(Agent);
		Results.Add(Evaluated);
	}
	return Results;
}

int UMultiOperation::NthArg(const int N) const
{
	return Args[N];
}

int UMultiOperation::ArgsNum() const
{
	return Args.Num();
}

const TArray<int>& UMultiOperation::Arguments() const
{
	return Args;
}

void UMultiOperation::Init(const TArray<UExpression*>& O, const TArray<int>& A)
{
	if (bHasExpectedNumberOfArgs)
	{
		checkf(A.Num() == ExpectedNumberOfArgs, TEXT("The number of provided arguments do not match the expected number of arguments"));
	}
	Ops = O;
	Args = A;
}
