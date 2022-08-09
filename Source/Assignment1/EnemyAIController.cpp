// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/TargetPoint.h"

void AEnemyAIController::BeginPlay() 
{
	Super::BeginPlay();

	//Finding all the waypoints on the map and setting them in the waypoints array
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetPoint::StaticClass(), Waypoints);

	//picking a random waypoint and moving towards it
	RandomPatrol();

	//Setting the player pawn reference
	PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
}

// Called every frame
void AEnemyAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//setting the AI pawn 
	APawn* AIPawn = GetPawn();
	FVector AIForwardVector = AIPawn->GetActorForwardVector(); //already nomalised vector of the AI forward vector
	FVector PlayerPositionVector = PlayerPawn->GetActorLocation(); //player position vector
	FVector AIPositionVector = AIPawn->GetActorLocation(); //The AI position vecotr
	FVector AIToPlayerVector = PlayerPositionVector - AIPositionVector; //Finding the vector from the AI to the player
	AIToPlayerVector.Normalize(); //this vector must be explicitly normalised
	float DirectionDotProduct = FVector::DotProduct(AIToPlayerVector, AIForwardVector); //The dopt product of the players position in regards to the AI. > 0 for infront and < 0 for behind

	//Checking if the AI has line of sight to the player and the player is infront of the AI
	if (LineOfSightTo(PlayerPawn) && DirectionDotProduct >= 0)
	{
		SetFocus(PlayerPawn); //Look at the player
		MoveToActor(PlayerPawn, 10.0f); //Move towards the player
	}
}

void AEnemyAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
	Super::OnMoveCompleted(RequestID, Result);
	PlaceToMoveTo = nullptr; //Resetting the place to move pointer
	GetWorld()->GetTimerManager().SetTimer(WaitTimer, this, &AEnemyAIController::RandomPatrol, WaitDuration, false); //Making the AI wait for 3 seconds before going to another checkpoint
}


AActor* AEnemyAIController::ChooseWaypoint()
{
	int index = FMath::RandRange(0, Waypoints.Num() - 1); //Deciding a random number between 0 and the size of the waypoints array
	return Waypoints[index]; //Returning the random waypoint
}

void AEnemyAIController::RandomPatrol()
{
	PlaceToMoveTo = ChooseWaypoint();
	SetFocus(PlaceToMoveTo); //Looking at the new waypoint
	MoveToActor(PlaceToMoveTo, 10.0f); //moving towards the new waypoint
}

