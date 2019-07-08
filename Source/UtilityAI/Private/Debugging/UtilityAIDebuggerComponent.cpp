// Fill out your copyright notice in the Description page of Project Settings.

#include "Debugging/UtilityAIDebuggerComponent.h"
#include "GameFramework/Actor.h"
#include "UtilityAIBrainComponent.h"
#include "UtilityAI.h"

// Sets default values for this component's properties
UUtilityAIDebuggerComponent::UUtilityAIDebuggerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UUtilityAIDebuggerComponent::BeginPlay()
{
	Super::BeginPlay();
	if (const auto Component = GetOwner()->GetComponentByClass(UUtilityAIBrainComponent::StaticClass()))
	{
		BrainComponent = Cast<UUtilityAIBrainComponent>(Component);
	}
	StartDebugging();
}

// Called every frame
void UUtilityAIDebuggerComponent::TickComponent(const float DeltaTime, const ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UUtilityAIDebuggerComponent::ReactOnActionRun(FString ActionName)
{
	State.Emplace(TEXT("Active action"), ActionName);
}

void UUtilityAIDebuggerComponent::StartDebugging()
{
	if (BrainComponent == nullptr)
	{
		UE_LOG(UtilityAI_Debugging, Warning, TEXT("There is no Utility AI Brain Component found"));
		return;
	}
	BrainComponent->OnActionRun.AddDynamic(this, &UUtilityAIDebuggerComponent::ReactOnActionRun);
}
