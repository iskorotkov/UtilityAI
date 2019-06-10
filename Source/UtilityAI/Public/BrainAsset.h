// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Action.h"
#include "BrainAsset.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Abstract)
class UTILITYAI_API UBrainAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	virtual UAction* SelectAction() const = 0;

private:
	UPROPERTY(EditAnywhere)
	TArray<UAction*> Actions;
};
