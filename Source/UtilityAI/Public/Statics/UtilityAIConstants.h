// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UtilityAIConstants.generated.h"

/**
 * 
 */
UCLASS()
class UTILITYAI_API UUtilityAIConstants : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(Category = "Utility AI|Constants", BlueprintPure)
	static float MinActionRating();

	UFUNCTION(Category = "Utility AI|Constants", BlueprintPure)
	static float MaxActionRating();

	UFUNCTION(Category = "Utility AI|Constants", BlueprintPure)
	static float AbsoluteMin();

	UFUNCTION(Category = "Utility AI|Constants", BlueprintPure)
	static float AbsoluteMax();
};
