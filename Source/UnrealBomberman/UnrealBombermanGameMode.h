// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UnrealBombermanGameMode.generated.h"

UCLASS(minimalapi)
class AUnrealBombermanGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AUnrealBombermanGameMode();
	virtual void BeginPlay() override;
};



