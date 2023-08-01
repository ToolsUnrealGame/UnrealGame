// Fill out your copyright notice in the Description page of Project Settings.


#include "ReactiveLamp.h"
#include<Components/PointLightComponent.h>

void UReactiveLamp::ActivateCollision(AActor* Button, bool IsCollide) {
	Super::ActivateCollision(Button, IsCollide);

	UPointLightComponent* PointLightComponent = GetOwner()->FindComponentByClass<UPointLightComponent>();
	if (!PointLightComponent) {
		UE_LOG(LogTemp, Display, TEXT("%s PointLightComponent is Missing"), *GetOwner()->GetActorNameOrLabel());
		return;
	}
	UE_LOG(LogTemp, Display, TEXT("%s has PointLightComponent"), *GetOwner()->GetActorNameOrLabel());
	if (IsActivated()) {
		PointLightComponent->SetVisibility(true);
	}
	else {
		PointLightComponent->SetVisibility(false);
	}
}

void UReactiveLamp::BeginPlay() {
	Super::BeginPlay();
	GetPointLightComponent()->SetVisibility(false);
}

UPointLightComponent* UReactiveLamp::GetPointLightComponent()const {
	return  GetOwner()->FindComponentByClass<UPointLightComponent>();
}
