#pragma once

namespace Lorwen {

	class BaseLevel
	{
	protected:


	public:
		virtual ~BaseLevel() {}

		virtual void Load() = 0;

		virtual void Init() = 0;

		virtual void End() = 0; 

	};


}