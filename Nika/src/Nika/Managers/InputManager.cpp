#include "nkpch.h"
#include "InputManager.h"

namespace Nika
{
	InputManager& InputManager::getInstance()
	{
		static InputManager instance;
		return instance;
	}

	void InputManager::inputUpdate()
	{
		handleInput();
	}

	void InputManager::handleInput()
	{
		// --- keyboard input ---
		constexpr int MAX_KEYCODE = 512;
		for (int key = 0; key < MAX_KEYCODE; key++) // covers all possible keycodes
		{
			if (IsKeyPressed(key))
			{
				KeyPressedEvent e(key, 0);
				m_EventCallback(e);
			}

			if (IsKeyReleased(key))
			{
				KeyReleasedEvent e(key);
				m_EventCallback(e);
			}
		}

		// --- mouse input ---
		Vector2 mousePos = GetMousePosition();

		if (mousePos.x != m_LastMousePos.x || mousePos.y != m_LastMousePos.y)
		{
			MouseMovedEvent e(mousePos.x, mousePos.y);
			m_EventCallback(e);

			m_LastMousePos = mousePos;
		}
	}
}

