#pragma once
#include <Windows.h>
#include <Xinput.h>
#include "BaseComponent.h"

namespace dae
{
	class Gamepad : public BaseComponent
	{
	public:
		void Update();
		bool IsDownThisFrame(unsigned int button) const;
		bool IsUpThisFrame(unsigned int button) const;
		bool IsPressed(unsigned int button) const;

	private:
		XINPUT_STATE m_PreviousState{};
		XINPUT_STATE m_CurrentState{};
		size_t m_ControllerIndex;
		WORD m_ButtonPressedThisFrame{};
		WORD m_ButtonReleasedThisFrame{};
	};
}

