#pragma once

namespace Lorwen {

	class Object
	{
	private:
		/* Unique ID of each Game Object, 0 means it hasn't been created yet */
		unsigned int m_GameObjectID = 0;

	public:
		Object() {}
	};
}
