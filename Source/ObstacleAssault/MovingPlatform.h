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
	bool MoveFoward= true;
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

	UPROPERTY(EditAnywhere, Category="Platform Movement")
	float Speed = 1;

	UPROPERTY(EditAnywhere, Category = "Platform Movement")
	FVector MovementRate = FVector(0,1,0);

	UPROPERTY(EditAnywhere)
	FVector Spawn = FVector(-14283, -2464, 4027);
	
};
