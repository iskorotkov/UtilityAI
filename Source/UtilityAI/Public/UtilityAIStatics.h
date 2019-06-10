// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Action.h"
#include "UtilityAIStatics.generated.h"

/**
 * 
 */
UCLASS()
class UTILITYAI_API UUtilityAIStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static UAction* CreateAction(UObject* Outer, UClass* Class, TArray<UCondition*> Conditions);

	UFUNCTION(BlueprintCallable)
	static UCondition* CreateCondition(UObject* Outer, UClass* Class, UExpression* Expression);

	// TODO: add multiple variants of CreateExpression() method
	UFUNCTION(BlueprintCallable)
	static UExpression* CreateExpression(UObject* Outer, UClass* Class);
};
