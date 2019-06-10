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
	UFUNCTION(Category="Utility AI", BlueprintPure, meta=(WorldContext="Outer"))
	static UAction* CreateAction(UObject* Outer, TSubclassOf<UAction> Class, TArray<UCondition*> Conditions);

	UFUNCTION(Category="Utility AI", BlueprintPure, meta=(WorldContext="Outer"))
	static UCondition* CreateCondition(UObject* Outer, TSubclassOf<UCondition> Class, UExpression* Expression);

	UFUNCTION(Category="Utility AI", BlueprintPure, meta=(WorldContext="Outer"))
	static UExpression* CreateUnaryExpression(UObject* Outer, TSubclassOf<UExpression> Class, UExpression* Operand);

	UFUNCTION(Category="Utility AI", BlueprintPure, meta=(WorldContext="Outer"))
	static UExpression* CreateBinaryExpression(UObject* Outer, TSubclassOf<UExpression> Class, UExpression* Operand1, UExpression* Operand2);

	UFUNCTION(Category="Utility AI", BlueprintPure, meta=(WorldContext="Outer"))
	static UExpression* CreateTernaryExpression(UObject* Outer, TSubclassOf<UExpression> Class, UExpression* Operand1, UExpression* Operand2, UExpression* Operand3);

	UFUNCTION(Category="Utility AI", BlueprintPure, meta=(WorldContext="Outer"))
	static UExpression* CreateMultiExpression(UObject* Outer, TSubclassOf<UExpression> Class, TArray<UExpression*> Operands);
};
