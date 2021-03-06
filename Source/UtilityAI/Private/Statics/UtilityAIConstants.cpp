// Fill out your copyright notice in the Description page of Project Settings.

#include "UtilityAIConstants.h"

float UUtilityAIConstants::MinActionRating()
{
	return 0.0f;
}

float UUtilityAIConstants::MaxActionRating()
{
	return 1.0f;
}

float UUtilityAIConstants::AbsoluteMin()
{
	return MinActionRating() - 1.f;
}

float UUtilityAIConstants::AbsoluteMax()
{
	return MaxActionRating() + 1.f;
}
