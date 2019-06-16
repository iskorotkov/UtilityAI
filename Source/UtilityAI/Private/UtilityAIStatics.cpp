// Fill out your copyright notice in the Description page of Project Settings.

#include "UtilityAIStatics.h"
#include "Action.h"
#include "Condition.h"
#include "Expression.h"
#include "UnaryOperation.h"
#include "BinaryOperation.h"
#include "TernaryOperation.h"
#include "MultiOperation.h"
#include "Predicate.h"
#include "Operation.h"

UAction* UUtilityAIStatics::CreateAction(const TSubclassOf<UAction> Class, TArray<UCondition*> Conditions)
{
	
	const auto Action = NewObject<UAction>(GetOuter(), Class);
	check(Action);
	Action->SetConditions(Conditions);
	return Action;
}

UCondition* UUtilityAIStatics::CreateCondition(const TSubclassOf<UCondition> Class, UExpression* Expression, float Success, float Failure)
{
	const auto Condition = NewObject<UCondition>(GetOuter(), Class);
	check(Condition);
	Condition->SetExpression(Expression);
	return Condition;
}

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

UAction* UUtilityAIStatics::CreateDefaultAction(TSubclassOf<UAction> Class)
{
	return NewObject<UAction>(GetOuter(), Class);
}

UCondition* UUtilityAIStatics::CreateDefaultCondition(TSubclassOf<UCondition> Class)
{
	return NewObject<UCondition>(GetOuter(), Class);
}

UExpression* UUtilityAIStatics::CreateDefaultOperation(TSubclassOf<UOperation> Class)
{
	return NewObject<UExpression>(GetOuter(), Class);
}

UObject* UUtilityAIStatics::GetOuter()
{
	return Cast<UObject>(GetTransientPackage());
}
