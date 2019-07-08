// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Operation.h"
#include "TernaryOperation.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Abstract, Blueprintable)
class UTILITYAI_API UTernaryOperation : public UOperation
{
	GENERATED_BODY()

	friend class UUtilityAIStatics;

public:
	TSet<UPredicate*> GetPredicatesRecursively_Implementation() const override;

protected:
	UFUNCTION(BlueprintCallable)
	UExpression* First() const;

	UFUNCTION(BlueprintCallable)
	UExpression* Second() const;

	UFUNCTION(BlueprintCallable)
	UExpression* Third() const;

	UFUNCTION(BlueprintCallable)
	bool FirstResult(const TScriptInterface<IAgent>& Agent) const;

	UFUNCTION(BlueprintCallable)
	bool SecondResult(const TScriptInterface<IAgent>& Agent) const;

	UFUNCTION(BlueprintCallable)
	bool ThirdResult(const TScriptInterface<IAgent>& Agent) const;

private:
	UPROPERTY()
	UExpression* Operand1;

	UPROPERTY()
	UExpression* Operand2;

	UPROPERTY()
	UExpression* Operand3;

	void Init(UExpression* F, UExpression* S, UExpression* T);
};
