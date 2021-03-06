// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "Assignment1GameModeBase.h"
#include "ExplosiveCrate.generated.h"

UCLASS()
class ASSIGNMENT1_API AExplosiveCrate : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AExplosiveCrate();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
	float Health = 20.0f;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY()
		AAssignment1GameModeBase* GameModeRef;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent,
		AController* EventInstigator, AActor* DamageCauser) override;

};
