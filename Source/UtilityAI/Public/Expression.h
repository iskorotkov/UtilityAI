// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Expression.generated.h"

class IAgent;
/**
 * 
 */
UCLASS(BlueprintType, Abstract)
class UTILITYAI_API UExpression : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	bool Evaluate(const TScriptInterface<IAgent>& Agent);
	virtual bool Evaluate_Implementation(const TScriptInterface<IAgent>& Agent);
};
