#pragma once

namespace Lorwen {

	/*
	*	A game Instance is persistent during the game session.
	*	It should hold info that persist along multiple levels, like player-points, player-wins.. 
	*/

	class BaseGameInstance
	{
	protected:

	public:
		virtual void StartGameSession() = 0;
		virtual void EndGameSession() = 0;


	};

}