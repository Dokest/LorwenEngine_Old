#pragma once

#include "Game/EPawn.h"

class EPlayerPawn : public EPawn
{
private:
	class LSpriteComponent* SpriteComponent;
;
	float m_Velocity = 0;
	float m_MaxSpeed = 500.0f;

public:
	EPlayerPawn();


private:
	void MoveRight(float value);
	
	/**
	 *  Input
	 */
protected:
	virtual void SetupInputComponent(class LInputComponent* playerInput);

	virtual void OnUpdate(float deltaTime) override;
};

