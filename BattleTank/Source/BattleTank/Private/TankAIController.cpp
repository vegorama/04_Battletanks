// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include"BattleTank.h"
#include "Tank.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AITank can't find PlayerTank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AITank  found player: %s"), *(PlayerTank->GetName()));
	}

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
		//TODO move toward player

		//aim toward player
		GetAIControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		//fire if ready
	
}



ATank* ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}
