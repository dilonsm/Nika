#include "nkpch.h"
#include "Window.h"

namespace Nika
{
	static bool s_GLFWInitialized = false;

	static void GLFWErrorCallback(int error, const char* description)
	{
		NIKA_ERROR("GLFW Error [{0}]: {1}", error, description);
	}

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
			glfwSetErrorCallback(GLFWErrorCallback);

		// GLFW window creation
		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);

		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		setVSync(true);

		// GLFW window size callback
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* win, int width, int height)
			{
				// casts void* to WinData* and then dereferences the pointer
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(win);
				data.Width = width;
				data.Height = height;

				WindowResizeEvent event(width, height);
				data.EventCallback(event);
			});

		// GLFW window close callback
		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* win)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(win);

				WindowCloseEvent event;
				data.EventCallback(event);
			});

		// GLFW key callback
		glfwSetKeyCallback(m_Window, [](GLFWwindow* win, int key, int keycode, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(win);

				switch (action)
				{
				case GLFW_PRESS:
				{
					KeyPressedEvent event(key, 0);
					data.EventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, 1);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					data.EventCallback(event);
					break;
				}
				}
			});

		// GLFW mouse callback
		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* win, int button, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(win);

				switch (action)
				{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button);
					data.EventCallback(event);
					break;
				}
				}
			});

		// GLFW scroll callback
		glfwSetScrollCallback(m_Window, [](GLFWwindow* win, double xOffset, double yOffset)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(win);

				MouseScrolledEvent event((float)xOffset, (float)yOffset);
				data.EventCallback(event);
			});

		// GLFW cursor position callback
		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* win, double xPos, double yPos)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(win);

				MouseMovedEvent event((float)xPos, (float)yPos);
				data.EventCallback(event);
			});
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

