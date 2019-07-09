// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DebuggerSettings.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct UTILITYAI_API FDebuggerSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	bool bStripPredicateNames = true;

	UPROPERTY(EditAnywhere)
	bool bStripActionNames = true;
};
