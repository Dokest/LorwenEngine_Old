#pragma once

#include <string>

#include "Object.h"
#include "Component.h"

#include "GameObjectManager.h"
#include "LInputComponent.h"


class GameObject : public Object
{
private:
	std::vector<Component*> m_Components;

protected:
	bool bCanTick = false;

public:
	GameObject() {}

private:
	virtual void OnCreation() {}
	virtual void OnUpdate(float deltaTime) {}
	virtual void OnDestruction() {}

	virtual void Preparation() {}
	virtual void Construct() {}

public:
	
	template<class T>
	inline T* RegisterComponent(const char* name)
	{
		T* comp = GameObjectManager::RegisterComponent<T>(this);
		return comp;
	}

	inline void _Create()
	{
		OnCreation();
	}
	inline void _Update(float deltaTime) 
	{
		OnUpdate(deltaTime);

		for (Component* comp : m_Components)
			comp->_Update(deltaTime);
	}
	inline void _Destroy() 
	{
		OnDestruction();

		for (Component* comp : m_Components)
			comp->_Destroy();
	}

};

