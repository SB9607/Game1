// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Assignment1GameModeBase.h"
#include "HurtBox.generated.h"

class UBoxComponent;
UCLASS()
class ASSIGNMENT1_API AHurtBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHurtBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	UPROPERTY(EditAnywhere)
	UBoxComponent* BoxCollision; //Box component used as a collision box

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	//Function that will be called when another actor is overlapping the collision box
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	//Function that will be called when another actor is not overlapping the collision box anymore
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

private:

	float BaseDamage = 10.0f; //Damage that the player will take

};
