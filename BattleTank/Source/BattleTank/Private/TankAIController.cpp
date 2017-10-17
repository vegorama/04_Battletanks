// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankAimingComponent.h"
#include"BattleTank.h"
//Depends on movement component via pathfinding system

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

		auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
		auto ControlledTank = GetPawn();

		if (!ensure(PlayerTank && ControlledTank)) { return; }

		//Move towards player
		MoveToActor(PlayerTank, AcceptanceRadius);
		
		//aim at player
		auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
		AimingComponent->AimAt(PlayerTank->GetActorLocation());

	if (AimingComponent->GetFiringState() == EFiringStatus::Locked)
	{
		AimingComponent->Fire();
	}
		
}



