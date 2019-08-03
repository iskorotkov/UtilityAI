// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SubclassOf.h"
#include "StrongObjectPtr.h"
#include "Condition.generated.h"

class UPredicate;
class IAgent;
/**
 * 
 */
USTRUCT(BlueprintType)
struct UTILITYAI_API FCondition
{
	GENERATED_BODY()

public:
	float Evaluate(const TScriptInterface<IAgent>& Agent, UObject* OuterAction);

	FString GetName() const;

	UPredicate* GetPredicate(UObject* Outer);
	UPredicate* GetPredicateIfCreated() const;

private:
	TStrongObjectPtr<UPredicate> Predicate;

	UPROPERTY(EditAnywhere)
	FString Name;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UPredicate> PredicateClass;

	UPROPERTY(EditAnywhere)
	float SuccessValue = 0.1f;

	UPROPERTY(EditAnywhere)
	float FailureValue = 0.0f;

	void EnsurePredicateIsCreated(UObject* Outer);
};
