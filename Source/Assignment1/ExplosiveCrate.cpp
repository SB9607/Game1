// Fill out your copyright notice in the Description page of Project Settings.


#include "ExplosiveCrate.h"

// Sets default values
AExplosiveCrate::AExplosiveCrate()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Setting up the mesh
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);
	Mesh->SetSimulatePhysics(true);
	Mesh->SetNotifyRigidBodyCollision(true);
	
}

// Called when the game starts or when spawned
void AExplosiveCrate::BeginPlay()
{
	Super::BeginPlay();
	
	//Casting to the gamemode
	GameModeRef = Cast<AAssignment1GameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
}

// Called every frame
void AExplosiveCrate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float AExplosiveCrate::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	//Decrease the health value
	Health -= DamageAmount;

	if (Health == 0.0f)
	{
		//When the health hits 0 destroy the crate
		Destroy();

		//Checking if the gamemode is not null
		if (GameModeRef != nullptr)
		{
			GameModeRef->PointScored(1.0f); //Add one point to the user when a box is destroyed
		}
	}

	return DamageAmount;
}

