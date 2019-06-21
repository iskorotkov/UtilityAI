// Fill out your copyright notice in the Description page of Project Settings.

#include "UtilityAIStatics.h"
#include "Expression.h"
#include "UnaryOperation.h"
#include "BinaryOperation.h"
#include "TernaryOperation.h"
#include "MultiOperation.h"
#include "Predicate.h"

UExpression* UUtilityAIStatics::CreateUnaryOperation(TSubclassOf<UUnaryOperation> Class, UExpression* Operand)
{
	const auto Expression = NewObject<UExpression>(GetOuter(), Class);
	check(Expression);
	return Expression;
}

UExpression* UUtilityAIStatics::CreateBinaryOperation(TSubclassOf<UBinaryOperation> Class, UExpression* Operand1, UExpression* Operand2)
{
	const auto Expression = NewObject<UExpression>(GetOuter(), Class);
	check(Expression);
	return Expression;
}

UExpression* UUtilityAIStatics::CreateTernaryOperation(TSubclassOf<UTernaryOperation> Class, UExpression* Operand1, UExpression* Operand2, UExpression* Operand3)
{
	const auto Expression = NewObject<UExpression>(GetOuter(), Class);
	check(Expression);
	return Expression;
}

UExpression* UUtilityAIStatics::CreateMultiOperation(TSubclassOf<UMultiOperation> Class, TArray<UExpression*> Operands)
{
	const auto Expression = NewObject<UExpression>(GetOuter(), Class);
	check(Expression);
	return Expression;
}

UExpression* UUtilityAIStatics::CreatePredicate(TSubclassOf<UPredicate> Class)
{
	return NewObject<UExpression>(GetOuter(), Class);
}

UObject* UUtilityAIStatics::GetOuter()
{
	return Cast<UObject>(GetTransientPackage());
}
