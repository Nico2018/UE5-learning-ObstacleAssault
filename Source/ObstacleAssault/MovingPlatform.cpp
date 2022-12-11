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
	
	SetActorLocation(Spawn);
}

void AMovingPlatform::Move(float DeltaTime) {

	FVector CurrentLocation = GetActorLocation();
	if (FVector::Dist(CurrentLocation, Spawn) > 1000) {
		Speed = -Speed;
		Spawn = CurrentLocation;
	}
	FVector TranslateLocation = (MovementRate * Speed * DeltaTime);

	

	CurrentLocation += TranslateLocation;

	SetActorLocation(CurrentLocation);
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move(DeltaTime);

}

