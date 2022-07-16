// Fill out your copyright notice in the Description page of Project Settings.


#include "ExplosiveCrate.h"

// Sets default values
AExplosiveCrate::AExplosiveCrate()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
	Mesh->SetSimulatePhysics(true);
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

