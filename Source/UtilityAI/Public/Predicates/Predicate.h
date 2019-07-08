// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Expression.h"
#include "Predicate.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Abstract, Blueprintable)
class UTILITYAI_API UPredicate : public UExpression
{
	GENERATED_BODY()

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPredicateSignature, FString, PredicateName, bool, Success);

public:
	FPredicateSignature OnEvaluated;

	bool Evaluate_Implementation(const TScriptInterface<IAgent>& Agent) override;

	TSet<UPredicate*> GetPredicatesRecursively_Implementation() const override;
};
