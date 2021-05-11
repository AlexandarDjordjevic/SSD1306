#include <SSD1306/Display.hpp>

namespace SSD1306{

	Display::Display(){

	}

	Display::~Display(){

	}

	bool Display::Initialize(){
		settings.Off();
		settings.SetClockDIV(0x80);
		settings.SetMultiplex(0x3f);
		settings.SetOffset(0);

        return true;
	}

	bool Display::On(){
		return settings.On();
	}

}//namespace SSD1306