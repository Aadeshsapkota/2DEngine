#include "StateMachine.h"

void StateMachine::ChangeState(State* newState)
{
    if (m_Current)
        m_Current->OnExit();

    m_Current = newState;

    if (m_Current)
        m_Current->OnEnter();
}

void StateMachine::Update(float dt)
{
    if (m_Current)
        m_Current->Update(dt);
}
