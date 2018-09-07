#include "WPlayerController.h"

#include "GameInputManager.h"

#include "InputComponent.h"
#include "EPawn.h"


void WPlayerController::OnCreation()
{
	SetupInputComponent(GameObjectManager::RegisterComponent<InputComponent>(this));
}

void WPlayerController::SetupInputComponent(InputComponent* playerInput)
{
	m_InputComponent = playerInput;
}

void WPlayerController::PossessPawn(class EPawn* pawn)
{
	pawn->Possess(this);

	std::cout << "Pawn was possessed!" << std::endl;
}


