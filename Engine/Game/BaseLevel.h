#pragma once

namespace Lorwen {

	class BaseLevel
	{
	protected:
		class WPlayerController* PlayerController = nullptr;

	public:
		virtual ~BaseLevel() {}

		virtual void Load() = 0;

		virtual void Init() = 0;

		virtual void End() = 0; 

		virtual void PrepareLevel() = 0;
	};


}