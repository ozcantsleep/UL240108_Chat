// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LobbyWidget.generated.h"

class UTextBlock;
class UScrollBox;
class UEditableTextBox;

/**
 * 
 */
UCLASS()
class CL240108_CHAT_API ULobbyWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	UFUNCTION()
	void ProcessChanged(const FText& Text);

	UFUNCTION()
	void ProcessCommitted(const FText& Text, ETextCommit::Type CommitMethod);

	UFUNCTION(BlueprintCallable)
	void AddMessage(const FString& InMessage);

	void UpdatePlayerCount(int32 InPlayerCount);

	void UpdateLeftTime(int InLeftTime);

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Custom UI")
	TObjectPtr<UTextBlock> PlayerCountText;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Custom UI")
	TObjectPtr<UScrollBox> ChatScrollBox;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Custom UI")
	TObjectPtr<UEditableTextBox> ChatInputBox;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Custom UI")
	TObjectPtr<UTextBlock> LeftTimeTextBox;

};
