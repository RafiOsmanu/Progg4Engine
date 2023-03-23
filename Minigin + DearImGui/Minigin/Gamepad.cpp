#include "Gamepad.h"

void dae::Gamepad::Update()
{
	CopyMemory(&m_PreviousState, &m_CurrentState, sizeof(XINPUT_STATE));
	ZeroMemory(&m_PreviousState, sizeof(XINPUT_STATE));
	XInputGetState(m_ControllerIndex, &m_CurrentState);

	auto buttonChanges = m_CurrentState.Gamepad.wButtons ^ m_PreviousState.Gamepad.wButtons;
	m_ButtonPressedThisFrame = buttonChanges & m_CurrentState.Gamepad.wButtons;
	m_ButtonReleasedThisFrame = buttonChanges & (~m_CurrentState.Gamepad.wButtons);
}

bool dae::Gamepad::IsDownThisFrame(unsigned int button) const
{
	return m_ButtonPressedThisFrame & button;
}

bool dae::Gamepad::IsUpThisFrame(unsigned int button) const
{
	return m_ButtonReleasedThisFrame & button;
}

bool dae::Gamepad::IsPressed(unsigned int button) const
{
	return m_CurrentState.Gamepad.wButtons & button;
}
