#pragma once

#include "WorldObject.h"

class EPawn : public WorldObject
{
private:
	class WPlayerController* m_PlayerController;

public:
	EPawn();

	/* 
	*	Player Controller
	*/
public:
	inline const class WPlayerController* GetPlayerController() const { return m_PlayerController; } 

	void Possess(class WPlayerController* playerController);
	void _Unposses();

protected:
	virtual void OnPossess();

	/**
	 *  Input
	 */

	virtual void SetupInputComponent(class InputComponent* inputComponent);
};

