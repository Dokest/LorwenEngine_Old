#include "WPlayerController.h"

#include "LGameInputManager.h"

#include "LInputComponent.h"
#include "EPawn.h"


void WPlayerController::OnCreation()
{
	SetupInputComponent(GameObjectManager::RegisterComponent<LInputComponent>(this));
}

void WPlayerController::SetupInputComponent(LInputComponent* playerInput)
{
	m_InputComponent = playerInput;
}

void WPlayerController::PossessPawn(class EPawn* pawn)
{
	pawn->Possess(this);

	std::cout << "Pawn was possessed!" << std::endl;
}


