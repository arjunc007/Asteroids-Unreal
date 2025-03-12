// Fill out your copyright notice in the Description page of Project Settings.


#include "Asteroid.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AAsteroid::AAsteroid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Box Collision"));
	RootComponent = SphereComponent;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Asteroid Mesh"));
	BaseMesh->SetupAttachment(SphereComponent);

	AsteroidMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Asteroid Movement"));
}

// Called when the game starts or when spawned
void AAsteroid::BeginPlay()
{
	Super::BeginPlay();

	RotationAxis = FMath::VRand();
}

// Called every frame
void AAsteroid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(FRotator(RotSpeed * DeltaTime, RotSpeed * DeltaTime, 0.0f));
}

void AAsteroid::Initialise(FVector StartPosition, FVector Direction, float Speed, float RotationSpeed)
{
	SetActorLocation(StartPosition);

	AsteroidMovement->Velocity = Direction * Speed;

	RotSpeed = RotationSpeed;
}
