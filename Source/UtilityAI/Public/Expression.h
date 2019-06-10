// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Expression.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class UTILITYAI_API UExpression : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	virtual bool Evaluate() const;
};
