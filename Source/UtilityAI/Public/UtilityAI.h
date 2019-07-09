// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

class FUtilityAIModule : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	void StartupModule() override;
	void ShutdownModule() override;
};

DECLARE_LOG_CATEGORY_EXTERN(UtilityAI_Actions, Log, All)
DECLARE_LOG_CATEGORY_EXTERN(UtilityAI_Brains, Log, All)
DECLARE_LOG_CATEGORY_EXTERN(UtilityAI_Predicates, Log, All)
DECLARE_LOG_CATEGORY_EXTERN(UtilityAI_Operations, Log, All)
DECLARE_LOG_CATEGORY_EXTERN(UtilityAI_Components, Log, All)
DECLARE_LOG_CATEGORY_EXTERN(UtilityAI_Statics, Log, All)
DECLARE_LOG_CATEGORY_EXTERN(UtilityAI_Debugging, Log, All)
DECLARE_LOG_CATEGORY_EXTERN(UtilityAI, Log, All)
