// Fill out your copyright notice in the Description page of Project Settings.


#include "MessageBusSubscribe.h"
#include "MessageEndpointBuilder.h"

// Sets default values
AMessageBusSubscribe::AMessageBusSubscribe()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMessageBusSubscribe::BeginPlay()
{
	Super::BeginPlay();

	MessageBus = IMessagingModule::Get().GetDefaultBus();

	MessageEndpoint = FMessageEndpoint::Builder("Publish-Subscribe", MessageBus.ToSharedRef()).Handling<FTestMessage>(
		this, &AMessageBusSubscribe::OnReceive);

	MessageEndpoint->Subscribe<FTestMessage>();
}

// Called every frame
void AMessageBusSubscribe::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMessageBusSubscribe::OnReceive(const FTestMessage& Message,
                                     const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	UE_LOG(LogTemp, Log, TEXT("AMessageBusSubscribe::OnReceive => %s"), *Message.Val);
}
