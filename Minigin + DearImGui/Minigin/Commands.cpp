#include "Commands.h"
#include "DeltaTime.h"
#include "HealthComponent.h"
#include "ScoreComponent.h"

dae::MoveCommand::MoveCommand(const std::shared_ptr<GameObject> actor, float speed, PlayerInput input)
	:m_Actor{actor}
	,m_Speed{speed}
	,m_OgPos{actor->GetLocalPosition()}
	,m_Input{input}
{
	switch (m_Input)
	{
	case Left:
		m_Direction = { -1,-1,0 };
		break;
	case Right:
		m_Direction = { 1,1,0 };
		break;
	case Up:
		m_Direction = { 1,-1,0 };
		break;
	case Down:
		m_Direction = { -1,1,0 };
		break;
	}

	
}

void dae::MoveCommand::Execute()
{
	if (m_IsMoving) return;

	m_OgPos = m_Actor->GetLocalPosition();
	m_IsMoving = true;
	
}

void dae::MoveCommand::Update()
{
	if (m_IsMoving)
	{
		if (glm::distance(m_Actor->GetLocalPosition(), m_OgPos) < 15.f)
		{
			auto translation = glm::vec3(m_Actor->GetLocalPosition(), 0) + (m_Direction * m_Speed * DeltaTime::GetInstance().getDeltaTime());
			m_Actor->SetLocalPosition({ translation.x, translation.y });
		}
		else
		{
			m_IsMoving = false;
		}
	}
}

dae::DamageCommand::DamageCommand(const std::shared_ptr<GameObject> actor)
	:m_Actor{actor}
{
}

void dae::DamageCommand::Execute()
{
	m_Actor->GetComponent<dae::HealthComponent>()->LoseLife();
}

dae::AddScoreCommand::AddScoreCommand(const std::shared_ptr<GameObject> actor)
	:m_Actor {actor}
{

}

void dae::AddScoreCommand::Execute()
{
	m_Actor->GetComponent<dae::ScoreComponent>()->AddScore(10);
}
