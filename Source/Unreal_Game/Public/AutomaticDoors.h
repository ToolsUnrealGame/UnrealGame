// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TouchRecognition.h"
#include "AutomaticDoors.generated.h"

/**
 * 
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREAL_GAME_API UAutomaticDoors : public UTouchRecognition
{
	GENERATED_BODY()

	protected:
	virtual void BeginPlay() override;

	public:
	UAutomaticDoors();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	private:
	UPROPERTY(EditAnywhere)
	float MoveTime;
	UPROPERTY(EditAnywhere)
	FVector MoveOffset;
	FVector InitialLocation;
};
