#include "GameObjectManager.h"

#include <typeinfo>

#include "GameObject.h"

namespace Lorwen {
	
	GameObjectManager* GameObjectManager::Singleton_ObjectManager;
	
	template<class T>
	std::vector<T> GameObjectManager::m_Objects;

	void GameObjectManager::Remove(unsigned int objectID)
	{

	}




	void GameObjectManager::Update(float deltaTime)
	{
// 		for (auto objectInstances : m_GameObjects)
// 		{
// 			for (GameObject& object : objectInstances)
// 				object.Update(deltaTime);
//  		}
	}

}