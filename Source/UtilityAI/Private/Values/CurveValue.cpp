// Fill out your copyright notice in the Description page of Project Settings.

#include "CurveValue.h"
#include "Curves/CurveFloat.h"

float UCurveValue::GetValue_Implementation(const TScriptInterface<IAgent>& Agent)
{
	check(Curve);
	if (!Source)
	{
		Source = NewObject<UValue>(this, SourceClass);
		check(Source);
	}
	const auto Value = Source->Evaluate(Agent);
	return Curve->GetFloatValue(Value);
}
