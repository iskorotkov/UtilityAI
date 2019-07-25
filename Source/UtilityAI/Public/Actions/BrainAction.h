// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actions/Action.h"
#include "BrainAction.generated.h"

class UBrainAsset;
/**
 * 
 */
UCLASS()
class UTILITYAI_API UBrainAction : public UAction
{
	GENERATED_BODY()

public:
	void Run_Implementation(const TScriptInterface<IAgent>& Agent) const override;

	UBrainAsset* GetBrain();

private:
	UPROPERTY(EditAnywhere)
	UBrainAsset* Brain;
};
