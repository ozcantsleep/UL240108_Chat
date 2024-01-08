// Fill out your copyright notice in the Description page of Project Settings.


#include "Lobby/LobbyGameStateBase.h"
#include "Net/UnrealNetwork.h"

void ALobbyGameStateBase::IncreasePlayerCount()
{
	PlayerCount++;
}

void ALobbyGameStateBase::DecreasePlayerCount()
{
	PlayerCount--;
}

void ALobbyGameStateBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ALobbyGameStateBase, PlayerCount);
}
