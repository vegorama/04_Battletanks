// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Tankbarrel.h"
#include "Projectile.h"
#include "BattleTank.h"

// Sets default values THIS IS THE CONSTRUCTOR I THINK
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;


	//TODO bring this shit back into play
	//TankBody = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TankBody"));
	//RootComponent = TankBody;

}

float ATank::GetHealthPercent() const
{
	return (float)CurrentHealth / (float)StartingHealth;
}

float ATank::TakeDamage(float DamageAmount, FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser)
{
	int32 DamagePoints = FPlatformMath::RoundToInt(DamageAmount);
	int32 DamageToApply = FMath::Clamp(DamagePoints, 0, CurrentHealth);

	CurrentHealth = (CurrentHealth - DamageToApply);
	if (CurrentHealth <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank Died"))
	}

	return DamageToApply;
}
