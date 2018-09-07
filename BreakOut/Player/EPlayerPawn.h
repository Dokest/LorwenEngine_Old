#pragma once

#include "Game/EPawn.h"

class EPlayerPawn : public EPawn
{
private:
	class LSpriteComponent* SpriteComponent;
;
	float m_Velocity = 0;
	float m_MaxSpeed = 3.0f;

public:
	EPlayerPawn();


private:
	void MoveRight(float value);
	
	/**
	 *  Input
	 */
protected:
	virtual void SetupInputComponent(class InputComponent* playerInput);

	virtual void OnUpdate(float deltaTime) override;
};

