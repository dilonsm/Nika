#include "nkpch.h"
#include "Window.h"

#include "Log.h"

namespace Nika
{
	static bool s_GLFWInitialized = false;

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
		shutdown();
	}

	void Window::init(const WindowProps& props)
	{
		m_Data.Title  = props.Title;
		m_Data.Width  = props.Width;
		m_Data.Height = props.Height;

		if (!s_GLFWInitialized)
		{
			glfwInit();

			NIKA_INFO("Creating {0} Window: [{1}], [{2}]", props.Title, props.Width, props.Height);
			s_GLFWInitialized = true;
		}
		else
			NIKA_ERROR("Could not initialize Window");

		// creation of window
		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		setVSync(true);
	}

	void Window::shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

	void Window::onUpdate()
	{
		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}

	void Window::setVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;
	}

	bool Window::isVSync() const
	{
		return m_Data.VSync;
	}
}

