// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ReceiveCollsion.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UReceiveCollsion : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class UNREAL_GAME_API IReceiveCollsion
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void ActivateCollision(AActor* Button,bool IsCollided) = 0;
	/**
	* Active State of this Object set to boolean Input
	* @param new Object State
	*/

	virtual bool IsCollided(AActor* Button) const = 0;

};
