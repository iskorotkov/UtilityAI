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
#include "BrainAsset.h"
#include "Action.h"
#include "BrainAction.h"

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

UExpression* UUtilityAIStatics::CreateMultiOperation(const TSubclassOf<UMultiOperation> Class, const TArray<UExpression*> Operands, const TArray<int> Arguments)
{
	const auto Op = NewObject<UMultiOperation>(GetOuter(), Class, TEXT("Multi operation"));
	check(Op);
	Op->Init(Operands, Arguments);
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

TArray<UBrainAsset*> UUtilityAIStatics::GetBrainsRecursively(UBrainAsset* Brain)
{
	check(Brain);
	TArray<UBrainAsset*> Results;
	Results.Add(Brain);
	const auto Actions = GetActionsRecursively(Brain);
	for (const auto Action : Actions)
	{
		if (const auto BrainAction = Cast<UBrainAction>(Action))
		{
			Results.Add(BrainAction->GetBrain());
		}
	}
	return Results;
}

TArray<UAction*> UUtilityAIStatics::GetActionsRecursively(UBrainAsset* Brain)
{
	check(Brain);
	const auto Actions = Brain->GetActions();
	auto Results = Actions;
	for (const auto Action : Actions)
	{
		GetActions_Internal(Results, Action);
	}
	return Actions;
}

TArray<UPredicate*> UUtilityAIStatics::GetPredicates(UBrainAsset* Brain)
{
	check(Brain);
	const auto& Actions = Brain->GetActions();

	// TODO: use type like this consistently (or don't use at all)

	UExpression::FPredicatesContainer Predicates;
	for (const auto Action : Actions)
	{
		const auto& Conditions = Action->GetConditions();
		for (const auto& Condition : Conditions)
		{
			Condition.GetPredicate()->GetPredicatesRecursively(Predicates);
		}
	}
	return Predicates.Array();
}

TArray<UPredicate*> UUtilityAIStatics::GetPredicatesRecursively(UBrainAsset* Brain)
{
	check(Brain);
	const auto& Actions = GetActionsRecursively(Brain);
	UExpression::FPredicatesContainer Predicates;
	for (const auto Action : Actions)
	{
		const auto& Conditions = Action->GetConditions();
		for (const auto& Condition : Conditions)
		{
			Condition.GetPredicate()->GetPredicatesRecursively(Predicates);
		}
	}
	return Predicates.Array();
}

void UUtilityAIStatics::GetActions_Internal(TArray<UAction*>& Actions, UAction* Action)
{
	if (const auto BrainAction = Cast<UBrainAction>(Action))
	{
		Actions.Append(BrainAction->GetBrain()->GetActions());
		for (const auto InternalAction : BrainAction->GetBrain()->GetActions())
		{
			GetActions_Internal(Actions, InternalAction);
		}
	}
}
