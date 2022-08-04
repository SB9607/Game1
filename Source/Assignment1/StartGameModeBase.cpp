// Fill out your copyright notice in the Description page of Project Settings.


#include "StartGameModeBase.h"
#include "Kismet/GameplayStatics.h"

void AStartGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	UGameplayStatics::GetPlayerController(GetWorld(), 0)->bShowMouseCursor = true;
}
