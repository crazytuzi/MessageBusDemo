// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IMessageBus.h"
#include "MessageEndpoint.h"
#include "IMessageContext.h"
#include "MessageBusType.h"
#include "MessageBusSubscribe.generated.h"

UCLASS()
class MESSAGEBUSDEMO_API AMessageBusSubscribe : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMessageBusSubscribe();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	void OnReceive(const FTestMessage& Message, const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context);

public:
	/** Holds a pointer to the message bus. */
	TSharedPtr<IMessageBus, ESPMode::ThreadSafe> MessageBus;

	/** Holds the messaging endpoint. */
	TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> MessageEndpoint;
};
