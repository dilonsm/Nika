#include "nkpch.h"
#include "Window.h"

namespace Nika
{
	std::unique_ptr<WindowBase> WindowBase::createWin(const WindowProps& props)
	{
		return std::make_unique<Window>(props);
	}

	Window::Window(const WindowProps& props)
	{
		init(props);
	}

	Window::~Window()
	{
	}

	void Window::init(const WindowProps& props)
	{
		m_Data.Title  = props.Title;
		m_Data.Width  = props.Width;
		m_Data.Height = props.Height;

		if (!IsWindowReady())
		{
			InitWindow((int)m_Data.Width, (int)m_Data.Height, m_Data.Title.c_str());
			DisableCursor(); // disabled by default
			setVSync(true);

			NIKA_INFO("Created Window [{0}]: [{1}], [{2}]", props.Title, props.Width, props.Height);
		}
		else
			NIKA_ERROR("Window initialization failed!");
	}

	void Window::winUpdate()
	{
		// window related update
		toggleScreen();
		toggleCursor();
		shutdown();
	}

	void Window::setVSync(bool enabled)
	{
		m_Data.VSync = enabled;

		if (enabled)
			SetTargetFPS(144);
		else
			SetTargetFPS(0);
	}

	bool Window::isVSync() const
	{
		return m_Data.VSync;
	}

	void Window::toggleCursor()
	{
		static bool cursorOff = true;
		if (IsKeyPressed(KEY_F1))
		{
			switch (cursorOff)
			{
			case false:
				DisableCursor();
				cursorOff = true;
				break;
			case true:
				EnableCursor();
				cursorOff = false;
				break;
			}
		}
	}

	void Window::toggleScreen()
	{
		if (IsKeyPressed(KEY_F11))
		{
			if (!IsWindowFullscreen())
			{
				int monitor = GetCurrentMonitor();
				m_Data.Width  = GetScreenWidth();
				m_Data.Height = GetScreenHeight();

				SetWindowSize(GetMonitorWidth(monitor), GetMonitorHeight(monitor));
				ToggleFullscreen();
			}
			else
			{
				ToggleFullscreen();
				SetWindowSize(m_Data.Width, m_Data.Height);
			}
		}
	}

	void Window::shutdown()
	{
		if (WindowShouldClose())
		{
			WindowCloseEvent event;
			m_Data.EventCallback(event);
		}
	}
}

