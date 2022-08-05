// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/TargetPoint.h"

void AEnemyAIController::BeginPlay() 
{
	Super::BeginPlay();

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetPoint::StaticClass(), Waypoints);

	RandomPatrol();

	PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
}

// Called every frame
void AEnemyAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	APawn* AIPawn = GetPawn();
	FVector AIForwardVector = AIPawn->GetActorForwardVector(); //already nomalised
	FVector PlayerPositionVector = PlayerPawn->GetActorLocation();
	FVector AIPositionVector = AIPawn->GetActorLocation();
	FVector AIToPlayerVector = PlayerPositionVector - AIPositionVector;
	AIToPlayerVector.Normalize(); //this vector must be explicitly normalised
	float DirectionDotProduct = FVector::DotProduct(AIToPlayerVector, AIForwardVector);
	UE_LOG(LogTemp, Warning, TEXT("dot product is: %f"), DirectionDotProduct);

	if (LineOfSightTo(PlayerPawn) && DirectionDotProduct >= 0)
	{
		SetFocus(PlayerPawn);
		MoveToActor(PlayerPawn, 10.0f);
	}
}

void AEnemyAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
	Super::OnMoveCompleted(RequestID, Result);
	PlaceToMoveTo = nullptr;
	GetWorld()->GetTimerManager().SetTimer(WaitTimer, this, &AEnemyAIController::RandomPatrol, WaitDuration, false);
}


AActor* AEnemyAIController::ChooseWaypoint()
{
	int index = FMath::RandRange(0, Waypoints.Num() - 1);
	return Waypoints[index];
}

void AEnemyAIController::RandomPatrol()
{
	PlaceToMoveTo = ChooseWaypoint();
	SetFocus(PlaceToMoveTo);
	MoveToActor(PlaceToMoveTo, 10.0f);
}

