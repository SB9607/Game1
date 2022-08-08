// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayablePlayerController.h"
#include "Blueprint/UserWidget.h"

// Called when the game starts or when spawned
void APlayablePlayerController::BeginPlay()
{
	Super::BeginPlay();

	HUD = CreateWidget(this, HUDClass);

	if (HUD != nullptr)
	{
		HUD->AddToViewport();
	}
}