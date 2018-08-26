#pragma once

#include <string>
#include <functional>
#include <vector>
#include <map>
#include <array>

#include <typeinfo>

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

		void Register(class GameObject& gameObject);

//		std::map<const unsigned int, MemoryManager> m_ObjectHandlers;
//		
// 		template<typename T>
// 		T* Register(const unsigned int number)
// 		{
// 			unsigned int classHash = typeid(T).hash_code();
// 
// 			if (m_ObjectHandlers.count(classHash) == NULL)
// 			{
// 				m_ObjectHandlers[classHash] = MemoryManager();
// 				m_ObjectHandlers[classHash].Init(sizeof(T), number);
// 			}
// 
// 			T* object = (T*)m_ObjectHandlers[classHash].Alloc();
// 
// 			return object;
// 		}

		template<class T>
		static std::vector<T> m_Objects;
		
		template<class T>
		T* RegisterGameObject()
		{
			if (m_Objects<T>.size() == 0)
			{
/*				m_Objects<T> = std::map<unsigned int, T>();*/
				m_Objects<T>.push_back(T());

				return &m_Objects<T>[0];
			}

			m_Objects<T>.push_back(T());
			return &m_Objects<T>[m_Objects<T>.size() - 1];
		}

		std::vector<GameObject*> m_ObjectManager;

		template<typename T>
		T* RegisterGameObject(char Name)
		{
// 			unsigned int i = 0;
// 			while (m_ObjectManager.count(Name) == 1)
// 				i++;

			//const char newName = (Name + "_" + i);

			T* temp = new T();
			m_ObjectManager.push_back(temp);

			return temp;
		}

		void Update(float deltaTime);
	};

}
