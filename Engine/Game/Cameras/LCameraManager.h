#pragma once

#include <array>

class LCameraManager
{
private:
	static std::array<class LCameraComponent*, 10> m_Cameras;

public:
	/* Current camera in use */
	static class LCameraComponent* CameraInUse;

public:

	/* Sets a given camera as the current main camera */
	static void UseCamera(class LCameraComponent* cameraComponent);

	static unsigned int AddNewCamera(class LCameraComponent* newCamera);


};

