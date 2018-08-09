#pragma once

//#include "WorldObject.h"

#include <map>

class WorldObject;

namespace Lorwen {

	class BasicObjectManager
	{
	private:
		static std::map<const char*, WorldObject> m_WorldObjects;



	public:
		BasicObjectManager();
		~BasicObjectManager();

		static const WorldObject* RegisterWorldObject(const char* name)
		{


		}
	};
	
}


