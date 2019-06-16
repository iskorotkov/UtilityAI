// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BrainAsset.generated.h"

class UAction;
/**
 * 
 */
UCLASS(BlueprintType, Abstract)
class UTILITYAI_API UBrainAsset : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	virtual UAction* SelectAction() const;

	UFUNCTION(BlueprintCallable)
	virtual void SetActions(const TArray<UAction*>& NewActions);

private:
	UPROPERTY(EditAnywhere)
	TArray<UAction*> Actions;
};
