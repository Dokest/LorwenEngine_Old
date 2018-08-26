#pragma once

#include <string>

namespace Lorwen {

	class GameObject
	{
	private:
		/* Unique ID of each Game Object, 0 means it hasn't been created yet */
		unsigned int m_GameObjectID = 0;
		unsigned short m_GameObjectLocation = 0;

	protected:
		bool bCanTick = false;

	public:
		GameObject();
		~GameObject();

	protected:
		virtual void OnCreation() {}
		virtual void OnUpdate(float deltaTime) {}
		virtual void OnDestruction() {}

		virtual void Preparation() {}
		virtual void Construct() {};

	public:
		virtual inline void Create() { OnCreation(); }
		virtual inline void Update(float deltaTime) { OnUpdate(deltaTime); }
		virtual inline void Destroy() { OnDestruction(); }

	public:
		inline const unsigned int GetObjectID() const { return m_GameObjectID; }
		inline void SetObjectID(unsigned int newID) { m_GameObjectID = newID; }

	};
}
