// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include"ReceiveCollsion.h"
#include "ReactPlatform.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREAL_GAME_API UReactPlatform : public USceneComponent,public IReceiveCollsion
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UReactPlatform();

protected:

public:
	//-------IReceiveCollision Interface's Implementations.------------------
	virtual void ActivateCollision(AActor* Button, bool IsCollide) override;
	virtual bool IsCollided(AActor* Button) const override;
	//-----------------------------------------------------------------------
	/**
	 * Change Active State of Platform to Input bool Parameter.
	 * @param bIsActivated - new Platform Active State
	 */
	virtual void BeginPlay() override;
	bool IsActivated()const;
	
private:
	UPROPERTY(EditAnywhere)
		TArray<AActor*> Buttons;
	TArray<bool> EachButtonCollides;
};
/*
* Depending on 'bIsActivated' bool value, Platform is Activated.
* This should be Abstract Class, So don't make Instance of this class.
*/
