// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"
#include "BattleTank.h"


void UTankTrack::SetThrottle(float Throttle)
{
	
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	AddForceAtLocation(ForceApplied, ForceLocation);
	//REMOVED TankRoot-> from start of above line cos its bussstedddd
}
