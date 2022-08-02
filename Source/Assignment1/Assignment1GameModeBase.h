// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Assignment1GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class ASSIGNMENT1_API AAssignment1GameModeBase : public AGameModeBase
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;

public:

	UPROPERTY()
	float UserPoints = 0.0f;

	UFUNCTION()
	void PointScored(float AmountToIncrease);

	UFUNCTION()
	void WinGame();

	UFUNCTION()
	void LoseGame();

	FTimerHandle EndGameTimer;
	
private:

	UPROPERTY(EditAnywhere)
	float GameDuration = 60.0f;

	UPROPERTY()
	float WinCondition = 1.0f;
};
