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

public:
	TSet<UPredicate*> GetPredicates_Implementation() const override;
};
