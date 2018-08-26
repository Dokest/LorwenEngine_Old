#pragma once

#include "Game/PlayerController.h"

class PlayerPaddle : public Lorwen::PlayerController
{
public:
	PlayerPaddle();
	~PlayerPaddle();

	void MoveRight(float Value);

	virtual void SetupInputComponent() override;
};

