// Fill out your copyright notice in the Description page of Project Settings.

#include "UtilityAIStatics.h"

UAction* UUtilityAIStatics::CreateAction(UObject* Outer, const TSubclassOf<UAction> Class, TArray<UCondition*> Conditions)
{
	const auto Action = NewObject<UAction>(Outer, Class);
	check(Action);
	// TODO: set conditions
	return Action;
}

UCondition* UUtilityAIStatics::CreateCondition(UObject* Outer, const TSubclassOf<UCondition> Class, UExpression* Expression)
{
	const auto Condition = NewObject<UCondition>(Outer, Class);
	check(Condition);
	// TODO: set expression
	return Condition;
}

UExpression* UUtilityAIStatics::CreateUnaryExpression(UObject* Outer, const TSubclassOf<UExpression> Class, UExpression* Operand)
{
	const auto Expression = NewObject<UExpression>(Outer, Class);
	check(Expression);
	return Expression;
}

UExpression* UUtilityAIStatics::CreateBinaryExpression(UObject* Outer, TSubclassOf<UExpression> Class, UExpression* Operand1, UExpression* Operand2)
{
	const auto Expression = NewObject<UExpression>(Outer, Class);
	check(Expression);
	return Expression;
}

UExpression* UUtilityAIStatics::CreateTernaryExpression(UObject* Outer, TSubclassOf<UExpression> Class, UExpression* Operand1, UExpression* Operand2, UExpression* Operand3)
{
	const auto Expression = NewObject<UExpression>(Outer, Class);
	check(Expression);
	return Expression;
}

UExpression* UUtilityAIStatics::CreateMultiExpression(UObject* Outer, TSubclassOf<UExpression> Class, TArray<UExpression*> Operands)
{
	const auto Expression = NewObject<UExpression>(Outer, Class);
	check(Expression);
	return Expression;
}
