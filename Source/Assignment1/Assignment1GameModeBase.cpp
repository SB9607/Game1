// Copyright Epic Games, Inc. All Rights Reserved.


#include "Assignment1GameModeBase.h"
#include "Kismet/GameplayStatics.h"

void AAssignment1GameModeBase::BeginPlay()
{
	Super::BeginPlay();

	StartGame();
}

void AAssignment1GameModeBase::PointScored(float AmountToIncrease)
{
	UserPoints += AmountToIncrease; //Increase the players points towards the win condition

	//Check to see if the user has won the game
	if (UserPoints == WinCondition)
	{
		WinGame();
	}
}

void AAssignment1GameModeBase::StartGame()
{
	//Setting the timer that will count down and if make the player lose the game
	GetWorld()->GetTimerManager().SetTimer(EndGameTimer, this, &AAssignment1GameModeBase::LoseGame, GameDuration, false);

	//Setting the player controller mouse cursor to invisible
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->bShowMouseCursor = false;
}

void AAssignment1GameModeBase::WinGame()
{
	//Display the Win UI
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("WinMap"));	
}

void AAssignment1GameModeBase::LoseGame()
{
	//Display the Lose UI
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("LoseMap"));
}
