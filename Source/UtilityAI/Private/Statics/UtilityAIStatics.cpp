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

UExpression* UUtilityAIStatics::CreateUnaryOperation(const TSubclassOf<UUnaryOperation> Class, UExpression* Operand)
{
	const auto Op = NewObject<UUnaryOperation>(GetOuter(), Class, TEXT("Unary operation"));
	check(Op);
	Op->Init(Operand);
	return Op;
}

UExpression* UUtilityAIStatics::CreateBinaryOperation(const TSubclassOf<UBinaryOperation> Class, UExpression* Operand1, UExpression* Operand2)
{
	const auto Op = NewObject<UBinaryOperation>(GetOuter(), Class, TEXT("Binary operation"));
	check(Op);
	Op->Init(Operand1, Operand2);
	return Op;
}

UExpression* UUtilityAIStatics::CreateTernaryOperation(const TSubclassOf<UTernaryOperation> Class, UExpression* Operand1, UExpression* Operand2, UExpression* Operand3)
{
	const auto Op = NewObject<UTernaryOperation>(GetOuter(), Class, TEXT("Ternary operation"));
	check(Op);
	Op->Init(Operand1, Operand2, Operand3);
	return Op;
}

UExpression* UUtilityAIStatics::CreateMultiOperation(const TSubclassOf<UMultiOperation> Class, TArray<UExpression*> Operands)
{
	const auto Op = NewObject<UMultiOperation>(GetOuter(), Class, TEXT("Multi operation"));
	check(Op);
	return Op;
}

UExpression* UUtilityAIStatics::CreatePredicate(const TSubclassOf<UPredicate> Class)
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
