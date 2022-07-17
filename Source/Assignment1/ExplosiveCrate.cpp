// Fill out your copyright notice in the Description page of Project Settings.


#include "ExplosiveCrate.h"

// Sets default values
AExplosiveCrate::AExplosiveCrate()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);
	Mesh->SetSimulatePhysics(true);
	Mesh->SetNotifyRigidBodyCollision(true);
	
}

// Called when the game starts or when spawned
void AExplosiveCrate::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AExplosiveCrate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float AExplosiveCrate::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	UE_LOG(LogTemp, Warning, TEXT("Box taken damage"));
	Health -= DamageAmount;

	if (Health == 0.0f)
	{
		UE_LOG(LogTemp, Warning, TEXT("BOOM! BOX DESTROYED"));
		Destroy();
	}

	return DamageAmount;
}

