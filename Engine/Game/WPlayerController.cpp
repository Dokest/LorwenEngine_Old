#include "WPlayerController.h"

#include "GameInputManager.h"

#include "InputComponent.h"
#include "EPawn.h"

namespace Lorwen {

	void WPlayerController::OnCreation()
	{
		SetupInputComponent(GameObjectManager::RegisterComponent<InputComponent>(this));
	}

	void WPlayerController::SetupInputComponent(InputComponent* playerInput)
	{
	}

	void Lorwen::WPlayerController::PossessPawn(class EPawn* pawn)
	{
		//pawn->OnPossess();
	}
}

