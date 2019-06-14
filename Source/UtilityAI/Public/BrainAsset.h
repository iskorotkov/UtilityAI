// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BrainAsset.generated.h"

class UAction;
/**
 * 
 */
UCLASS(BlueprintType)
class UTILITYAI_API UBrainAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	virtual UAction* SelectAction() const;

private:
	UPROPERTY(EditAnywhere)
	TArray<UAction*> Actions;
};
