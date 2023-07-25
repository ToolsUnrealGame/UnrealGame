// Fill out your copyright notice in the Description page of Project Settings.


#include "ReactPlatform.h"

// Sets default values for this component's properties
UReactPlatform::UReactPlatform()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
	
}

void UReactPlatform::BeginPlay() {
	EachButtonCollides.Init(false, Buttons.Num());
}

void UReactPlatform::ActivateCollision(AActor* Button,bool IsCollide) {
	int32 findedIndex = Buttons.Find(Button);
	if (findedIndex == INDEX_NONE ) {
		UE_LOG(LogTemp, Display, TEXT("Matching Button is Not Found"));
		return;
	}
	if (!EachButtonCollides.IsValidIndex(findedIndex)) {
		UE_LOG(LogTemp, Display, TEXT("This Button Collides Array Out of Range Index"));
		UE_LOG(LogTemp, Display, TEXT("EachButtonCollides Length:%i Access Index:%i"),EachButtonCollides.Num(),findedIndex);
		UE_LOG(LogTemp, Display, TEXT("Button Length:%i"), Buttons.Num());
		return;
	}
	else{
		EachButtonCollides[findedIndex] = IsCollide;
	}
}

bool UReactPlatform::IsCollided(AActor* Button) const {
	int32 findedIndex = Buttons.Find(Button);
	if (findedIndex == INDEX_NONE) {
		UE_LOG(LogTemp, Display, TEXT("Matching Button is Not Found"));
		return false;
	}
	if (!EachButtonCollides.IsValidIndex(findedIndex)) {
		UE_LOG(LogTemp, Display, TEXT("This Button Collides Array Out of Range Index"));
		UE_LOG(LogTemp, Display, TEXT("EachButtonCollides Length:%i Access Index:%i"), EachButtonCollides.Num(), findedIndex);
		UE_LOG(LogTemp, Display, TEXT("Button Length:%i"), Buttons.Num());
		return false;
	}
	return EachButtonCollides[findedIndex];
}

bool UReactPlatform::IsActivated()const {
	if (EachButtonCollides.Num() == 0) {
		return false;
	}
	for (bool IsCollide : EachButtonCollides) {
		if (!IsCollide) {
			return false;
		}
	}
	return true;
}