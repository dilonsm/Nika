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
		for (int key = 0; key < 512; key++) // covers all keycodes
		{
			if (IsKeyPressed(key))
			{
				KeyPressedEvent e(key, 0);

				if (m_EventCallback)
					m_EventCallback(e);
			}

			if (IsKeyReleased(key))
			{
				KeyReleasedEvent e(key);

				if (m_EventCallback)
					m_EventCallback(e);
			}
		}

		// --- mouse input ---
		Vector2 mousePos = GetMousePosition();

		if (mousePos.x != m_LastMousePos.x || mousePos.y != m_LastMousePos.y)
		{
			MouseMovedEvent e(mousePos.x, mousePos.y);
			if (m_EventCallback)
				m_EventCallback(e);

			m_LastMousePos = mousePos;
		}
	}

	bool InputManager::isKeyPressed(int key) const
	{
		return IsKeyPressed(key);
	}

	bool InputManager::isKeyReleased(int key) const
	{
		return IsKeyReleased(key);
	}
}

