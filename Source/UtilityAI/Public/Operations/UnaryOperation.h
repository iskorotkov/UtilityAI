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

	friend class UUtilityAIStatics;

public:
	TSet<UPredicate*> GetPredicates_Implementation() const override;

protected:
	UFUNCTION(BlueprintCallable)
	UExpression* First() const;

	UFUNCTION(BlueprintCallable)
	bool FirstResult(const TScriptInterface<IAgent>& Agent) const;

private:
	UPROPERTY()
	UExpression* Operand;

	void Init(UExpression* F);
};
