#pragma once

#include "WorldObject.h"

namespace Lorwen {

	class PlayerController : public WorldObject // Needs to change to RENDERABLE -> Needs to change to ACTOR
	{
	private:
		unsigned char m_ControllerID;
		class InputComponent* PlayerInputComponent;


	public:
		PlayerController();
		~PlayerController();

		virtual void OnCreation() override;

		virtual void SetupInputComponent();

		//void PossesPawn();
		//void UnpossesPawn();
	};
}

