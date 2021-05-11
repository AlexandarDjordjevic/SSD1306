#include <SSD1306/Settings.hpp>

namespace SSD1306
{

	bool Settings::WriteCommand(uint8_t command){
		const uint8_t data[] = {
			static_cast<uint8_t>(Settings::COMMAND),
			command
		};
		return SSD1306::ComInterface::GetComInterface().Write(data, 2);
	}

	bool Settings::WriteCommand(Settings::Command command){
		const uint8_t data[] = {
			static_cast<uint8_t>(Settings::COMMAND),
			static_cast<uint8_t>(command)
		};
		return SSD1306::ComInterface::GetComInterface().Write(data, 2);
	}

	bool Settings::On(){
		return WriteCommand(Settings::Command::On);
	}

	bool Settings::Off(){
		return WriteCommand(Settings::Command::Off);
	}

	bool Settings::SetClockDIV(uint8_t value){
		return WriteCommand(Settings::Command::SetClockDiv) && WriteCommand(value);
	}

	bool Settings::SetMultiplex(uint8_t value){
		return WriteCommand(Settings::Command::SetMultiplex) && WriteCommand(value);
	}

	bool Settings::SetOffset(uint8_t value){
		return WriteCommand(Settings::Command::SetDisplayOffset) && WriteCommand(value);
	}

	bool Settings::SetStartLine(uint8_t value){
		return WriteCommand(Settings::Command::SetStartLine);
	}

	bool Settings::ChargePump(Settings::ChargePumpStatus cps){
		return WriteCommand(Settings::Command::ChargePump) && WriteCommand(static_cast<uint8_t>(cps));
	}

	bool Settings::MemoryAddressingMode(Settings::MemoryAddressingModeType mamt){
		return WriteCommand(Settings::Command::MemoryAddressingMode) && WriteCommand(static_cast<uint8_t>(mamt));
	}

	bool Settings::SetContrast(uint8_t contrast){
		return WriteCommand(Settings::Command::SetContrast) && WriteCommand(static_cast<uint8_t>(contrast));
	}

} // namespace SSD1306
