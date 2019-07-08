// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Predicate.h"
#include "ComplexPredicate.generated.h"

/**
 * 
 */
UCLASS()
class UTILITYAI_API UComplexPredicate : public UPredicate
{
	GENERATED_BODY()

public:
	bool ExpressionValue_Implementation(const TScriptInterface<IAgent>& Agent) override;

protected:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	UExpression* AssignExpression(const TScriptInterface<IAgent>& Agent) const;

private:
	UPROPERTY()
	UExpression* Expression;
};
