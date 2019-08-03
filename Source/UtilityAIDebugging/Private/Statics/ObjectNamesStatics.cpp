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

FString UObjectNamesStatics::StripNestedObjectName(UObject* Self, UObject* StopOuter)
{
	check(Self);
	check(StopOuter);
	const auto Name = Self->GetPathName(StopOuter);
	return StripNestedObjectName(Name);
}

FString UObjectNamesStatics::StripNestedObjectName(const FString NestedName)
{
	const auto Parts = SplitName(NestedName);
	return StripAndAppendSubstrings(Parts);
}

FString UObjectNamesStatics::StripAndAppendSubstrings(const TArray<FString>& Parts)
{
	auto Result = Parts[0];
	for (auto Index = 1, Len = Parts.Num(); Index < Len; ++Index)
	{
		Result.AppendChar('.');
		const auto Name = Parts[Index];
		const auto PrettyName = StripObjectName(Name);
		Result.Append(PrettyName);
	}
	return Result;
}

TArray<FString> UObjectNamesStatics::SplitName(const FString& Name, const char Symbol)
{
	const auto ExtractLastWord = [](const FString& Name, const int Start, const int End)
	{
		return Name.Mid(Start, End - Start + 1);
	};
	const auto ExtractWord = [](const FString& Name, const int Start, const int End)
	{
		return Name.Mid(Start, End - Start);
	};
	TArray<FString> Parts;
	for (auto Start = 0, Index = 0, Len = Name.Len();
		Index < Len;
		++Index)
	{
		if (Name[Index] == Symbol)
		{
			Parts.Add(ExtractWord(Name, Start, Index));
			Start = Index + 1;
		}
		else if (Index == Len - 1
			&& Start < Index)
		{
			Parts.Add(ExtractLastWord(Name, Start, Index));
		}
	}
	return Parts;
}
