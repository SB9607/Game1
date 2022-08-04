// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "StartGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class ASSIGNMENT1_API AStartGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
	protected:
	virtual void BeginPlay() override;
};
