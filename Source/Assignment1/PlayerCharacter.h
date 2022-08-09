// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Assignment1GameModeBase.h"
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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float Health = 100.0f; //Health of the player 

	/// <summary>
	/// Function to take damage when hurt.
	/// </summary>
	/// <param name="DamageAmount">Amount of damage to take off the players health</param>
	/// <returns>Health</returns>
	float TakeDamage(float DamageAmount);

private:
	UPROPERTY(EditAnywhere)
	USpringArmComponent* SpringArm; //Reference to the spring arm the camera is attached to

	UPROPERTY(EditAnywhere)
	UCameraComponent* Camera; //Reference to the camera 

	UPROPERTY(EditAnywhere)
	USceneComponent* ProjectileSpawnLocation; //Location to spawn the projectile when shot

	UPROPERTY(EditAnywhere)
	TSubclassOf<AProjectile> ProjectileClass; //Projectile that is shot when the player shoots the gun

	UPROPERTY(EditAnywhere)
	USoundBase* GunshotSound; //Reference to the sound of a gunshot

	UPROPERTY()
	AAssignment1GameModeBase* GameModeRef; //Reference to the gamemode 

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

	/// <summary>
	/// Function when the player shoots
	/// </summary>
	void OnBeginFire();

	/// <summary>
	/// Function when the player stops shooting
	/// </summary>
	void OnEndFire();

};
