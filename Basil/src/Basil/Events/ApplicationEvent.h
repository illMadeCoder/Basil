#pragma once

#include "Event.h"

namespace Basil {
	class BASIL_API WindowResizeEvent : public Event
	{
	public:
		WindowsResizeEvent(unsigned int width, unsigned int height) :
			m_Width(width), m_Height(height) {}

		inline unsigned int GetWidth() const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(windowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}
