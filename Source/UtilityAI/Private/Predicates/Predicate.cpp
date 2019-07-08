// Fill out your copyright notice in the Description page of Project Settings.

#include "Predicate.h"

TSet<UPredicate*> UPredicate::GetPredicates_Implementation() const
{
	TSet<UPredicate*> Predicates;
	Predicates.Emplace(this);
	return Predicates;
}
