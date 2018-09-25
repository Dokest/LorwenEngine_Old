#pragma once

#include "Object.h"



class Component : public Object
{
public:
	class GameObject* Owner;

protected:
	virtual void OnCreation() {}
	virtual void OnUpdate(float deltaTime) {}
	virtual void OnDestruction() {}

	virtual void Preparation() {}
	virtual void Construct() {}

public:
	inline void _Create() { OnCreation(); }
	inline void _Update(float deltaTime) { OnUpdate(deltaTime); }
	inline void _Destroy() { OnDestruction(); }

};
