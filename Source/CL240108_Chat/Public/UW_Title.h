// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UW_Title.generated.h"

class UButton;
class UEditableTextBox;

/**
 * 
 */
UCLASS()
class CL240108_CHAT_API UUW_Title : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;

	void ProcessMakeRoom();

	void ProcessConnectServer();

public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Customs")
	TObjectPtr<UButton> CreateButton;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Customs")
	TObjectPtr<UButton> ConnectButton;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Customs")
	TObjectPtr<UEditableTextBox> IPBox;
};
