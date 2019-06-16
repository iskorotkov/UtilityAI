// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BrainAsset.generated.h"

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
	UAction* SelectAction() const;
	virtual UAction* SelectAction_Implementation() const;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SetActions(const TArray<UAction*>& NewActions);
	virtual void SetActions_Implementation(const TArray<UAction*>& NewActions);

private:
	UPROPERTY(VisibleAnywhere)
	TArray<UAction*> Actions;
};
