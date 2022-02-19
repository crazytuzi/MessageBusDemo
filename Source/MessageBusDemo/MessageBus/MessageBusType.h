// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MessageBusType.generated.h"

USTRUCT()
struct FTestMessage
{
	GENERATED_USTRUCT_BODY()

	FString Val;

	FTestMessage() = default;

	explicit FTestMessage(FString InVal):Val(InVal)
	{
		
	};
};
