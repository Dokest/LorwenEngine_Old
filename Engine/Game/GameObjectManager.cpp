#include "GameObjectManager.h"

#include <typeinfo>

#include "GameObject.h"

#include "BaseLevel.h"


GameObjectManager* GameObjectManager::Singleton_ObjectManager;

template<class T>
std::vector<T> GameObjectManager::m_Objects;

void GameObjectManager::Remove(unsigned int objectID)
{

}


void GameObjectManager::Update(float deltaTime)
{
 	for (GameObject* gameObject : m_GameObjectManager)
 	{
		gameObject->_Update(deltaTime);
	}
}