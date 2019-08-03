// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

class FUtilityAIDebuggingModule : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	void StartupModule() override;
	void ShutdownModule() override;
};

DECLARE_LOG_CATEGORY_EXTERN(UtilityAI_Debugging, Log, All)
