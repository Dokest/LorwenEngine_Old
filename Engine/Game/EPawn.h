#pragma once

#include "WorldObject.h"

using namespace Lorwen;

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
protected:
	virtual void OnPossess();

};

