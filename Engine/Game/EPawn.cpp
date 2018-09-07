#include "EPawn.h"

#include "GameObjectManager.h"

#include "WPlayerController.h"

EPawn::EPawn()
{

}

void EPawn::Possess(class WPlayerController* playerController)
{
	m_PlayerController = playerController;

	SetupInputComponent(playerController->GetInputComponent());

	OnPossess();
}

void EPawn::_Unposses()
{
	m_PlayerController = nullptr;
}

void EPawn::OnPossess()
{

}

void EPawn::SetupInputComponent(class InputComponent* inputComponent)
{

}
