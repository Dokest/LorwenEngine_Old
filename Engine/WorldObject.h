#pragma once

#include "BasicObjectManager.h"

#include <string>

namespace Lorwen {

	class WorldObject
	{
	protected:
		const std::string Name;
		const unsigned int RegisterID;



	public:
		WorldObject() { registerWorldObject(); }
		virtual ~WorldObject();

	private:
		void registerWorldObject()
		{



		}

	protected:
		virtual void OnCreation();
		virtual void OnUpdate(float deltaTime);
		virtual void OnDestruction();

	};


}
