// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	Spawn = GetActorLocation();
	SetActorLocation(Spawn);
}

void AMovingPlatform::Move(float DeltaTime) {
	
	FVector CurrentLocation = GetActorLocation();
	float DistanceMoved = FVector::Dist(CurrentLocation, Spawn);


	if (DistanceMoved <= MoveDistance) {
		CurrentLocation += (MovementRate * DeltaTime);
		SetActorLocation(CurrentLocation);
	}
	else {
		Spawn = Spawn + (MovementRate.GetSafeNormal() * MoveDistance);
		SetActorLocation(Spawn);
		MovementRate = -MovementRate;
	}

}

void AMovingPlatform::Rotate(float DeltaTime) {
	AddActorRotation(RotationRate * DeltaTime);
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move(DeltaTime);
	Rotate(DeltaTime);

}

