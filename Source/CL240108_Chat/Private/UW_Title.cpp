// Fill out your copyright notice in the Description page of Project Settings.


#include "UW_Title.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "Kismet/GameplayStatics.h"

void UUW_Title::NativeConstruct()
{
	Super::NativeConstruct();

	CreateButton = Cast<UButton>(GetWidgetFromName(TEXT("CreateButton")));
	ConnectButton = Cast<UButton>(GetWidgetFromName(TEXT("ConnectButton")));
	IPBox = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("IPBox")));

	if (CreateButton)
	{
		CreateButton->OnReleased.AddDynamic(this, &UUW_Title::ProcessMakeRoom);
	}

	if (ConnectButton)
	{
		ConnectButton->OnReleased.AddDynamic(this, &UUW_Title::ProcessMakeRoom);
	}
}

void UUW_Title::ProcessMakeRoom()
{
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("Lobby"), true, TEXT("listen"));
}

void UUW_Title::ProcessConnectServer()
{
	if (IPBox)
	{
		UGameplayStatics::OpenLevel(GetWorld(), FName(*IPBox->GetText().ToString()));
	}
}