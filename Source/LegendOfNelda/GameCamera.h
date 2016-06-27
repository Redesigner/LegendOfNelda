// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "GameCamera.generated.h"

UCLASS()
class LEGENDOFNELDA_API AGameCamera : public AActor
{
	GENERATED_BODY()

	FVector Position;
	FRotator Rotation;
	
public:	
	// Sets default values for this actor's properties
	AGameCamera();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Camera")
	ACharacter* TrackedCharacter;

	UFUNCTION(BlueprintCallable, Category = "Game Camera")
	void SetCameraPosition(FVector NewPosition);

	UFUNCTION(BlueprintCallable, Category = "Game Camera")
	void SetCameraRotation(FRotator NewRotation);

	UFUNCTION(BlueprintNativeEvent, Category = "Game Camera")
	void CalculateCameraOrientation(ACharacter* Target, UCameraComponent* DefaultCamera);

	virtual void CalcCamera(float DeltaTime, struct FMinimalViewInfo& OutResult) override;

	UPROPERTY(EditAnywhere, Category = "Game Camera")
	USceneComponent* Root;

	UPROPERTY(EditAnywhere, Category = "Game Camera")
	UCameraComponent* Camera;
};
