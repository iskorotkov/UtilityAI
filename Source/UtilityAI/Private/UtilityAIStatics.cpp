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

UAction* UUtilityAIStatics::CreateAction(UObject* Outer, const TSubclassOf<UAction> Class, TArray<UCondition*> Conditions)
{
	const auto Action = NewObject<UAction>(Outer, Class);
	check(Action);
	Action->SetConditions(Conditions);
	return Action;
}

UCondition* UUtilityAIStatics::CreateCondition(UObject* Outer, const TSubclassOf<UCondition> Class, UExpression* Expression, float Success, float Failure)
{
	const auto Condition = NewObject<UCondition>(Outer, Class);
	check(Condition);
	Condition->SetExpression(Expression);
	return Condition;
}

UCondition* UUtilityAIStatics::CreateConditionNonDefault(UObject* Outer, TSubclassOf<UCondition> Class, UExpression* Expression, float Success, float Failure)
{
	const auto Condition = NewObject<UCondition>(Outer, Class);
	check(Condition);
	Condition->SetExpression(Expression);
	Condition->SetValues(Success, Failure);
	return Condition;
}

UExpression* UUtilityAIStatics::CreateUnaryOperation(UObject* Outer, TSubclassOf<UUnaryOperation> Class, UExpression* Operand)
{
	const auto Expression = NewObject<UExpression>(Outer, Class);
	check(Expression);
	return Expression;
}

UExpression* UUtilityAIStatics::CreateBinaryOperation(UObject* Outer, TSubclassOf<UBinaryOperation> Class, UExpression* Operand1, UExpression* Operand2)
{
	const auto Expression = NewObject<UExpression>(Outer, Class);
	check(Expression);
	return Expression;
}

UExpression* UUtilityAIStatics::CreateTernaryOperation(UObject* Outer, TSubclassOf<UTernaryOperation> Class, UExpression* Operand1, UExpression* Operand2, UExpression* Operand3)
{
	const auto Expression = NewObject<UExpression>(Outer, Class);
	check(Expression);
	return Expression;
}

UExpression* UUtilityAIStatics::CreateMultiOperation(UObject* Outer, TSubclassOf<UMultiOperation> Class, TArray<UExpression*> Operands)
{
	const auto Expression = NewObject<UExpression>(Outer, Class);
	check(Expression);
	return Expression;
}

UExpression* UUtilityAIStatics::CreatePredicate(UObject* Outer, TSubclassOf<UPredicate> Class)
{
	return NewObject<UExpression>(Outer, Class);
}
