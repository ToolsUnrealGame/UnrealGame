// Fill out your copyright notice in the Description page of Project Settings.


#include "TransferCollision.h"
#include "TouchRecognition.h"

// Sets default values for this component's properties
UTransferCollision::UTransferCollision()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UTransferCollision::BeginPlay()
{
	Super::BeginPlay();
	
}

void UTransferCollision::TransferCollisionToPlatform(bool IsCollide)
{
	for(AActor* Platform : TargetPlatforms){
		UTouchRecognition* PlatformComponent = Platform->FindComponentByClass<UTouchRecognition>();
		if(!PlatformComponent){
			FString ActorName=GetOwner()->GetActorNameOrLabel();
			UE_LOG(LogTemp, Display, TEXT("\"%s\" doesn't have PlatformComponent"),*ActorName);
			return;
		}
		PlatformComponent->ActivatePlatform(IsCollide);
	}
}