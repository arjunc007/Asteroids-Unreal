// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AsteroidSpawner.generated.h"

class AAsteroid;

UCLASS()
class ASTEROIDS_API AAsteroidSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAsteroidSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void SpawnAsteroid();

private:
	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<AAsteroid> AsteroidClass;

	UPROPERTY(EditAnywhere, Category = "Spawning")
	float SpawnRate = 1.0f;

	UPROPERTY(EditAnywhere, Category = "Spawning")
	FVector SpawnAreaMin = FVector(2000.0f, -500.f, 0.0f);

	UPROPERTY(EditAnywhere, Category = "Spawning")
	FVector SpawnAreaMax = FVector(2000.f, 500.f, 0.0f);

	UPROPERTY(EditAnywhere, Category = "Spawning")
	float MinSpeed = 200.f;

	UPROPERTY(EditAnywhere, Category = "Spawning")
	float MaxSpeed = 600.f;

	UPROPERTY(EditAnywhere, Category = "Spawning")
	float MinSize = 1.5f;

	UPROPERTY(EditAnywhere, Category = "Spawning")
	float MaxSize = 5.0f;

	UPROPERTY(EditAnywhere, Category = "Spawning")
	float MinRotationSpeed = 10.0f;

	UPROPERTY(EditAnywhere, Category = "Spawning")
	float MaxRotationSpeed = 50.0f;

	FTimerHandle SpawnTimer;
};
