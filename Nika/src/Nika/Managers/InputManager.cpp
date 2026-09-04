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
		for (int key = 0; key < MAX_KEYCODE; key++)
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
		static Vector2 mousePos = GetMousePosition();

		if (mousePos.x != m_LastMousePos.x || mousePos.y != m_LastMousePos.y)
		{
			MouseMovedEvent e(mousePos.x, mousePos.y);
			m_EventCallback(e);

			m_LastMousePos = mousePos;
		}

		// left mousebutton check
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			MouseButtonPressedEvent e(MOUSE_BUTTON_LEFT);
			m_EventCallback(e);
		}
		else if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
		{
			MouseButtonPressedEvent e(MOUSE_BUTTON_RIGHT);
			m_EventCallback(e);
		}

		// right mousebutton check
		if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
		{
			MouseButtonReleasedEvent e(MOUSE_BUTTON_LEFT);
			m_EventCallback(e);
		}
		else if (IsMouseButtonReleased(MOUSE_BUTTON_RIGHT))
		{
			MouseButtonReleasedEvent e(MOUSE_BUTTON_RIGHT);
			m_EventCallback(e);
		}

	}
}

