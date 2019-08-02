// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ObjectNamesStatics.generated.h"

/**
 * 
 */
UCLASS()
class UObjectNamesStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static FString StripObjectName(UObject* Object);
	static FString StripObjectName(FString Name);
};
