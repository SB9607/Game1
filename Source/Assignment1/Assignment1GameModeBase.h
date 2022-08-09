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
	float UserPoints = 0.0f; //The score for the user that will increase when a box is destroyed

	/// <summary>
	/// Function to increase the score of the player by the amount passed
	/// </summary>
	UFUNCTION()
	void PointScored(float AmountToIncrease);

	/// <summary>
	/// Start game function that is called at the begin play for the gamemode
	/// </summary>
	UFUNCTION()
	void StartGame();

	/// <summary>
	/// Win game function that is called when the player hits the win condition and takes the player to the win screen
	/// </summary>
	UFUNCTION()
	void WinGame();

	/// <summary>
	/// Lose game function that is called when the timer runs out and the player will be sent to a lose screen
	/// </summary>
	UFUNCTION()
	void LoseGame();

	FTimerHandle EndGameTimer; //Timer that will be set to the game duration of 60 seconds. When the timer runs out the player will lose the game

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float GameDuration = 60.0f; //Duration of the game set to 60 seconds that will count down using the timer

private:

	UPROPERTY()
	float WinCondition = 10.0f; //Win condition set so when you destroy 10 boxes you win the game.
};
