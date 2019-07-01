// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Operations/UnaryOperation.h"
#include "Not.generated.h"

/**
 * 
 */
UCLASS()
class UTILITYAI_API UNot : public UUnaryOperation
{
	GENERATED_BODY()

public:
	bool Evaluate_Implementation(const TScriptInterface<IAgent>& Agent) override;
};
