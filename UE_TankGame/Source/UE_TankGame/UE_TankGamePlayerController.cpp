// Copyright Epic Games, Inc. All Rights Reserved.


#include "UE_TankGamePlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "UE_TankGameCameraManager.h"

AUE_TankGamePlayerController::AUE_TankGamePlayerController()
{
	// set the player camera manager class
	PlayerCameraManagerClass = AUE_TankGameCameraManager::StaticClass();
}

void AUE_TankGamePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
		{
			Subsystem->AddMappingContext(CurrentContext, 0);
		}
	}
}
