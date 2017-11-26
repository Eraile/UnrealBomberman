// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealBombermanPlayerController.h"
#include "Runtime/Engine/Classes/Engine/LocalPlayer.h"
#include "HeadMountedDisplayFunctionLibrary.h"	// OnResetVR
#include "GameFramework/Character.h"			// Character


AUnrealBombermanPlayerController::AUnrealBombermanPlayerController()
{
	bShowMouseCursor = true;
	bEnableClickEvents = true;
	bEnableTouchEvents = true;
	DefaultMouseCursor = EMouseCursor::Default;
}

void AUnrealBombermanPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	//// VR headset functionality
	//InputComponent->BindAction("ResetVR", IE_Pressed, this, &AUnrealBombermanPlayerController::OnResetVR);

	if (GetLocalPlayer() == NULL)
	{
		GLog->Log("AUnrealBombermanPlayerController::SetupInputComponent() - GetLocalPlayer NULL");
		return;
	}

	// Map movement/actions input (2 players on same keyboard)
	int32 id = GetLocalPlayer()->GetControllerId();
	if (id == 0)
	{
		GLog->Log("AUnrealBombermanPlayerController::SetupInputComponent() - BindAxis of P1");
		InputComponent->BindAxis("P1_Vertical", this, &AUnrealBombermanPlayerController::MoveVertical);
		InputComponent->BindAxis("P1_Horizontal", this, &AUnrealBombermanPlayerController::MoveHorizontal);
		// TODO : Add P1 bomb and remote bomb trigger
	}
	else if (id == 1)
	{
		GLog->Log("AUnrealBombermanPlayerController::SetupInputComponent() - BindAxis of P2");
		InputComponent->BindAxis("P2_Vertical", this, &AUnrealBombermanPlayerController::MoveVertical);
		InputComponent->BindAxis("P2_Horizontal", this, &AUnrealBombermanPlayerController::MoveHorizontal);
		// TODO : Add P2 bomb and remote bomb trigger
	}
}

void AUnrealBombermanPlayerController::MoveVertical(float Value)
{
	APawn* attachedPawn = this->GetPawn();
	if (attachedPawn != NULL)
	{
		if (Value != 0.0f)
		{
			// find out which way is forward
			const FRotator Rotation = GetControlRotation();
			const FRotator YawRotation(0, Rotation.Yaw, 0);

			// get forward vector
			const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
			// add movement in that direction
			attachedPawn->AddMovementInput(Direction, Value);
		}
	}
}

void AUnrealBombermanPlayerController::MoveHorizontal(float Value)
{
	APawn* attachedPawn = this->GetPawn();
	if (attachedPawn != NULL)
	{
		if (Value != 0.0f)
		{
			// find out which way is right
			const FRotator Rotation = GetControlRotation();
			const FRotator YawRotation(0, Rotation.Yaw, 0);

			// get right vector 
			const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
			// add movement in that direction
			attachedPawn->AddMovementInput(Direction, Value);
		}
	}
}
