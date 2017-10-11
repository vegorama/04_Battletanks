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