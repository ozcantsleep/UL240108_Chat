// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "LobbyGameStateBase.generated.h"

/**
 * 
 */
UCLASS()
class CL240108_CHAT_API ALobbyGameStateBase : public AGameStateBase
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void IncreasePlayerCount();

	UFUNCTION(BlueprintCallable)
	void DecreasePlayerCount();


protected:
	UPROPERTY(ReplicatedUsing="OnRep_PlayerCount", BlueprintReadOnly, meta = (AllowPritaveAccess = "true"))
	int32 PlayerCount;

	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const override;

public:
	int32 LeftTime = 60;

	UFUNCTION()
	void OnRep_PlayerCount();

	UFUNCTION(NetMulticast, Unreliable)
	void S2A_UpdateLeftTime(int InLeftTime);
	void S2A_UpdateLeftTime_Implementation(int InLeftTime);
};
