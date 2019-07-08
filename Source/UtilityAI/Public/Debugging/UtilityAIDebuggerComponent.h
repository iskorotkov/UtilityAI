// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DebuggerSettings.h"
#include "UtilityAIDebuggerComponent.generated.h"

class UUtilityAIBrainComponent;
UCLASS(ClassGroup=(UtilityAI), meta=(BlueprintSpawnableComponent), DisplayName="Utility AI Debugger")
class UTILITYAI_API UUtilityAIDebuggerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UUtilityAIDebuggerComponent();

protected:
	// Called when the game starts
	void BeginPlay() override;

	// Called every frame
	void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(EditAnywhere)
	bool bIsDebugEnabled = true;

	UPROPERTY(EditAnywhere)
	FDebuggerSettings Settings;

	UPROPERTY(VisibleAnywhere)
	TMap<FString, FString> State;

	UPROPERTY()
	UUtilityAIBrainComponent* BrainComponent;

	UFUNCTION()
	void ReactOnActionRun(FString ActionName);

	void StartDebugging();
};
