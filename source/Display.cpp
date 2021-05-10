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

	bool Display::On(){
		return WriteCommand(Display::Command::On);
	}

	bool Display::Off(){
		return WriteCommand(Display::Command::Off);
	}

	bool Display::SetClockDIV(uint8_t value){
		return WriteCommand(Display::Command::SetClockDiv) && WriteCommand(value);
	}

	bool Display::SetMultiplex(uint8_t value){
		return WriteCommand(Display::Command::SetMultiplex) && WriteCommand(value);
	}

	bool Display::SetOffset(uint8_t value){
		return WriteCommand(Display::Command::SetDisplayOffset) && WriteCommand(value);
	}

	bool Display::SetStartLine(uint8_t value){
		return WriteCommand(Display::Command::SetStartLine);
	}
	
	bool Display::ChargePump(Display::ChargePumpStatus cps){
		return WriteCommand(Display::Command::ChargePump) && WriteCommand(static_cast<uint8_t>(cps));
	}

	bool Display::MemoryAddressingMode(Display::MemoryAddressingModeType mamt){
		return WriteCommand(Display::Command::MemoryAddressingMode) && WriteCommand(static_cast<uint8_t>(mamt));
	}

} // namespace SSD1306
