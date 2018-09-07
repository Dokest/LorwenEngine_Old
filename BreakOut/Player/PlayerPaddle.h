#pragma once

#include "Game/WPlayerController.h"


class PlayerPaddle : public WPlayerController
{
public:
	PlayerPaddle();
	~PlayerPaddle();

	void Interact();
	void DeInteract();

	virtual void OnCreation() override;

	virtual void SetupInputComponent(class InputComponent* playerInput) override;
};

