#pragma once

#include "GameObject.h"

#include "Maths/Maths.h"
#include "STransform.h"

#include <vector>

using namespace Maths;


class EEntity : public GameObject
{
private:
	std::vector<class Component*> m_pComponents;

public:
	STransform Transform;


	EEntity();

public:
	inline std::vector<class Component*>& GetComponents() { return m_pComponents; }


protected:
	virtual void OnCreation() {}
	virtual void OnUpdate(float deltaTime) {}
	virtual void OnDestruction() {}

private:
	inline void _Create() { EEntity::_Create(); }
		inline void _Update(float deltaTime) { EEntity::OnUpdate(deltaTime); }
		inline void _Destroy() { EEntity::OnDestruction(); }
	
};

