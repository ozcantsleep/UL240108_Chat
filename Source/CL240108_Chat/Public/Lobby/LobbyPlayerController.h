// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "LobbyPlayerController.generated.h"

class ULobbyWidget;
/**
 * 
 */
UCLASS()
class CL240108_CHAT_API ALobbyPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Custom UI")
	TObjectPtr<ULobbyWidget> LobbyWidgetObject;

	//UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "Custom UI")
	//TSubclassOf<ULobbyWidget> LobbyWidgetClass;

	UFUNCTION(Server, Unreliable, WithValidation)
	void C2S_SendMessage(const FString& InMessage);
	bool C2S_SendMessage_Validate(const FString& InMessage);
	void C2S_SendMessage_Implementation(const FString& InMessage);

	UFUNCTION(Client, Reliable)
	void S2C_SendMessage(const FString& InMessage);
	void S2C_SendMessage_Implementation(const FString& InMessage);
};

