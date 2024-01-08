// Fill out your copyright notice in the Description page of Project Settings.


#include "Lobby/LobbyWidget.h"
#include "Lobby/LobbyPlayerController.h"
#include "Components/ScrollBox.h"
#include "Components/EditableTextBox.h"
#include "Components/TextBlock.h"

void ULobbyWidget::NativeConstruct()
{
	Super::NativeConstruct();

	PlayerCountText = Cast<UTextBlock>(GetWidgetFromName("PlayerCountText"));
	ChatScrollBox = Cast<UScrollBox>(GetWidgetFromName("ChatScrollBox"));
	ChatInputBox = Cast<UEditableTextBox>(GetWidgetFromName("ChatInputBox"));

	if (ChatInputBox)
	{
		ChatInputBox->OnTextChanged.AddDynamic(this, &ULobbyWidget::ProcessChanged);
		ChatInputBox->OnTextCommitted.AddDynamic(this, &ULobbyWidget::ProcessCommitted);
	}

	LeftTimeTextBox = Cast<UTextBlock>(GetWidgetFromName("LeftTimeBox"));
}

void ULobbyWidget::ProcessChanged(const FText& Text)
{

}

void ULobbyWidget::ProcessCommitted(const FText& Text, ETextCommit::Type CommitMethod)
{
	ALobbyPlayerController* PC = Cast<ALobbyPlayerController>(GetOwningPlayer());

	if (PC)
	{
		switch (CommitMethod)
		{
		case ETextCommit::OnEnter:
			PC->C2S_SendMessage(ChatInputBox->GetText().ToString());
			ChatInputBox->SetText(FText::FromString(TEXT("")));
			break;
		case ETextCommit::OnCleared:
			ChatInputBox->SetUserFocus(PC);
		}
	}
}

void ULobbyWidget::UpdatePlayerCount(int32 InPlayerCount)
{
	if (PlayerCountText)
	{
		FString Message = FString::Printf(TEXT("%d Players"), InPlayerCount);
		PlayerCountText->SetText(FText::FromString(Message));
	}
}

void ULobbyWidget::UpdateLeftTime(int InLeftTime)
{
	if (LeftTimeTextBox)
	{
		if (InLeftTime > 0)
		{
			FString Message = FString::Printf(TEXT("%d Seconds Left"), InLeftTime);
			LeftTimeTextBox->SetText(FText::FromString(Message));
		}
		else
		{
			LeftTimeTextBox->SetText(FText::FromString(TEXT("Start")));
		}
	}
}

void ULobbyWidget::AddMessage(const FString& InMessage)
{
	if (ChatScrollBox)
	{
		UTextBlock* NewMessage = NewObject<UTextBlock>(ChatScrollBox);
		if (NewMessage)
		{
			NewMessage->SetText(FText::FromString(InMessage));
			FSlateFontInfo NewFont = NewMessage->GetFont();
			NewFont.Size = 18;
			NewMessage->SetFont(NewFont);
			ChatScrollBox->AddChild(NewMessage);
			ChatScrollBox->ScrollToEnd();
		}
	}
}
