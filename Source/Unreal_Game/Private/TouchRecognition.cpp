// Fill out your copyright notice in the Description page of Project Settings.


#include "TouchRecognition.h"

// Sets default values for this component's properties
UTouchRecognition::UTouchRecognition()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	bIsActivated=false;
	// ...
}

// Called every frame
void UTouchRecognition::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	// ...
}

bool UTouchRecognition::IsActivated() const{
	return bIsActivated;
}

void UTouchRecognition::ActivatePlatform(bool bIsTurnOn){
	// -----------printing log debug code for checking -----------
	FString Name=GetOwner()->GetActorNameOrLabel();
	FString TurnOnState=bIsTurnOn?"On":"Off";
	UE_LOG(LogTemp,Display,TEXT("%s is Turn %s"),*Name,*TurnOnState);
	// -----------------------------------------------------------
	bIsActivated=bIsTurnOn;
}

void  UTouchRecognition::TogglePlatform(){
	bIsActivated=!bIsActivated;
}

/*// Called when the game starts
void UTouchRecognition::BeginPlay()
{
	Super::BeginPlay();
	// ...
}
*/