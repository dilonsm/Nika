#pragma once

#include "Nika/Events/Event.h"

namespace Nika
{
	struct WindowProps
	{
		std::string Title;
		uint32_t Width;
		uint32_t Height;

		WindowProps(const std::string& title = "Nika Engine",
			uint32_t width = 1280,
			uint32_t height = 720)
			: Title(title), Width(width), Height(height)
		{
		}
	};

	class WindowBase
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~WindowBase() = default;

		virtual void winUpdate() = 0;

		virtual uint32_t getWidth() const = 0;
		virtual uint32_t getHeight() const = 0;

		// window attributes
		virtual void setEventCallback(const EventCallbackFn& callback) = 0;
		virtual void setVSync(bool enabled) = 0;
		virtual bool isVSync() const = 0;

		static std::unique_ptr<WindowBase>(createWin(const WindowProps& props = WindowProps()));
	};
}

