#include "EPlayerPawn.h"

#include "Graphics/LSpriteComponent.h"
#include "Game/Cameras/LCameraComponent.h"

#include <stdlib.h>

#include "Console/ConsoleLogger.h"

EPlayerPawn::EPlayerPawn()
{
	SpriteComponent = RegisterComponent<LSpriteComponent>("SpriteComp");
	CameraComponent = RegisterComponent<LCameraComponent>("CameraComp");

	Transform.Position = Maths::Vec3(400.0f, 50.0f, 0.0f);

	SpriteComponent->SetLocation(Maths::Vec2(Transform.Position.x, Transform.Position.y));
	SpriteComponent->SetSize(Maths::Vec2(200, 40.f));
	//SpriteComponent->SetTint(Vec4(0.4f, 0.6f, 0.8f, 1.0f));

	CameraComponent->UseCamera();
	CameraComponent->SetAbsoluteLocation(Maths::Vec3(SpriteComponent->GetLocation().x, SpriteComponent->GetLocation().y, 0.0f));
}


void EPlayerPawn::MoveRight(float value)
{
	if (value != 0)
	{
		m_Velocity = (500.0f * value);
	}
	else
	{
		if (m_Velocity > 0 && m_Velocity < 50)
			m_Velocity -= 50.0f;
		else if (m_Velocity < 0 && m_Velocity > 50)
			m_Velocity += 50.0f;
 		else
 			m_Velocity = 0;
	}

}

void EPlayerPawn::MoveUp(float value)
{
	if (value != 0)
		CameraComponent->SetAbsoluteLocation(Maths::Vec3(CameraComponent->GetAbsoluteLocation().x, CameraComponent->GetAbsoluteLocation().y + (10 * value), CameraComponent->GetAbsoluteLocation().z));
}

void EPlayerPawn::Interact()
{
	Logger::ConsoleLog("Interact!");
}

void EPlayerPawn::ShowMenu()
{
	Logger::ConsoleLog("The menu is now Open");
}

void EPlayerPawn::SetupInputComponent(class LInputComponent* playerInput)
{
	EPawn::SetupInputComponent(playerInput);

	playerInput->BindAxis("MoveRight", this, &EPlayerPawn::MoveRight);
	playerInput->BindAxis("MoveUp", this, &EPlayerPawn::MoveUp);
	playerInput->BindAction("Interact", EButtonAction::RELEASE, this, &EPlayerPawn::Interact);
	playerInput->BindAction("ShowMenu", EButtonAction::PRESS, this, &EPlayerPawn::ShowMenu);
}

void EPlayerPawn::OnUpdate(float deltaTime)
{
 	float pos = SpriteComponent->GetLocation().x;

	Maths::Vec2 FinalPos(pos + (m_Velocity * deltaTime), SpriteComponent->GetLocation().y);

	if (FinalPos.x < 5 + SpriteComponent->GetSize().x / 2)
		FinalPos.x = 5 + SpriteComponent->GetSize().x / 2;
	else if (FinalPos.x > ((1280 - SpriteComponent->GetSize().x / 2) - 5))
		FinalPos.x = (1280 - SpriteComponent->GetSize().x / 2) - 5;

	SpriteComponent->SetLocation(FinalPos);

	//CameraComponent->SetAbsoluteLocation(Maths::Vec3(FinalPos.x, FinalPos.y, 0.0f));
}
