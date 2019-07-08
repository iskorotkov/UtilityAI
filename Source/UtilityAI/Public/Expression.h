// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Expression.generated.h"

class UPredicate;
class IAgent;
/**
 * 
 */
UCLASS(BlueprintType, Abstract)
class UTILITYAI_API UExpression : public UObject
{
	GENERATED_BODY()

public:
	using FPredicatesContainer = TSet<UPredicate*>;
	using FPredicatesContainerRef = FPredicatesContainer&;

	UFUNCTION(BlueprintCallable)
	virtual bool Evaluate(const TScriptInterface<IAgent>& Agent);

	virtual void GetPredicatesRecursively(FPredicatesContainerRef Predicates);

protected:
	UFUNCTION(BlueprintNativeEvent)
	bool ExpressionValue(const TScriptInterface<IAgent>& Agent);
	virtual bool ExpressionValue_Implementation(const TScriptInterface<IAgent>& Agent);
};
