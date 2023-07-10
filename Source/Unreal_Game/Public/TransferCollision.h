// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TransferCollision.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREAL_GAME_API UTransferCollision : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTransferCollision();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
private:
	UPROPERTY(EditAnywhere)
	TArray<AActor*> TargetPlatforms;

	UFUNCTION(BlueprintCallable)
	void TransferCollisionToPlatform(bool IsCollide);
};
