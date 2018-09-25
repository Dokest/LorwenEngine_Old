#pragma once

#include "EEntity.h"


class WPlayerController : public EEntity // Needs to change to RENDERABLE -> Needs to change to ACTOR
{
private:
	unsigned char m_ControllerID;
	class EPawn* m_PossessPawn;

	class LInputComponent* m_InputComponent;
public:

	virtual void OnCreation() override;

	/**
	 *  INPUT HANDELING
	 */

public:
	virtual void SetupInputComponent(class LInputComponent* playerInput);

	void PossessPawn(class EPawn* pawn);

	class LInputComponent* GetLInputComponent() const { return m_InputComponent; }
};


