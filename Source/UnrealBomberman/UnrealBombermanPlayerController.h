// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "UnrealBombermanPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class UNREALBOMBERMAN_API AUnrealBombermanPlayerController : public APlayerController
{
	GENERATED_BODY()


public:
	AUnrealBombermanPlayerController();

	/** Called for forwards/backward input */
	void MoveVertical(float Value);

	/** Called for side to side input */
	void MoveHorizontal(float Value);

protected:
	// APlayerController interface
	virtual void SetupInputComponent() override;
	// End of APlayerController interface
	
};
