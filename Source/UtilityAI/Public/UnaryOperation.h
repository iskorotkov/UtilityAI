// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Operation.h"
#include "UnaryOperation.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Abstract, Blueprintable)
class UTILITYAI_API UUnaryOperation : public UOperation
{
	GENERATED_BODY()

private:
	UPROPERTY()
	UExpression* Operand;
};
