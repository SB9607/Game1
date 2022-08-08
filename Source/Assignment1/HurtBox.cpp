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


	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	BoxCollision->SetCollisionProfileName("Trigger");
	BoxCollision->SetBoxExtent(FVector(49.0f, 49.0f, 49.0f));
}

// Called when the game starts or when spawned
void AHurtBox::BeginPlay()
{
	Super::BeginPlay();

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
	if (OtherActor != nullptr)
	{
		if (OtherActor->GetClass()->IsChildOf(APlayerCharacter::StaticClass()))
		{
			Cast<APlayerCharacter>(OtherActor)->TakeDamage(10.0f);
		}
	}
}
void AHurtBox::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}

