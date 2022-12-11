// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()

private:
	
	void Move(float DeltaTime);

public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Platform Movement")
	float MoveDistance = 1000;

	UPROPERTY(EditAnywhere, Category = "Platform Movement")
	FVector MovementRate = FVector(10,10,10);

	UPROPERTY(EditAnywhere)
	FVector Spawn = FVector(-14283, -2464, 4027);
	
};
