// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BrainAsset.generated.h"

class IAgent;
class UAction;
/**
 * 
 */
UCLASS(BlueprintType, Abstract, Blueprintable)
class UTILITYAI_API UBrainAsset : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	UAction* SelectAction(const TScriptInterface<IAgent>& Agent);
	virtual UAction* SelectAction_Implementation(const TScriptInterface<IAgent>& Agent);

	void CreateActions(const TScriptInterface<IAgent>& Agent);

private:
	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<UAction>> ActionClasses;

	UPROPERTY()
	TArray<UAction*> Actions;
};
