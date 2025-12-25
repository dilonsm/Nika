#pragma once

#include "Nika/Events/MouseEvent.h"
#include "Nika/Events/KeyEvent.h"

#include <raylib.h>

namespace Nika
{
	class InputManager
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		static InputManager& getInstance();

		void inputUpdate();

		void setEventCallback(const EventCallbackFn& callback) { m_EventCallback = callback; }

	private:
		InputManager() = default;
		~InputManager() = default;

		void handleInput();

		Vector2 m_LastMousePos = { 0,0 };

		EventCallbackFn m_EventCallback;
	};
}

