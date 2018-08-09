#pragma once

namespace Lorwen {

	class BaseObjectRenderer
	{
	protected:


	public:

		virtual void Submit(class Renderable& renderable) = 0;
		virtual void Init() = 0;
		virtual void End() = 0;

	};
	
}