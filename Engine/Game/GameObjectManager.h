#pragma once

#include <string>
#include <functional>
#include <vector>
#include <map>
#include <array>

#include <typeinfo>

#include "Object.h"
#include "GameObject.h"

#include "MemoryManager.h"

namespace Lorwen {
	
#define MAX_GAME_OBJECTS 1000

	template<typename T>
	struct ObjectRegistration
	{
		unsigned int ClassID;
		std::vector<T> m_InstancedObjects;
	};

	template<typename T>
	struct SGameObjectHandle
	{
		unsigned int HandleID;

		std::vector<T> ArrayInstance;

		SGameObjectHandle() {}

	};

	class GameObjectManager
	{
	private:

	public:
		static GameObjectManager* Singleton_ObjectManager;

		unsigned int m_ObjectCounter;

	public:

		GameObjectManager()
		{
			Singleton_ObjectManager = this;
		}

		void Remove(unsigned int objectID);

		template<class T>
		static std::vector<T> m_Objects;
		
		template<class T>
		static T* RegisterGameObjectTest()
		{
			if (m_Objects<T>.size() == 0)
			{
/*				m_Objects<T> = std::map<unsigned int, T>();*/
				m_Objects<T>.push_back(T());

				return &m_Objects<T>[0];
			}

			m_Objects<T>.push_back(T());
			T* newObject = &m_Objects<T>[m_Objects<T>.size() - 1];
			newObject->_Create();
			return newObject;
		}

		std::vector<class Object*> m_ObjectManager;

		template<typename T>
		static T* RegisterGameObject(const char* Name)
		{
			T* newObject = new T();
			Singleton_ObjectManager->m_ObjectManager.push_back(newObject);

			GameObject* temp = (GameObject*)newObject;
			temp->_Create();

			return newObject;
		}

		template<typename T>
		static T* RegisterComponent(class GameObject* owner)
		{
			T* newComponent = new T();
			newComponent->Owner = owner;
			Singleton_ObjectManager->m_ObjectManager.push_back(newComponent);

			GameObject* temp = (GameObject*)newComponent;
			temp->_Create();

			return newComponent;
		}

		void Update(float deltaTime);
	};

}
