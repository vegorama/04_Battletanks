// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include"BattleTank.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

		auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
		auto ControlledTank = Cast<ATank>(GetPawn());

		if (PlayerTank)	
		{
		//Move towards player
		MoveToActor(PlayerTank, AcceptanceRadius);
		
		//aim at player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		//TODO don't fire every frame 
		ControlledTank->Fire();
		}
}



