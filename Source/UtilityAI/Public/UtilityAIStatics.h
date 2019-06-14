// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UtilityAIStatics.generated.h"

class UPredicate;
class UMultiOperation;
class UTernaryOperation;
class UBinaryOperation;
class UUnaryOperation;
class UExpression;
class UCondition;
class UAction;
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
	static UCondition* CreateCondition(UObject* Outer, TSubclassOf<UCondition> Class, UExpression* Expression, float Success=1.f, float Failure=0.f);

	UFUNCTION(Category="Utility AI", BlueprintPure, meta=(WorldContext="Outer"))
	static UExpression* CreateUnaryOperation(UObject* Outer, TSubclassOf<UUnaryOperation> Class, UExpression* Operand);

	UFUNCTION(Category="Utility AI", BlueprintPure, meta=(WorldContext="Outer"))
	static UExpression* CreateBinaryOperation(UObject* Outer, TSubclassOf<UBinaryOperation> Class, UExpression* Operand1, UExpression* Operand2);

	UFUNCTION(Category="Utility AI", BlueprintPure, meta=(WorldContext="Outer"))
	static UExpression* CreateTernaryOperation(UObject* Outer, TSubclassOf<UTernaryOperation> Class, UExpression* Operand1, UExpression* Operand2, UExpression* Operand3);

	UFUNCTION(Category="Utility AI", BlueprintPure, meta=(WorldContext="Outer"))
	static UExpression* CreateMultiOperation(UObject* Outer, TSubclassOf<UMultiOperation> Class, TArray<UExpression*> Operands);

	UFUNCTION(Category="Utility AI", BlueprintPure, meta=(WorldContext="Outer"))
	static UExpression* CreatePredicate(UObject* Outer, TSubclassOf<UPredicate> Class);
};
