// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UtilityAIBrainComponent.h"
#include "TimedBrainComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (UtilityAI), meta = (BlueprintSpawnableComponent, DisplayName = "Timed Brain"), Blueprintable)
class UTILITYAI_API UTimedBrainComponent : public UUtilityAIBrainComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void Start();

	UFUNCTION(BlueprintCallable)
	void Stop();

protected:
	void BeginPlay() override;

	void EndPlay(EEndPlayReason::Type EndPlayReason) override;

private:
	UPROPERTY(EditAnywhere)
	float Rate = 0.2f;

	UPROPERTY(EditAnywhere)
	float FirstDelay = 0.f;

	FTimerHandle Handle;
};
