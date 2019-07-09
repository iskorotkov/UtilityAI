// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "UtilityAI.h"

#define LOCTEXT_NAMESPACE "FUtilityAIModule"

void FUtilityAIModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FUtilityAIModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FUtilityAIModule, UtilityAI)

DEFINE_LOG_CATEGORY(UtilityAI_Actions)
DEFINE_LOG_CATEGORY(UtilityAI_Brains)
DEFINE_LOG_CATEGORY(UtilityAI_Predicates)
DEFINE_LOG_CATEGORY(UtilityAI_Operations)
DEFINE_LOG_CATEGORY(UtilityAI_Components)
DEFINE_LOG_CATEGORY(UtilityAI_Statics)
DEFINE_LOG_CATEGORY(UtilityAI_Debugging)
DEFINE_LOG_CATEGORY(UtilityAI)
