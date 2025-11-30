#pragma once

#include "WindowBase.h"

namespace Nika
{
	class Window : public WindowBase
	{
	public:
		Window(const WindowProps& props);
		virtual ~Window();

		void onUpdate() override;

		uint32_t getWidth() const override { return m_Data.Width; }
		uint32_t getHeight() const override { return m_Data.Height; }

		// window attributes
		void setEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void setVSync(bool enabled) override;
		bool isVSync() const override;

	private:
		virtual void init(const WindowProps& props);
		virtual void shutdown();

		// GLFW attributes
		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			uint32_t Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};
}

