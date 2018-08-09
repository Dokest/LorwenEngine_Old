#pragma once

namespace Lorwen {

	class BaseLevelMode
	{
	protected:
		// NEEDS TO HOLD POINTER TO PLAYERS

		int borrar;

	public:

		virtual void LevelModeStart() = 0;
		virtual void LevelModeEnd() = 0;


	};


}