#include <SSD1306/Display.hpp>

namespace SSD1306
{

	bool Display::WriteCommand(uint8_t command){
		const uint8_t data[] = {
			static_cast<uint8_t>(Display::COMMAND),
			command
		};
		return SSD1306::ComInterface::GetComInterface().Write(data, 2);
	}

	bool Display::WriteCommand(Display::Command command){
		const uint8_t data[] = {
			static_cast<uint8_t>(Display::COMMAND),
			static_cast<uint8_t>(command)
		};
		return SSD1306::ComInterface::GetComInterface().Write(data, 2);
	}


	bool Display::TurnOff(){
		return WriteCommand(Display::Command::Off);
	}

	bool Display::SetClockDIV(uint8_t value){
		return WriteCommand(Display::Command::SetClockDiv) && WriteCommand(value);
	}

	
} // namespace SSD1306
