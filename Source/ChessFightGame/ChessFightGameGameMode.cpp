// Copyright Epic Games, Inc. All Rights Reserved.

#include "ChessFightGameGameMode.h"
#include "ChessFightGamePlayerController.h"
#include "ChessFightGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

AChessFightGameGameMode::AChessFightGameGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AChessFightGamePlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}