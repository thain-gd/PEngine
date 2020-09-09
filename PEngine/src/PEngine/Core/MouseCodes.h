#pragma once

namespace PEngine
{
	using MouseCode = uint16_t;

	namespace Mouse
	{
		enum : MouseCode
		{
			// From glfw3.h
			Button0 = 0,
			Button1 = 1,
			Button2 = 2,
			Button3 = 3,
			Button4 = 4,
			Button5 = 5,
			Button6 = 6,
			Button7 = 7,

			ButtonLast = Button7,
			ButtonLeft = Button0,
			ButtonRight = Button1,
			ButtonMiddle = Button2
		};
	}
}

#define PE_MOUSE_BUTTON_0      ::PEngine::Mouse::Button0
#define PE_MOUSE_BUTTON_1      ::PEngine::Mouse::Button1
#define PE_MOUSE_BUTTON_2      ::PEngine::Mouse::Button2
#define PE_MOUSE_BUTTON_3      ::PEngine::Mouse::Button3
#define PE_MOUSE_BUTTON_4      ::PEngine::Mouse::Button4
#define PE_MOUSE_BUTTON_5      ::PEngine::Mouse::Button5
#define PE_MOUSE_BUTTON_6      ::PEngine::Mouse::Button6
#define PE_MOUSE_BUTTON_7      ::PEngine::Mouse::Button7
#define PE_MOUSE_BUTTON_LAST   ::PEngine::Mouse::ButtonLast
#define PE_MOUSE_BUTTON_LEFT   ::PEngine::Mouse::ButtonLeft
#define PE_MOUSE_BUTTON_RIGHT  ::PEngine::Mouse::ButtonRight
#define PE_MOUSE_BUTTON_MIDDLE ::PEngine::Mouse::ButtonMiddle