// Fill out your copyright notice in the Description page of Project Settings.

#include "LegendOfNelda.h"
#include "GameCamera.h"


// Sets default values
AGameCamera::AGameCamera()
{
	PrimaryActorTick.bCanEverTick = false;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
	Camera->SetupAttachment(Root);
}

void AGameCamera::BeginPlay()
{
	Position = Camera->GetComponentLocation();
	Rotation = Camera->GetComponentRotation();
}

void AGameCamera::SetCameraPosition(FVector NewPosition)
{
	Position = NewPosition;
}

void AGameCamera::SetCameraRotation(FRotator NewRotation)
{
	Rotation = NewRotation;
}

void AGameCamera::CalculateCameraOrientation_Implementation(ACharacter* Target, UCameraComponent* DefaultCamera)
{
	SetCameraPosition(DefaultCamera->GetComponentLocation());
	SetCameraRotation(DefaultCamera->GetComponentRotation());
}

void AGameCamera::CalcCamera(float DeltaTime, struct FMinimalViewInfo& OutResult)
{
	CalculateCameraOrientation(TrackedCharacter, Camera);

	Camera->GetCameraView(DeltaTime, OutResult);

	OutResult.Location = Position;
	OutResult.Rotation = Rotation;
}
