// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto EnemyTank = GetAIControlledTank();
	if (!EnemyTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("EnemyTank not possessing any-ting"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("EnemyTank possessed by : %s"), *(EnemyTank->GetName()));
	}

}

ATank* ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
