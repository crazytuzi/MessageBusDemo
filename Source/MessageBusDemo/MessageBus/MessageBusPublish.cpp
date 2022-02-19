// Fill out your copyright notice in the Description page of Project Settings.


#include "MessageBusPublish.h"
#include "MessageEndpointBuilder.h"
#include "MessageBusType.h"

// Sets default values
AMessageBusPublish::AMessageBusPublish()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMessageBusPublish::BeginPlay()
{
	Super::BeginPlay();

	MessageBus = IMessagingModule::Get().GetDefaultBus();

	MessageEndpoint = FMessageEndpoint::Builder("Publish-Subscribe", MessageBus.ToSharedRef());
}

// Called every frame
void AMessageBusPublish::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MessageEndpoint->Publish<FTestPublishMessage>(new FTestPublishMessage("Publish"));
}

