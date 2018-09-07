#include "EPlayerPawn.h"

#include "Graphics/LSpriteComponent.h"

#include <stdlib.h>

EPlayerPawn::EPlayerPawn()
{
	SpriteComponent = GameObjectManager::RegisterComponent<LSpriteComponent>(this);

	m_NFLocation = Maths::Vec2(400.0f, 50.0f);

	SpriteComponent->SetLocation(m_NFLocation);
	SpriteComponent->SetSize(Maths::Vec2(80, 20.f));
	SpriteComponent->SetTint(Vec4(0.4f, 0.6f, 0.8f, 1.0f));
}


void EPlayerPawn::MoveRight(float value)
{
	if (value != 0)
	{
		printf("Pawn is moving %s\n", (value > 0) ? "right" : "left");

		m_Velocity = (5.0f * value);
	}
	else
	{
		m_Velocity = 0.0f;
	}
}

void EPlayerPawn::SetupInputComponent(class InputComponent* playerInput)
{
	EPawn::SetupInputComponent(playerInput);

	playerInput->BindAxis("MoveRight", this, &EPlayerPawn::MoveRight);
}

void EPlayerPawn::OnUpdate(float deltaTime)
{
 	float pos = SpriteComponent->GetLocation().x;
// 	m_Velocity = (m_Acceleration * deltaTime);

	if (abs(m_Velocity) > m_MaxSpeed)
		m_Velocity = (m_Velocity > 0) ? m_MaxSpeed : m_MaxSpeed * -1;

	SpriteComponent->SetLocation(Maths::Vec2(pos + m_Velocity, SpriteComponent->GetLocation().y));

	std::cout << "Velocity: " << m_Velocity << " Acceleration: " << m_Acceleration << std::endl;




	
}
