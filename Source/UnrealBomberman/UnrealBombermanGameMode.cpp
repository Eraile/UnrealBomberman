// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "UnrealBombermanGameMode.h"
#include "UnrealBombermanCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

AUnrealBombermanGameMode::AUnrealBombermanGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void AUnrealBombermanGameMode::BeginPlay()
{
	//// Spawn 2 players
	//for (int playerID = 0; playerID < 2; playerID++)
	//{
	//	UGameplayStatics::CreatePlayer(GetWorld(), playerID, true);
	//}
}
