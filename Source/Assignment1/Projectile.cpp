// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "ExplosiveCrate.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetSimulatePhysics(true);
	Mesh->SetNotifyRigidBodyCollision(true);

	SetRootComponent(Mesh);

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovement->MaxSpeed = MovementSpeed;
	ProjectileMovement->InitialSpeed = MovementSpeed;
	InitialLifeSpan = 4.0f;
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
	OnActorHit.AddDynamic(this, &AProjectile::OnHit);
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AProjectile::OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	
	AActor* ProjectileOwner = GetOwner();

	if (ProjectileOwner == nullptr)
	{
		return;
	}
	else
	{
		if (OtherActor != nullptr)
		{
			if (OtherActor->GetClass()->IsChildOf(AExplosiveCrate::StaticClass()))
			{
				UGameplayStatics::ApplyDamage(
					OtherActor, //actor that will be damaged
					Damage, //the base damage to apply
					ProjectileOwner->GetInstigatorController(), //controller that caused the damage
					this, //Actor that actually caused the damage
					UDamageType::StaticClass() //class that describes the damage that was done
				);
				Destroy();
			}
		}
	}

	
	
}

