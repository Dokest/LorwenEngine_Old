#pragma once

#include "BaseRenderable.h"

namespace Lorwen { namespace Graphics {

	class BaseRenderer
	{
	public:
		virtual void Render() = 0;

		virtual void Submit(BaseRenderable* renderable) = 0;
	};


} }