// Fill out your copyright notice in the Description page of Project Settings.


#include "Lobby/LobbyGameStateBase.h"
#include "Lobby/LobbyPlayerController.h"
#include "Lobby/LobbyWidget.h"
#include "Net/UnrealNetwork.h"
#include "Kismet/GameplayStatics.h"

void ALobbyGameStateBase::IncreasePlayerCount()
{
	PlayerCount++;
	UE_LOG(LogTemp, Warning, TEXT("Player Count %d"), PlayerCount);
}

void ALobbyGameStateBase::DecreasePlayerCount()
{
	PlayerCount--;
	UE_LOG(LogTemp, Warning, TEXT("Player Count %d"), PlayerCount);
}

void ALobbyGameStateBase::OnRep_PlayerCount()
{
	ALobbyPlayerController* PC = Cast<ALobbyPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	if (PC && PC->LobbyWidgetObject)
	{
		PC->LobbyWidgetObject->UpdatePlayerCount(PlayerCount);
	}
}

void ALobbyGameStateBase::S2A_UpdateLeftTime_Implementation(int InLeftTime)
{
	LeftTime = InLeftTime;

	ALobbyPlayerController* PC = Cast<ALobbyPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (PC && PC->LobbyWidgetObject)
	{
		PC->LobbyWidgetObject->UpdateLeftTime(LeftTime);
	}
}

void ALobbyGameStateBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ALobbyGameStateBase, PlayerCount);
}
