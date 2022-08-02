// Copyright Epic Games, Inc. All Rights Reserved.


#include "Assignment1GameModeBase.h"

void AAssignment1GameModeBase::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(EndGameTimer, this, &AAssignment1GameModeBase::LoseGame, GameDuration, false);
}

void AAssignment1GameModeBase::PointScored(float AmountToIncrease)
{
	UE_LOG(LogTemp, Warning, TEXT("Points increased!!!"));
	UserPoints += AmountToIncrease;
	if (UserPoints == WinCondition)
	{
		WinGame();
	}
}

void AAssignment1GameModeBase::WinGame()
{
	//Display the Win UI

	UE_LOG(LogTemp, Warning, TEXT("User has WON the game"));
}

void AAssignment1GameModeBase::LoseGame()
{
	//Display the Lose UI

	UE_LOG(LogTemp, Warning, TEXT("User has LOST the game"));
}
