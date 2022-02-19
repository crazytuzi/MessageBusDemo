// Fill out your copyright notice in the Description page of Project Settings.


#include "MessageBusReply.h"
#include "MessageEndpointBuilder.h"
#include "EngineUtils.h"
#include "MessageBusForward.h"
#include "Kismet/KismetStringLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
AMessageBusReply::AMessageBusReply()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMessageBusReply::BeginPlay()
{
	Super::BeginPlay();

	MessageBus = IMessagingModule::Get().GetDefaultBus();

	MessageEndpoint = FMessageEndpoint::Builder("Request-Reply", MessageBus.ToSharedRef()).Handling<
		FTestRequestMessage>(this, &AMessageBusReply::OnRequest);
}

// Called every frame
void AMessageBusReply::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMessageBusReply::OnRequest(const FTestRequestMessage& Message,
                                 const TSharedRef<IMessageContext, ESPMode::ThreadSafe>& Context)
{
	UE_LOG(LogTemp, Log, TEXT("AMessageBusReply::OnRequest IsDedicatedServer:%s Name:%s => %s"),
	       *UKismetStringLibrary::Conv_BoolToString(UKismetSystemLibrary::IsDedicatedServer(GetWorld())), *GetName(),
	       *Message.Val);

	MessageEndpoint->Send<FTestReplyMessage>(new FTestReplyMessage("OnRequest-Reply"), Context->GetSender());

	TArray<FMessageAddress> Recipients;

	for (TActorIterator<AMessageBusForward> Iterator(GetWorld()); Iterator; ++Iterator)
	{
		Recipients.Add(Iterator->MessageEndpoint->GetAddress());
	}

	MessageEndpoint->Forward(Context, Recipients);
}

