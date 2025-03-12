// Fill out your copyright notice in the Description page of Project Settings.


#include "AsteroidSpawner.h"
#include "Asteroid.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/World.h"
#include "TimerManager.h"

// Sets default values
AAsteroidSpawner::AAsteroidSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAsteroidSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorldTimerManager().SetTimer(SpawnTimer, this, &AAsteroidSpawner::SpawnAsteroid, SpawnRate, true);
}

// Called every frame
void AAsteroidSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAsteroidSpawner::SpawnAsteroid()
{
	if (!AsteroidClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("AsteroidClass is not set in the spawner!"));
		return;
	}

	FVector SpawnPosition = FVector(
		SpawnAreaMin.X,
		FMath::RandRange(SpawnAreaMin.Y, SpawnAreaMax.Y),
		100.f
	);

	FVector Direction = FVector(-1.0f, FMath::RandRange(-0.2f, 0.2f), 0.0f).GetSafeNormal();

	float Speed = FMath::RandRange(MinSpeed, MaxSpeed);
	float RotationSpeedValue = FMath::RandRange(MinRotationSpeed, MaxRotationSpeed);
	UE_LOG(LogTemp, Display, TEXT("Spawning Asteroid at Location %s with Speed = %f and Direction = %s"), *SpawnPosition.ToString(), Speed, *Direction.ToString());
	AAsteroid* NewAsteroid = GetWorld()->SpawnActor<AAsteroid>(AsteroidClass, SpawnPosition, FRotator::ZeroRotator);
	if (NewAsteroid)
	{
		NewAsteroid->Initialise(SpawnPosition, Direction, Speed, RotationSpeedValue);
	}
}