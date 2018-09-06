#include "EPawn.h"



EPawn::EPawn()
{


}


void EPawn::Possess(class WPlayerController* playerController)
{
	m_PlayerController = playerController;
}

void EPawn::OnPossess()
{

}
