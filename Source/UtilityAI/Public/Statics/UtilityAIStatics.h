// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BrainAction.h"
#include "UtilityAIDebuggerComponent.h"
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
	// TODO: move methods in separate files

	// Creating and setting up base objects

	UFUNCTION(Category="Utility AI|Statics", BlueprintPure)
	static UExpression* CreateUnaryOperation(TSubclassOf<UUnaryOperation> Class, UExpression* Operand);

	UFUNCTION(Category="Utility AI|Statics", BlueprintPure)
	static UExpression* CreateBinaryOperation(TSubclassOf<UBinaryOperation> Class, UExpression* Operand1, UExpression* Operand2);

	UFUNCTION(Category="Utility AI|Statics", BlueprintPure)
	static UExpression* CreateTernaryOperation(TSubclassOf<UTernaryOperation> Class, UExpression* Operand1, UExpression* Operand2, UExpression* Operand3);

	UFUNCTION(Category="Utility AI|Statics", BlueprintPure)
	static UExpression* CreateMultiOperation(TSubclassOf<UMultiOperation> Class, TArray<UExpression*> Operands, TArray<int> Arguments);

	UFUNCTION(Category="Utility AI|Statics", BlueprintPure)
	static UExpression* CreatePredicate(TSubclassOf<UPredicate> Class);

	// IAgent utility functions

	UFUNCTION(Category = "Utility AI|Statics", BlueprintPure)
	static AAIController* AsAIController(const TScriptInterface<IAgent>& Agent);

	UFUNCTION(Category = "Utility AI|Statics", BlueprintPure)
	static AActor* AsActor(const TScriptInterface<IAgent>& Agent);

	// Access to predicates, actions and brains

	UFUNCTION(Category = "Utility AI|Statics", BlueprintPure)
	static UBrainAsset* GetBrain(UUtilityAIBrainComponent* BrainComponent);

	UFUNCTION(Category = "Utility AI|Statics", BlueprintPure)
	static TArray<UBrainAsset*> GetBrainsRecursively(UUtilityAIBrainComponent* BrainComponent);

	UFUNCTION(Category = "Utility AI|Statics", BlueprintPure)
	static TArray<UAction*> GetActions(UUtilityAIBrainComponent* BrainComponent);

	UFUNCTION(Category = "Utility AI|Statics", BlueprintPure)
	static TArray<UAction*> GetActionsRecursively(UUtilityAIBrainComponent* BrainComponent);

	UFUNCTION(Category = "Utility AI|Statics", BlueprintPure)
	static TArray<UPredicate*> GetPredicates(UUtilityAIBrainComponent* BrainComponent);

	UFUNCTION(Category = "Utility AI|Statics", BlueprintPure)
	static TArray<UPredicate*> GetPredicatesRecursively(UUtilityAIBrainComponent* BrainComponent);

private:
	static UObject* GetOuter();

	static void GetActions_Internal(TArray<UAction*>& Actions, UAction* Action);
};
