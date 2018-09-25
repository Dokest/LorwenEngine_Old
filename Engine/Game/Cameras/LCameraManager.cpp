#include "LCameraManager.h"

#include "LCameraComponent.h"

std::array<class LCameraComponent*, 10> LCameraManager::m_Cameras;

class LCameraComponent* LCameraManager::CameraInUse;

void LCameraManager::UseCamera(class LCameraComponent* cameraComponent)
{
	CameraInUse->bInUse = false;

	CameraInUse = cameraComponent;
	cameraComponent->bInUse = true;
}

unsigned int LCameraManager::AddNewCamera(class LCameraComponent* newCamera)
{
	if (CameraInUse == nullptr)
		CameraInUse = newCamera;

	for (unsigned int i = 0; i < m_Cameras.size(); i++)
	{
		if (m_Cameras[i] == nullptr)
		{
			m_Cameras[i] = newCamera;

			return i;
		}
	}

}
