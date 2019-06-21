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

	UFUNCTION(BlueprintCallable)
	void SetActions(const TArray<UAction*>& NewActions);

protected:
	UFUNCTION(BlueprintNativeEvent)
	TArray<UAction*> GetActions() const;
	virtual TArray<UAction*> GetActions_Implementation() const;

	void PostInitProperties() override;

private:
	UPROPERTY(VisibleAnywhere)
	TArray<UAction*> Actions;
};
