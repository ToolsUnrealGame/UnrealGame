// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include"ReceiveCollsion.h"
#include "TransferCollision.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREAL_GAME_API UTransferCollision : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTransferCollision();

protected:

public:

private:
	UFUNCTION(BlueprintCallable)
	void TransferCollisionToPlatform(bool IsCollide);
	/**
	 * Change Active State of Platforms that is linked by variable of 'TargetPlatforms' to Input bool Parameter.
	 * @param bIsActivated - new Platform Active State
	 */
	UFUNCTION(BlueprintCallable)
	void ToggleCollisionPlatform();
	/**
	 * Toogle Active State of Platforms that is linked by variable of 'TargetPlatforms' to Input bool Parameter.
	 * @param bIsActivated - new Platform Active State
	 */

	UPROPERTY(EditAnywhere)
	TArray<AActor*> TargetPlatforms;
	/**
	* Platform Actor Array that is wanted to be change.
	* This Actors have to have Component that implements IReceiveCollision Interface.
	*/

	TArray<IReceiveCollsion*> GetReceiveCollision(AActor* Platform) const;
	/**
	 * Change Active State of Platform to Input bool Parameter.
	 * @param Platform - Actor that has Component implementing IReceiveCollision
	 * @return Input Actor Components' IReceiveCollision Interfaces.
	 */

};
