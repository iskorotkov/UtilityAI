// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "UtilityAIBrainComponent.generated.h"

class UBrainAsset;
UCLASS(ClassGroup=(UtilityAI), meta=(BlueprintSpawnableComponent))
class UTILITYAI_API UUtilityAIBrainComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UUtilityAIBrainComponent();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Act() const;
	virtual void Act_Implementation() const;

protected:
	void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UBrainAsset> BrainAssetClass;

	UPROPERTY()
	UBrainAsset* Asset;
};
