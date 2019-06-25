// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BrainAsset.generated.h"

class IAgent;
class UAction;
/**
 * 
 */
UCLASS(BlueprintType, Abstract, Blueprintable, EditInlineNew)
class UTILITYAI_API UBrainAsset : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	UAction* SelectAction(const TScriptInterface<IAgent>& Agent) const;
	virtual UAction* SelectAction_Implementation(const TScriptInterface<IAgent>& Agent) const;

private:
	UPROPERTY(EditAnywhere, Instanced)
	TArray<UAction*> Actions;
};
