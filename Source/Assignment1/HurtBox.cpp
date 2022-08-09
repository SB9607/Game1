// Fill out your copyright notice in the Description page of Project Settings.


#include "HurtBox.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerCharacter.h"

// Sets default values
AHurtBox::AHurtBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Setting up the box component
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	BoxCollision->SetCollisionProfileName("Trigger");
	BoxCollision->SetBoxExtent(FVector(49.0f, 49.0f, 49.0f));
}

// Called when the game starts or when spawned
void AHurtBox::BeginPlay()
{
	Super::BeginPlay();

	//Adding deledates that will be called to handle the overlap being and end functionality
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &AHurtBox::OnOverlapBegin);
	BoxCollision->OnComponentEndOverlap.AddDynamic(this, &AHurtBox::OnOverlapEnd);
}

// Called every frame
void AHurtBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHurtBox::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//Making sure the other actor is not null
	if (OtherActor != nullptr)
	{
		//Checking if the other actor is the player character
		if (OtherActor->GetClass()->IsChildOf(APlayerCharacter::StaticClass()))
		{
			//Cast the actor to the player character and call take damage. Then we pass the amound of damage to it.
			Cast<APlayerCharacter>(OtherActor)->TakeDamage(BaseDamage);
		}
	}
}
void AHurtBox::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}

