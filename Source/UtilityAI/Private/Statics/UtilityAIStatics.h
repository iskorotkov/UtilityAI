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
class AAIController;
class IAgent;
/**
 * 
 */
UCLASS()
class UTILITYAI_API UUtilityAIStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	// Creating and setting up base objects

	UFUNCTION(Category="Utility AI|Statics", BlueprintPure)
	static UExpression* CreateUnaryOperation(TSubclassOf<UUnaryOperation> Class, UExpression* Operand);

	UFUNCTION(Category="Utility AI|Statics", BlueprintPure)
	static UExpression* CreateBinaryOperation(TSubclassOf<UBinaryOperation> Class, UExpression* Operand1, UExpression* Operand2);

	UFUNCTION(Category="Utility AI|Statics", BlueprintPure)
	static UExpression* CreateTernaryOperation(TSubclassOf<UTernaryOperation> Class, UExpression* Operand1, UExpression* Operand2, UExpression* Operand3);

	UFUNCTION(Category="Utility AI|Statics", BlueprintPure)
	static UExpression* CreateMultiOperation(TSubclassOf<UMultiOperation> Class, TArray<UExpression*> Operands);

	UFUNCTION(Category="Utility AI|Statics", BlueprintPure)
	static UExpression* CreatePredicate(TSubclassOf<UPredicate> Class);

	// IAgent utility functions

	UFUNCTION(Category = "Utility AI|Statics", BlueprintPure)
	static AAIController* AsAIController(const TScriptInterface<IAgent>& Agent);

private:
	static UObject* GetOuter();
};
