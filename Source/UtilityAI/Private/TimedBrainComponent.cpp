// Fill out your copyright notice in the Description page of Project Settings.

#include "TimedBrainComponent.h"
#include "Engine/World.h"
#include "TimerManager.h"

void UTimedBrainComponent::Start()
{
	if (!Handle.IsValid())
	{
		GetWorld()->GetTimerManager().SetTimer(Handle, Rate, true, FirstDelay);
	}
}

void UTimedBrainComponent::Stop()
{
	if (Handle.IsValid())
	{
		GetWorld()->GetTimerManager().ClearTimer(Handle);
	}
}

void UTimedBrainComponent::BeginPlay()
{
	Super::BeginPlay();
	Start();
}

void UTimedBrainComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	Stop();
}
