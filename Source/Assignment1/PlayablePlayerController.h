// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayablePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ASSIGNMENT1_API APlayablePlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> HUDClass; //Widget class that will be displayed to the screen set in the editor

	UPROPERTY()
	UUserWidget* HUD; //The widget that will be displayed to the screen
};
