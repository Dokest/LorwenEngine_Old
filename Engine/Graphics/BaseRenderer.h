#pragma once

#include "LRenderableComponent.h"

#include "Maths/Maths.h"

class BaseRenderer
{
protected:
	Maths::Mat4 m_ProjectionMatrix;

public:
	virtual void Render() = 0;

	//virtual void Submit(LRenderableComponent* renderable) = 0;

	inline const Maths::Mat4 GetProjectionMatrix() const { return m_ProjectionMatrix; }
};
