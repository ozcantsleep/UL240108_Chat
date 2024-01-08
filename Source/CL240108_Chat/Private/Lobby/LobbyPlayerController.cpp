// Fill out your copyright notice in the Description page of Project Settings.


#include "Lobby/LobbyPlayerController.h"
#include "Lobby/LobbyWidget.h"

void ALobbyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	SetInputMode(FInputModeUIOnly());
	bShowMouseCursor = true;

	FSoftClassPath LobbyWidgetClass(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Blueprints/Lobby/WBP_Lobby.WBP_Lobby_C'"));
	UClass* WidgetClass = LobbyWidgetClass.TryLoadClass<UUserWidget>();

	if (WidgetClass && IsLocalPlayerController())
	{
		LobbyWidgetObject = CreateWidget<ULobbyWidget>(this, WidgetClass);
		if (LobbyWidgetObject)
		{
			LobbyWidgetObject->AddToViewport();
			//LobbyWidgetObejct->RemoveFromViewport();
		}
	}

}

bool ALobbyPlayerController::C2S_SendMessage_Validate(const FString& InMessage)
{
	return true;
}

void ALobbyPlayerController::C2S_SendMessage_Implementation(const FString& InMessage)
{
	for (auto It = GetWorld()->GetPlayerControllerIterator(); It; It++)
	{
		ALobbyPlayerController* PC = Cast<ALobbyPlayerController>(*It);
		if (PC)
		{
			PC->S2C_SendMessage(InMessage);
		}
	}
}

void ALobbyPlayerController::S2C_SendMessage_Implementation(const FString& InMessage)
{
	if (LobbyWidgetObject)
		{
			LobbyWidgetObject->AddMessage(InMessage);
		}
}
