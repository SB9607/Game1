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
	UE_LOG(LogTemp, Warning, TEXT("Points increased!!!"));
	UserPoints += AmountToIncrease;
	if (UserPoints == WinCondition)
	{
		WinGame();
	}
}

void AAssignment1GameModeBase::StartGame()
{
	GetWorld()->GetTimerManager().SetTimer(EndGameTimer, this, &AAssignment1GameModeBase::LoseGame, GameDuration, false);

	UGameplayStatics::GetPlayerController(GetWorld(), 0)->bShowMouseCursor = false;
}

void AAssignment1GameModeBase::WinGame()
{
	//Display the Win UI

	UGameplayStatics::OpenLevel(GetWorld(), TEXT("WinMap"));
	UE_LOG(LogTemp, Warning, TEXT("User has WON the game"));
	
}

void AAssignment1GameModeBase::LoseGame()
{
	//Display the Lose UI
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("LoseMap"));
	UE_LOG(LogTemp, Warning, TEXT("User has LOST the game"));
}
