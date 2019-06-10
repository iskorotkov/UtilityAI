// Fill out your copyright notice in the Description page of Project Settings.

#include "UtilityAIStatics.h"

UAction* UUtilityAIStatics::CreateAction(UObject* Outer, UClass* Class, TArray<UCondition*> Conditions)
{
	const auto Action = NewObject<UAction>(Outer, Class);
	check(Action);
	// TODO: set conditions
	return Action;
}

UCondition* UUtilityAIStatics::CreateCondition(UObject* Outer, UClass* Class, UExpression* Expression)
{
	const auto Condition = NewObject<UCondition>(Outer, Class);
	check(Condition);
	// TODO: set expression
	return Condition;
}

UExpression* UUtilityAIStatics::CreateExpression(UObject* Outer, UClass* Class)
{
	const auto Expression = NewObject<UExpression>(Outer, Class);
	check(Expression);
	return Expression;
}
