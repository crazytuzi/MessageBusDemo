// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IMessageBus.h"
#include "MessageEndpoint.h"
#include "MessageBusPublish.generated.h"

UCLASS()
class MESSAGEBUSDEMO_API AMessageBusPublish : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMessageBusPublish();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	/** Holds a pointer to the message bus. */
	TSharedPtr<IMessageBus, ESPMode::ThreadSafe> MessageBus;
	
	/** Holds the messaging endpoint. */
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> MessageEndpoint;
};
