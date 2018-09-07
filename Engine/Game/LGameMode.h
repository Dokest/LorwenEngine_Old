#pragma once

#include "Object.h"

#include <array>
#include <string>

#include "GameObjectManager.h"

class WPlayerController;

class LGameMode : public Object
{
private:
	std::array<WPlayerController*, 4> m_PlayerControllers = { nullptr, nullptr, nullptr, nullptr };

	unsigned short m_NumberOfPlayers = 0;

protected:
	void* DefaultPlayerController = nullptr;
	
	void* DefaultPlayerPawn = nullptr;

public:
	LGameMode();

	/**
	 *  Players
	 */
public:
	inline const unsigned short GetNumberOfPlayers() const { return m_NumberOfPlayers; }

	template<typename T>
	T* AddPlayerController()
	{
		if (GetNumberOfPlayers() >= m_PlayerControllers.max_size())
			return nullptr;

		std::string newControllerName = "PlayerController_" + std::to_string(GetNumberOfPlayers());
		T* newPlayerController = GameObjectManager::RegisterGameObject<T>(newControllerName.c_str());

		WPlayerController* playerController = static_cast<WPlayerController*>(newPlayerController);
		m_PlayerControllers[GetNumberOfPlayers()] = playerController;

		m_NumberOfPlayers++;

		return newPlayerController;
	}
};

