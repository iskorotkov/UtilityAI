// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Operations/TernaryOperation.h"
#include "Select.generated.h"

/**
 * 
 */
UCLASS()
class UTILITYAI_API USelect : public UTernaryOperation
{
	GENERATED_BODY()

protected:
	bool ExpressionValue_Implementation(const TScriptInterface<IAgent>& Agent) override;
};
