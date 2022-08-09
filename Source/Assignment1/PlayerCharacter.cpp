// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Projectile.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Use a spring arm to give the camera smooth, natural-feeling motion.
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->SetRelativeLocation(FVector(0.0f, 10.0f, 67.0f));
	SpringArm->SetRelativeRotation(FRotator(-10.f, 0.f, 0.f));
	SpringArm->SocketOffset = FVector(0.0f, 79.0f, 0.0f);
	SpringArm->TargetArmLength = 250.0f;
	SpringArm->bUsePawnControlRotation = true;

	// Create a camera and attach to our spring arm
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

	//Create projectile spawn location
	ProjectileSpawnLocation = CreateDefaultSubobject<USceneComponent>(TEXT("ProjectileSpawnLocation"));
	ProjectileSpawnLocation->SetupAttachment(RootComponent);
	ProjectileSpawnLocation->SetRelativeLocation(FVector(70.0f, 20.0f, 60.0f));
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	GameModeRef = Cast<AAssignment1GameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &APlayerCharacter::MoveForwards);
	PlayerInputComponent->BindAxis(TEXT("Strafe"), this, &APlayerCharacter::Strafe);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APlayerCharacter::LookUp);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &APlayerCharacter::Turn);

	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &ACharacter::Jump );
	PlayerInputComponent->BindAction(TEXT("Shoot"), IE_Pressed, this, &APlayerCharacter::OnBeginFire);
	PlayerInputComponent->BindAction(TEXT("Shoot"), IE_Released, this, &APlayerCharacter::OnEndFire);
}

void APlayerCharacter::MoveForwards(float AxisAmount)
{
	AddMovementInput(GetActorForwardVector() * AxisAmount); //Move the player forward
}

void APlayerCharacter::Strafe(float AxisAmount)
{
	AddMovementInput(GetActorRightVector() * AxisAmount); //Moving the player left or right
}

void APlayerCharacter::LookUp(float AxisAmount)
{
	AddControllerPitchInput(AxisAmount); //Allowing the player to look upwards
}

void APlayerCharacter::Turn(float AxisAmount)
{
	AddControllerYawInput(AxisAmount); //Allowing the player to turn left and right
}

void APlayerCharacter::OnBeginFire()
{
	//Check to see if the proijectile class is not null
	if (ProjectileClass) 
	{ 
		FVector SpawnLocation = ProjectileSpawnLocation->GetComponentLocation();
		FRotator SpawnRotation = Camera->GetComponentRotation();
		AProjectile* TempProjectile = GetWorld()->SpawnActor<AProjectile>(ProjectileClass, SpawnLocation, SpawnRotation); //Spawn a projectile at the location set

		TempProjectile->SetOwner(this); //Setting the owner of the projectile

		//Playing the gunshot sound
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), GunshotSound,	GetActorLocation(), 1.0f, 1.0f, 0.0f);
	}
	else
	{

		UE_LOG(LogTemp, Error, TEXT("No Projectile class set in the blueprint"));
	}
}

void APlayerCharacter::OnEndFire()
{
	
}

float APlayerCharacter::TakeDamage(float DamageAmount)
{  
	Health -= DamageAmount; //Decrease the health

	//Cehcking to see if the player died
	if (Health == 0.0f)
	{
		if (GameModeRef != nullptr)
		{
			//If the player is dead lose the game
			GameModeRef->LoseGame();
		}
	}
	return DamageAmount;
}

