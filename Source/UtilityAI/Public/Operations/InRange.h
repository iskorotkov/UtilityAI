// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Operations/MultiOperation.h"
#include "InRange.generated.h"

/**
 * 
 */
UCLASS()
class UTILITYAI_API UInRange : public UMultiOperation
{
	GENERATED_BODY()

public:
	bool Evaluate_Implementation(const TScriptInterface<IAgent>& Agent) override;
};
