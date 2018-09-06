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

void PlayerPaddle::MoveRight(float value)
{
	std::cout << "Player is moving RIGHT -> " << value << std::endl;
}

void PlayerPaddle::MoveUp(float value)
{
	std::cout << "Player is moving UP -> " << value << std::endl;
}

void PlayerPaddle::MoveLeft(float value)
{
	std::cout << "Player is moving LEFT -> " << value << std::endl;
}

void PlayerPaddle::MoveDown(float value)
{
	std::cout << "Player is moving DOWN -> " << value << std::endl;
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

void PlayerPaddle::SetupInputComponent(class Lorwen::InputComponent* playerInput)
{
	WPlayerController::SetupInputComponent(playerInput);

	//Lorwen::GameInputManager::BindAction("MoveForward", Lorwen::EInputState::Press, this, &PlayerPaddle::MoveRight);

	playerInput->BindAxis("MoveUp", this, &PlayerPaddle::MoveUp);
	playerInput->BindAxis("MoveDown",this, &PlayerPaddle::MoveDown);
	playerInput->BindAxis("MoveRight",this, &PlayerPaddle::MoveRight);
	playerInput->BindAxis("MoveLeft", this, &PlayerPaddle::MoveLeft);
	playerInput->BindAxis("Shoot", this, &PlayerPaddle::MoveUp);

	playerInput->BindAction("Interact", Press, this, &PlayerPaddle::Interact);
	playerInput->BindAction("Interact", Release, this, &PlayerPaddle::DeInteract);
}
