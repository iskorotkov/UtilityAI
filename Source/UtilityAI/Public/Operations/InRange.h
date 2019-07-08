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

protected:
	bool ExpressionValue_Implementation(const TScriptInterface<IAgent>& Agent) override;
};
