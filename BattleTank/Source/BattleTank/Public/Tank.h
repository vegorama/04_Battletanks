// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // must be last

// forward declarations
class UTankBarrel;
class UTankAimingComponent;
class UTankTurret;
class AProjectile;


UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable)
	void Fire();


protected:
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;


private:
	// Sets default values for this pawn's properties
	ATank();

	virtual void BeginPlay() override;


	//TODO remove once firing is moved to aiming component
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 5000;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(VisibleDefaultsOnly)
	UStaticMeshComponent* TankBody;
	
	float ReloadTimeInSeconds = 3;

	double LastFireTime = 0;

	UTankBarrel* Barrel = nullptr;

};
