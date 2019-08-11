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

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FValueSignature, FString, Name, float, Value);

public:
	FValueSignature OnEvaluated;
	
	UFUNCTION(BlueprintCallable)
	float Evaluate(const TScriptInterface<IAgent>& Agent);

protected:
	UFUNCTION(BlueprintNativeEvent)
	float GetValue(const TScriptInterface<IAgent>& Agent);

private:
	UPROPERTY(EditAnywhere)
	float Multiplier = 1.f;
};
