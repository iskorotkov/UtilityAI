// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UtilityAIStatics.generated.h"

class UOperation;
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
	// Creating and setting up base objects

	UFUNCTION(Category="Utility AI", BlueprintPure)
	static UAction* CreateAction(TSubclassOf<UAction> Class, TArray<UCondition*> Conditions);

	UFUNCTION(Category="Utility AI", BlueprintPure)
	static UCondition* CreateCondition(TSubclassOf<UCondition> Class, UExpression* Expression, float Success = 1.f, float Failure = 0.f);

	UFUNCTION(Category="Utility AI", BlueprintPure)
	static UExpression* CreateUnaryOperation(TSubclassOf<UUnaryOperation> Class, UExpression* Operand);

	UFUNCTION(Category="Utility AI", BlueprintPure)
	static UExpression* CreateBinaryOperation(TSubclassOf<UBinaryOperation> Class, UExpression* Operand1, UExpression* Operand2);

	UFUNCTION(Category="Utility AI", BlueprintPure)
	static UExpression* CreateTernaryOperation(TSubclassOf<UTernaryOperation> Class, UExpression* Operand1, UExpression* Operand2, UExpression* Operand3);

	UFUNCTION(Category="Utility AI", BlueprintPure)
	static UExpression* CreateMultiOperation(TSubclassOf<UMultiOperation> Class, TArray<UExpression*> Operands);

	UFUNCTION(Category="Utility AI", BlueprintPure)
	static UExpression* CreatePredicate(TSubclassOf<UPredicate> Class);

	// Creating pre-defined objects

	UFUNCTION(Category = "Utility AI", BlueprintPure)
	static UAction* CreateDefaultAction(TSubclassOf<UAction> Class);

	UFUNCTION(Category = "Utility AI", BlueprintPure)
	static UCondition* CreateDefaultCondition(TSubclassOf<UCondition> Class);

	UFUNCTION(Category = "Utility AI", BlueprintPure)
	static UExpression* CreateDefaultOperation(TSubclassOf<UOperation> Class);

private:
	static UObject* GetOuter();
};
