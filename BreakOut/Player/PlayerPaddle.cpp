#include "PlayerPaddle.h"

#include "Game/KEY_Alphabet.h"

#include "Game/InputComponent.h"

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

void PlayerPaddle::SetupInputComponent(class InputComponent* playerInput)
{
	WPlayerController::SetupInputComponent(playerInput);

	playerInput->BindAction("Interact", Press, this, &PlayerPaddle::Interact);
}
