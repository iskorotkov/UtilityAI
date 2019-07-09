// Fill out your copyright notice in the Description page of Project Settings.

#include "Debugging/UtilityAIDebuggerComponent.h"
#include "GameFramework/Actor.h"
#include "UtilityAIBrainComponent.h"
#include "UtilityAI.h"
#include "BrainAsset.h"
#include "Action.h"
#include "Predicate.h"
#include "Expression.h"

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

void UUtilityAIDebuggerComponent::ReactOnActionEvaluated(FString ActionName, float Value)
{
	if (GetSettings().bStripActionNames)
	{
		ActionName = StripName(ActionName);
	}
	ActionsState.Emplace(ActionName, Value);
}

void UUtilityAIDebuggerComponent::ReactOnPredicateEvaluated(FString PredicateName, bool Success)
{
	if (GetSettings().bStripPredicateNames)
	{
		PredicateName = StripName(PredicateName);
	}
	PredicatesState.Emplace(PredicateName, Success);
}

void UUtilityAIDebuggerComponent::BindBrainComponent()
{
	BrainComponent->OnActionRun.AddDynamic(this, &UUtilityAIDebuggerComponent::ReactOnActionRun);
}

void UUtilityAIDebuggerComponent::BindActions()
{
	const auto& Actions = BrainComponent->GetBrainAsset()->GetActions();
	for (const auto Action : Actions)
	{
		Action->OnEvaluated.AddDynamic(this, &UUtilityAIDebuggerComponent::ReactOnActionEvaluated);
	}
}

void UUtilityAIDebuggerComponent::BindPredicates()
{
	const auto& Actions = BrainComponent->GetBrainAsset()->GetActions();
	UExpression::FPredicatesContainer Predicates;
	for (const auto Action : Actions)
	{
		const auto& Conditions = Action->GetConditions();
		for (const auto& Condition : Conditions)
		{
			Condition.GetPredicate(BrainComponent)->GetPredicatesRecursively(Predicates);
		}
	}
	for (auto& Predicate : Predicates)
	{
		Predicate->OnEvaluated.AddDynamic(this, &UUtilityAIDebuggerComponent::ReactOnPredicateEvaluated);
	}
}

const FDebuggerSettings& UUtilityAIDebuggerComponent::GetSettings() const
{
	return Settings;
}

FString UUtilityAIDebuggerComponent::StripName(const FString& Name) const
{
	auto Index = Name.Len() - 1;
	Name.FindLastChar('_', Index);
	--Index;
	Name.FindLastChar('_', Index);
	return Name.Left(Index-2);
}

void UUtilityAIDebuggerComponent::StartDebugging()
{
	if (BrainComponent == nullptr)
	{
		UE_LOG(UtilityAI_Debugging, Warning, TEXT("There is no Utility AI Brain Component found"));
		return;
	}
	BindBrainComponent();
	BindActions();
	BindPredicates();
}
