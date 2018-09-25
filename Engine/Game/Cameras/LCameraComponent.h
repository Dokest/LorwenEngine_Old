#pragma once

#include "Game/LEntityComponent.h"
#include "Game/STransform.h"


/**
 *	The Camera Component is the element that if in use, is use to determine where the screen should be in the game scene.
 */
class LCameraComponent : public LEntityComponent
{
private:
	unsigned int m_CameraID = -1;

public:
	/* Indicates whether this camera is currently been used as render location */
	bool bInUse = true;


private:
	virtual void OnCreation() override;

public:
	/* Sets the camera as the current camera */
	void UseCamera();

	Mat4 GetViewMatrix();
};

