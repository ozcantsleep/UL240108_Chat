// Fill out your copyright notice in the Description page of Project Settings.


#include "Lobby/LobbyGameMode.h"
#include "Lobby/LobbyGameStateBase.h"

void ALobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	ALobbyGameStateBase* GS = GetGameState<ALobbyGameStateBase>();
	if (GS)
	{
		GS->IncreasePlayerCount();
		GS->OnRep_PlayerCount();
	}
}

void ALobbyGameMode::Logout(AController* Exiting)
{
	ALobbyGameStateBase* GS = GetGameState<ALobbyGameStateBase>();
	if (GS)
	{
		GS->DecreasePlayerCount();
		GS->OnRep_PlayerCount();
	}

	Super::Logout(Exiting);
}

void ALobbyGameMode::BeginPlay()
{
	Super::BeginPlay();

	ALobbyGameStateBase* GS = GetGameState<ALobbyGameStateBase>();
	if (GS)
	{
		GS->OnRep_PlayerCount(); //Only server call
	}

	FTimerHandle LeftTimerHandle;

	GetWorld()->GetTimerManager().SetTimer(LeftTimerHandle, this, &ALobbyGameMode::UpdateLeftTime, 1.0f, true, -1.0f);
}

void ALobbyGameMode::UpdateLeftTime()
{
	ALobbyGameStateBase* GS = GetGameState<ALobbyGameStateBase>();
	if (GS)
	{
		GS->LeftTime--;
		GS->S2A_UpdateLeftTime(GS->LeftTime);
	}
}


