// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "UtilityAIBrainComponent.generated.h"

class UBrainAsset;
UCLASS(ClassGroup=(UtilityAI), meta=(BlueprintSpawnableComponent, DisplayName="Utility AI Brain"), Blueprintable)
class UTILITYAI_API UUtilityAIBrainComponent : public UActorComponent
{
	GENERATED_BODY()

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBrainSignature);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FActionSignature, FString, ActionName);

public:
	UUtilityAIBrainComponent();

	FBrainSignature OnBeforeAct;
	FBrainSignature OnAfterAct;

	FActionSignature OnActionRun;

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
