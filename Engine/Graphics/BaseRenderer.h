#pragma once

#include "BaseRenderable.h"

#include "Maths/Maths.h"

namespace Lorwen { namespace Graphics {

	class BaseRenderer
	{
	protected:
		Maths::Mat4 m_ProjectionMatrix;

	public:
		virtual void Render() = 0;

		//virtual void Submit(BaseRenderable* renderable) = 0;

		inline const Maths::Mat4 GetProjectionMatrix() const { return m_ProjectionMatrix; }
	};


} }