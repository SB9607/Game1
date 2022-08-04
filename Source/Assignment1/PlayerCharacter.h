// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class USceneComponent;
class AProjectile;

UCLASS()
class ASSIGNMENT1_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(EditAnywhere)
	USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere)
	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere)
	USceneComponent* ProjectileSpawnLocation;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere)
	USoundBase* GunshotSound;

	UPROPERTY()
	float Health = 100.0f;

	/// <summary>
	/// Handeller function for moving forward
	/// </summary>
	/// <param name="AxisAmount">The amount you want to move by</param>
	void MoveForwards(float AxisAmount);

	/// <summary>
	/// Handeller function for moving side to side
	/// </summary>
	/// <param name="AxisAmount">The amount you want to move by</param>
	void Strafe(float AxisAmount);

	/// <summary>
	/// Handeller function for looking up
	/// </summary>
	/// <param name="AxisAmount">The amount you want to look up</param>
	void LookUp(float AxisAmount);

	/// <summary>
	/// Handeller function for looking side to side
	/// </summary>
	/// <param name="AxisAmount">The amount you want to turn by</param>
	void Turn(float AxisAmount);

	void OnBeginFire();

	void OnEndFire();

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent,
		AController* EventInstigator, AActor* DamageCauser) override;


};
