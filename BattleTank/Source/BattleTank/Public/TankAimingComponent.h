// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "TankAimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public USceneComponent
{
	GENERATED_BODY()

protected:


public:	

	void AimAt(FVector HitLocation, float LaunchSpeed);
	// Sets default values for this component's properties

	UTankAimingComponent();

	void SetBarrelReference(UStaticMeshComponent* BarrelToSet);
	
private:
	UStaticMeshComponent* Barrel = nullptr;

	void MoveBarrelTowards(FVector AimDirection);

};
