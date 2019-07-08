// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Operation.h"
#include "MultiOperation.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Abstract, Blueprintable)
class UTILITYAI_API UMultiOperation : public UOperation
{
	GENERATED_BODY()

	friend class UUtilityAIStatics;

public:
	TSet<UPredicate*> GetPredicates_Implementation() const override;

protected:

	// Operands

	UFUNCTION(BlueprintCallable)
	UExpression* Nth(int N) const;

	UFUNCTION(BlueprintCallable)
	const TArray<UExpression*>& Operands() const;

	// Results

	UFUNCTION(BlueprintCallable)
	bool NthResult(const TScriptInterface<IAgent>& Agent, int N) const;

	UFUNCTION(BlueprintCallable)
	TArray<bool> OperandsResults(const TScriptInterface<IAgent>& Agent) const;

	// Arguments

	UFUNCTION(BlueprintCallable)
	int NthArg(int N) const;

	UFUNCTION(BlueprintCallable)
	int ArgsNum() const;

	UFUNCTION(BlueprintCallable)
	const TArray<int>& Arguments() const;

private:
	UPROPERTY()
	TArray<UExpression*> Ops;

	TArray<int> Args;

	void Init(const TArray<UExpression*>& O, const TArray<int>& A);
};
