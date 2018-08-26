#pragma once

#include "GameObject.h"

namespace Lorwen {

	class Component : public GameObject
	{
	public:
		GameObject* Owner;

	};



}