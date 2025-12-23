#include "nkpch.h"
#include "Window.h"

namespace Nika
{
	static bool s_WindowInitialized = false; // false by default to ensure only one window initialization

	Camera camera; // camera instance
	Renderer renderer; // renderer instance

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
		SetConfigFlags(FLAG_WINDOW_RESIZABLE); // config flag for resizable window

		m_Data.Title  = props.Title;
		m_Data.Width  = props.Width;
		m_Data.Height = props.Height;

		if (!s_WindowInitialized)
		{
			InitWindow((int)m_Data.Width, (int)m_Data.Height, m_Data.Title.c_str());
			DisableCursor(); // disabled by default
			setVSync(true);

			NIKA_INFO("Created Window [{0}]: [{1}], [{2}]", props.Title, props.Width, props.Height);

			s_WindowInitialized = true;
		}
		else
			NIKA_ERROR("Window initialization failed!");
	}

	void Window::winUpdate(float dt)
	{
		toggleCursor();

		// camera update
		camera.camUpdate();

		// renderer update
		renderer.renderUpdate(camera);

		// end of program
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

	void Window::shutdown()
	{
		if (WindowShouldClose())
		{
			CloseWindow();

			WindowCloseEvent event;
			m_Data.EventCallback(event);
		}
	}
}

