// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Operation.h"
#include "BinaryOperation.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Abstract, Blueprintable)
class UTILITYAI_API UBinaryOperation : public UOperation
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	UExpression* First() const;

	UFUNCTION(BlueprintCallable)
	UExpression* Second() const;

	UFUNCTION(BlueprintCallable)
	bool FirstResult(const TScriptInterface<IAgent>& Agent) const;

	UFUNCTION(BlueprintCallable)
	bool SecondResult(const TScriptInterface<IAgent>& Agent) const;

private:
	UPROPERTY()
	UExpression* Operand1;

	UPROPERTY()
	UExpression* Operand2;
};
