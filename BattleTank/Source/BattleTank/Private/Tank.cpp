// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Tankbarrel.h"
#include "Projectile.h"
#include "BattleTank.h"
#include"TankAimingComponent.h"
#include "TankMovementComponent.h"


// Sets default values THIS IS THE CONSTRUCTOR I THINK
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	TankBody = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TankBody"));
	RootComponent = TankBody;

	// No need to protect pointers as added at construction
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
	
}


void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::Fire()
{
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	if (Barrel && isReloaded)
	{
		//Spawn projectile at socket location
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))
			);
		//Launch it
		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();

	}
}
