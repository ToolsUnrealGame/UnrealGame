// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

void UMovingPlatform::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FVector TargetLocation;
	if (IsActivated()) {
		TargetLocation = InitialLocation + MoveOffset;
	}
	else {
		TargetLocation = InitialLocation;
	}
	USceneComponent* SceneComponent = GetAttachParent();
	FVector CurrentLocation = SceneComponent->GetRelativeLocation();
	float MoveSpeed = MoveOffset.Length() / MoveTime;
	FVector NextLocation = FMath::VInterpConstantTo(CurrentLocation, TargetLocation, DeltaTime, MoveSpeed);
	SceneComponent->SetRelativeLocation(NextLocation);
}

void UMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	InitialLocation = GetAttachParent()->GetRelativeLocation();
}

UMovingPlatform::UMovingPlatform() {
	PrimaryComponentTick.bCanEverTick = true;
}

