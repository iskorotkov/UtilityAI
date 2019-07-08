// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Operations/BinaryOperation.h"
#include "And.generated.h"

/**
 * 
 */
UCLASS()
class UTILITYAI_API UAnd : public UBinaryOperation
{
	GENERATED_BODY()

protected:
	bool ExpressionValue_Implementation(const TScriptInterface<IAgent>& Agent) override;
};
