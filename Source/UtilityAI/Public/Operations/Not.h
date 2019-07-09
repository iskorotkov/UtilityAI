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

protected:
	bool ExpressionValue_Implementation(const TScriptInterface<IAgent>& Agent) override;
};
