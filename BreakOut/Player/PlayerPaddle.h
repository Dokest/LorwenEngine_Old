#pragma once

#include "Game/WPlayerController.h"

using namespace Lorwen;

class PlayerPaddle : public WPlayerController
{
public:
	PlayerPaddle();
	~PlayerPaddle();

	void MoveRight(float value);
	void MoveUp(float value);
	void MoveLeft(float value);
	void MoveDown(float value);

	void Interact();
	void DeInteract();

	virtual void OnCreation() override;

	virtual void SetupInputComponent(class Lorwen::InputComponent* playerInput) override;
};

