#include "PlayerPaddle.h"

#include "Game/KEY_Alphabet.h"

#include "Game/LInputComponent.h"

#include "Game/GameInputManager.h"

PlayerPaddle::PlayerPaddle()
{
}

PlayerPaddle::~PlayerPaddle()
{
}

void PlayerPaddle::Interact()
{
	std::cout << "Interacting" << std::endl;
}

void PlayerPaddle::DeInteract()
{
	std::cout << "De Interacting" << std::endl;
}

void PlayerPaddle::OnCreation()
{
	WPlayerController::OnCreation();
}

void PlayerPaddle::SetupInputComponent(class LInputComponent* playerInput)
{
	WPlayerController::SetupInputComponent(playerInput);
}
