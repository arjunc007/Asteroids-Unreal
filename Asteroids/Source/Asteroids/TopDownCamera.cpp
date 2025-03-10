// Fill out your copyright notice in the Description page of Project Settings.


#include "TopDownCamera.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraComponent.h"

// Sets default values
ATopDownCamera::ATopDownCamera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	RootComponent = CameraComponent;

	CameraComponent->SetRelativeLocation(FVector(0.f, 0.f, 1000.f));
	CameraComponent->SetRelativeRotation(FRotator(-90.0f, 0.f, 0.f));
	CameraComponent->SetProjectionMode(ECameraProjectionMode::Orthographic);
	CameraComponent->SetOrthoWidth(4000.f);
}

// Called when the game starts or when spawned
void ATopDownCamera::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
	if (PlayerController)
	{
		PlayerController->SetViewTarget(this);
	}
}

// Called every frame
void ATopDownCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

