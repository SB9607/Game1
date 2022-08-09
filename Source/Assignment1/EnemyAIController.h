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
	/// <summary>
	/// When the AI has finished moving to a waypoint the AI will pick another waypoint and move towards it
	/// </summary>
	void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) override;

	UFUNCTION()
	/// <summary>
	/// Random patrol function that will pick a random waypoint and tell the AI to move towards it
	/// </summary>
	void RandomPatrol();

	FTimerHandle WaitTimer; //Timer used so the AI will wait at each waypoint it goes to

protected:
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:
	UPROPERTY()
	TArray<AActor*> Waypoints; //List of waypoints that is on the map

	UFUNCTION()
	/// <summary>
	/// Choose a random waypoint that is on the map
	/// </summary>
	/// <returns>Returns the waypoint that has been selected</returns>
	AActor* ChooseWaypoint();

	UPROPERTY(EditAnywhere)
	float WaitDuration = 3.0f; //The wait amount that the AI will wait at a checkpoint

	APawn* PlayerPawn; //Referece to the player pawn

	AActor* PlaceToMoveTo; //Reference for the waypoint the AI will move towards

};
