#pragma once

#include "WorldObject.h"

namespace Lorwen {

	class WPlayerController : public WorldObject // Needs to change to RENDERABLE -> Needs to change to ACTOR
	{
	private:
		unsigned char m_ControllerID;
		class EPawn* m_PossessPawn;

	public:

		virtual void OnCreation() override;

		/**
		 *  INPUT HANDELING
		 */

	public:
		virtual void SetupInputComponent(class InputComponent* playerInput);

		void PossessPawn(class EPawn* pawn);
	};
}

