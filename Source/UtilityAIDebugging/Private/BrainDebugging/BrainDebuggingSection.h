// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BrainDebuggingSection.generated.h"

class UBrainAsset;
/**
 * 
 */
UCLASS()
class UBrainDebuggingSection : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	virtual void SetBrain(UBrainAsset* Brain);

protected:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Reset();

	UFUNCTION()
	UBrainAsset* GetAssignedBrain() const;

private:
	UPROPERTY()
	UBrainAsset* AssignedBrain;
};
