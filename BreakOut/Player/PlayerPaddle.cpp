#include "PlayerPaddle.h"



PlayerPaddle::PlayerPaddle()
{
}

PlayerPaddle::~PlayerPaddle()
{
}

void PlayerPaddle::MoveRight(float Value)
{
	std::cout << "MOVING RIGHT\n";
}

void PlayerPaddle::SetupInputComponent()
{
	PlayerController::SetupInputComponent();

	PlayerInputComponent->BindInput("MoveRigth", K, &PlayerPaddle::MoveRight, this);
}
