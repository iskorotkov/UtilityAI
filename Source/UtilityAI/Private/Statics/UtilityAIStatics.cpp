// Fill out your copyright notice in the Description page of Project Settings.

#include "UtilityAIStatics.h"
#include "Expression.h"
#include "UnaryOperation.h"
#include "BinaryOperation.h"
#include "TernaryOperation.h"
#include "MultiOperation.h"
#include "Predicate.h"
#include "Agent.h"
#include "AIController.h"

UExpression* UUtilityAIStatics::CreateUnaryOperation(TSubclassOf<UUnaryOperation> Class, UExpression* Operand)
{
	const auto Expression = NewObject<UExpression>(GetOuter(), Class, TEXT("Unary operation"));
	check(Expression);
	return Expression;
}

UExpression* UUtilityAIStatics::CreateBinaryOperation(TSubclassOf<UBinaryOperation> Class, UExpression* Operand1, UExpression* Operand2)
{
	const auto Expression = NewObject<UExpression>(GetOuter(), Class, TEXT("Binary operation"));
	check(Expression);
	return Expression;
}

UExpression* UUtilityAIStatics::CreateTernaryOperation(TSubclassOf<UTernaryOperation> Class, UExpression* Operand1, UExpression* Operand2, UExpression* Operand3)
{
	const auto Expression = NewObject<UExpression>(GetOuter(), Class, TEXT("Ternary operation"));
	check(Expression);
	return Expression;
}

UExpression* UUtilityAIStatics::CreateMultiOperation(TSubclassOf<UMultiOperation> Class, TArray<UExpression*> Operands)
{
	const auto Expression = NewObject<UExpression>(GetOuter(), Class, TEXT("Multi operation"));
	check(Expression);
	return Expression;
}

UExpression* UUtilityAIStatics::CreatePredicate(TSubclassOf<UPredicate> Class)
{
	return NewObject<UExpression>(GetOuter(), Class, TEXT("Predicate"));
}

AAIController* UUtilityAIStatics::AsAIController(const TScriptInterface<IAgent>& Agent)
{
	return Cast<AAIController>(Agent.GetObject());
}

AActor* UUtilityAIStatics::AsActor(const TScriptInterface<IAgent>& Agent)
{
	return Cast<AActor>(Agent.GetObject());
}

UObject* UUtilityAIStatics::GetOuter()
{
	return Cast<UObject>(GetTransientPackage());
}
