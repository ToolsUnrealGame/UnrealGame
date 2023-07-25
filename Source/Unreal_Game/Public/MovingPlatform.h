// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ReactPlatform.h"
#include"ReceiveCollsion.h"
#include "MovingPlatform.generated.h"
/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UNREAL_GAME_API UMovingPlatform : public UReactPlatform
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;

public:
	UMovingPlatform();
	//-------IReceiveCollision Interface's Implementations.------------------
	/**
	* Active State of this Object set to boolean Input
	* If Activated Parent Scene Component moves to MoveOffeset FVector in MoveTime.
	* @param new Object Active State
	*/
	//virtual void ActivateCollision(bool IsCollide) override;
	/**
	* Toggle State of this Object set to boolean Input
	* If Activated Parent Scene Component moves to MoveOffeset FVector in MoveTime.
	* @param new Object Active State
	*/
	//-----------------------------------------------------------------------
	//virtual void ToggleCollision() override;
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
private:
	UPROPERTY(EditAnywhere)
	float MoveTime;

	UPROPERTY(EditAnywhere)
	FVector MoveOffset;

	FVector InitialLocation;
};
