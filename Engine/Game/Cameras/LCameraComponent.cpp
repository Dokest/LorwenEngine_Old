#include "LCameraComponent.h"

#include "LCameraManager.h"

void LCameraComponent::OnCreation()
{
	m_CameraID = LCameraManager::AddNewCamera(this);

	//Owner = static_cast<EEntity>(Owner);
}

void LCameraComponent::UseCamera()
{
	LCameraManager::UseCamera(this);
}

Maths::Mat4 LCameraComponent::GetViewMatrix()
{
	Maths::Mat4 viewMatrix(1.0f);

	viewMatrix *= viewMatrix.Translation(Transform.Position);

	return viewMatrix;
}
