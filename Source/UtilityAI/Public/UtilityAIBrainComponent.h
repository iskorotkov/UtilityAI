// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "UtilityAIBrainComponent.generated.h"

UCLASS(ClassGroup=(UtilityAI), Abstract, meta=(BlueprintSpawnableComponent))
class UTILITYAI_API UUtilityAIBrainComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UUtilityAIBrainComponent();

	UFUNCTION(BlueprintCallable)
	virtual void Act() const = 0;

private:
	UPROPERTY()
	UBrainAsset* Asset;
};
