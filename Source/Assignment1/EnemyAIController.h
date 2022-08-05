// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class ASSIGNMENT1_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) override;

	UFUNCTION()
	void RandomPatrol();

	FTimerHandle WaitTimer;

protected:
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:
	UPROPERTY()
	TArray<AActor*> Waypoints;

	UFUNCTION()
	AActor* ChooseWaypoint();

	UPROPERTY(EditAnywhere)
	float WaitDuration = 3.0f;

	APawn* PlayerPawn;

	AActor* PlaceToMoveTo;

};
