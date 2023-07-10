// Fill out your copyright notice in the Description page of Project Settings.


#include "AutomaticDoors.h"

void UAutomaticDoors::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FVector TargetLocation; 
	if(IsActivated()){
		TargetLocation = InitialLocation + MoveOffset;
	}else{
		TargetLocation = InitialLocation;
	}
	AActor* Owner=GetOwner();
	FVector CurrentLocation = Owner->GetActorLocation();
	float MoveSpeed=MoveOffset.Length() /MoveTime;
	FVector NextLocation= FMath::VInterpConstantTo(CurrentLocation,TargetLocation,DeltaTime,MoveSpeed);
	Owner->SetActorLocation(NextLocation);
}

void UAutomaticDoors::BeginPlay()
{
	Super::BeginPlay();
	InitialLocation=GetOwner()->GetActorLocation();
}

UAutomaticDoors::UAutomaticDoors(){
	PrimaryComponentTick.bCanEverTick = true;
}