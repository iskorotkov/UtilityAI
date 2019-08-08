// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actions/Action.h"
#include "CompoundAction.generated.h"

/**
 * 
 */
UCLASS()
class UTILITYAI_API UCompoundAction : public UAction
{
	GENERATED_BODY()

public:
	void Run_Implementation(const TScriptInterface<IAgent>& Agent) override;

private:
	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<UAction>> ActionsClasses;

	TArray<TStrongObjectPtr<UAction>> Actions;

	void PrepareActions();
	void RunActions(const TScriptInterface<IAgent>& Agent);
};
