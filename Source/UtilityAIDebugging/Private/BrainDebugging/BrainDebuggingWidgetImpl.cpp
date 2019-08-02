// Fill out your copyright notice in the Description page of Project Settings.

#include "BrainDebuggingWidgetImpl.h"
#include "Editor.h"
#include "Engine/Selection.h"
#include "UtilityAIBrainComponent.h"
#include "UtilityAIStatics.h"
#include "BrainAsset.h"
#include "ComboBoxString.h"
#include "Statics/ObjectNamesStatics.h"

void UBrainDebuggingWidgetImpl::SelectActor()
{
	if (GEditor)
	{
		const auto Selection = GEditor->GetSelectedActors();
		if (Selection->Num() == 1)
		{
			SelectedActor = Selection->GetTop<AActor>();
			if (SelectedActor && !SelectedActor->IsPendingKillPending())
			{
				if (const auto BrainComponent = SelectedActor->FindComponentByClass<UUtilityAIBrainComponent>())
				{
					ExtractComponentInfo(BrainComponent);
				}
				else
				{
					// TODO: log error: actor has no attached brain component
				}
			}
		}
		else
		{
			// TODO: log error: no actors or too many actors selected
		}
	}
}

TArray<FString> UBrainDebuggingWidgetImpl::GetBrainOptions() const
{
	return ActorBrainsNames;
}

void UBrainDebuggingWidgetImpl::SelectBrain(const FString SelectedItem)
{
	if (!SelectedActor || SelectedActor->IsPendingKillPending())
	{
		return;
	}
	if (SelectedItem.IsEmpty())
	{
		return;
	}
	const auto Index = ActorBrainsNames.IndexOfByKey(SelectedItem);
	if (ActorBrains.IsValidIndex(Index))
	{
		SelectedBrain = ActorBrains[Index];
	}
	OnBrainSelected(SelectedBrain);
}

void UBrainDebuggingWidgetImpl::FillBrainComboBox(UComboBoxString* ComboBox)
{
	ResetBrainComboBox(ComboBox);
	const auto Options = GetBrainOptions();
	if (Options.Num() > 0)
	{
		for (const auto& Str : Options)
		{
			ComboBox->AddOption(Str);
		}
		ComboBox->SetSelectedIndex(0);
	}
}

void UBrainDebuggingWidgetImpl::ResetBrainComboBox(UComboBoxString* ComboBox)
{
	ComboBox->ClearOptions();
	ComboBox->ClearOptions();
}

void UBrainDebuggingWidgetImpl::ExtractComponentInfo(UUtilityAIBrainComponent* const BrainComponent)
{
	ActorBrains = UUtilityAIStatics::GetBrainsRecursively(BrainComponent->GetBrainAsset());
	ActorBrainsNames.Empty();
	for (const auto Brain : ActorBrains)
	{
		const auto Name = Brain->GetPathName(BrainComponent);
		const auto PrettyName = UObjectNamesStatics::StripNestedObjectName(Brain, BrainComponent);
		ActorBrainsNames.Add(PrettyName);
	}
}
