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

protected:
	UFUNCTION(BlueprintCallable)
	const TArray<UExpression*>& Operands() const;

	UFUNCTION(BlueprintCallable)
	TArray<bool> OperandsResult(const TScriptInterface<IAgent>& Agent) const;

private:
	UPROPERTY()
	TArray<UExpression*> Ops;
};
