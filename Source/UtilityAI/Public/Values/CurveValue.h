// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Values/Value.h"
#include "SubclassOf.h"
#include "CurveValue.generated.h"

class UCurveFloat;
/**
 * 
 */
UCLASS()
class UTILITYAI_API UCurveValue : public UValue
{
	GENERATED_BODY()

public:
	float GetValue_Implementation(const TScriptInterface<IAgent>& Agent) override;

private:
	UPROPERTY(EditAnywhere)
	UCurveFloat* Curve;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UValue> SourceClass;

	UPROPERTY()
	UValue* Source;
};
