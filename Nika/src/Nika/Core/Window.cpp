#include "nkpch.h"
#include "Window.h"

#include <raylib.h>

namespace Nika
{
	static bool s_WindowInitialized = false;

	WindowBase* WindowBase::createWin(const WindowProps& props)
	{
		return new Window(props);
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

		if (!s_WindowInitialized)
		{
			InitWindow((int)m_Data.Width, (int)m_Data.Height, m_Data.Title.c_str());
			SetTargetFPS(60);

			NIKA_INFO("Created Window [{0}]: [{1}], [{2}]", props.Title, props.Width, props.Height);

			s_WindowInitialized = true;
			setVSync(true);
		}
		else
			NIKA_ERROR("Window initialization failed!");
	}

	void Window::onUpdate()
	{
		BeginDrawing();

		ClearBackground(RED);

		EndDrawing();

		m_Data.Width  = GetScreenWidth();
		m_Data.Height = GetScreenHeight();

		shutdown();
	}

	void Window::setVSync(bool enabled)
	{
		m_Data.VSync = enabled;

		if (enabled)
			SetTargetFPS(60);
		else
			SetTargetFPS(0);
	}

	bool Window::isVSync() const
	{
		return m_Data.VSync;
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

