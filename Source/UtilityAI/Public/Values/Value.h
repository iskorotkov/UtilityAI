// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Value.generated.h"

class IAgent;
/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class UTILITYAI_API UValue : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	float Evaluate(const TScriptInterface<IAgent>& Agent);
};
