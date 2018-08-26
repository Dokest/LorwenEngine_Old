#include "PlayerController.h"

#include "GameInputManager.h"

namespace Lorwen {

	PlayerController::PlayerController()
	{
	}


	PlayerController::~PlayerController()
	{
	}

	void PlayerController::OnCreation()
	{
		
	}

	void PlayerController::SetupInputComponent()
	{
		PlayerInputComponent = GameInputManager::RegisterInputComponent(this);
	}

}