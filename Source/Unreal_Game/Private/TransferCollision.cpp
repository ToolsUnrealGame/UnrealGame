// Fill out your copyright notice in the Description page of Project Settings.


#include "TransferCollision.h"
#include "ReactPlatform.h"
#include"ReceiveCollsion.h"
#include"MovingPlatform.h"

// Sets default values for this component's properties
UTransferCollision::UTransferCollision()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}


void UTransferCollision::TransferCollisionToPlatform(bool IsCollide)
{
	for (AActor* Platform : TargetPlatforms) {
		TArray<IReceiveCollsion*> ReceiveCollisions = GetReceiveCollision(Platform);

		for (IReceiveCollsion* ReceiveCollision : ReceiveCollisions) {
			if (ReceiveCollision) {
				ReceiveCollision->ActivateCollision(GetOwner(), IsCollide);
			}
		}
	}
}

void UTransferCollision::ToggleCollisionPlatform() {
	for (AActor* Platform : TargetPlatforms) {
		TArray<IReceiveCollsion*> ReceiveCollisions = GetReceiveCollision(Platform);

		for (IReceiveCollsion* ReceiveCollision : ReceiveCollisions) {
			if (ReceiveCollision) {
				bool bNowCollided =ReceiveCollision->IsCollided(GetOwner());
				ReceiveCollision->ActivateCollision(GetOwner(), !bNowCollided);
			}
		}
	}
}

TArray<IReceiveCollsion*> UTransferCollision::GetReceiveCollision(AActor* Platform) const{

	TSet< UActorComponent*> ActorComponents = Platform->GetComponents();
	TArray<IReceiveCollsion*> ret = TArray<IReceiveCollsion*>();

	for (UActorComponent* ActorComponent : ActorComponents) {
		IReceiveCollsion* InterfaceReceiveCol = Cast<IReceiveCollsion>(ActorComponent);

		if (!InterfaceReceiveCol) {
			FString ActorName = Platform->GetActorNameOrLabel();
			UE_LOG(LogTemp, Display, TEXT("\"%s\" doesn't have IReceiveCollsion"), *ActorName);
			continue;
		}

		ret.Add(InterfaceReceiveCol);
	}

	return ret;
}