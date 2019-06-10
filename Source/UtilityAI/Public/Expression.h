// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Expression.generated.h"

/**
 * 
 */
// TODO: make abstract
UCLASS(BlueprintType)
class UTILITYAI_API UExpression : public UObject
{
	GENERATED_BODY()

public:
	// TODO: make pure virtual
	UFUNCTION(BlueprintCallable)
	virtual bool Evaluate() const { return true; }
};
