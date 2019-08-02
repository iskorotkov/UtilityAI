// Fill out your copyright notice in the Description page of Project Settings.

#include "ObjectNamesStatics.h"

FString UObjectNamesStatics::StripObjectName(UObject* Object)
{
	check(Object);
	return StripObjectName(Object->GetName());
}

FString UObjectNamesStatics::StripObjectName(const FString Name)
{
	auto Index = Name.Len() - 1;
	auto UnderscoresToIgnore = 2;
	while (Index >= 0 && UnderscoresToIgnore > 0)
	{
		if (Name[Index] == '_')
		{
			--UnderscoresToIgnore;
		}
		--Index;
	}
	return Name.Left(Index + 1);
}
