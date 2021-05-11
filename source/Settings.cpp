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

	bool Settings::DisplayOn(){
		return WriteCommand(Settings::Command::On);
	}

	bool Settings::DisplayOff(){
		return WriteCommand(Settings::Command::Off);
	}

	bool Settings::SetClockDIV(uint8_t value){
		return WriteCommand(Settings::Command::SetClockDiv) && 
				WriteCommand(value);
	}

	bool Settings::SetMultiplex(uint8_t multiplex){
		return WriteCommand(Settings::Command::SetMultiplex) && 
				WriteCommand(multiplex);
	}

	bool Settings::SetOffset(uint8_t offset){
		return WriteCommand(Settings::Command::SetDisplayOffset) && 
				WriteCommand(offset);
	}

	bool Settings::SetStartLine(uint8_t startLine){
		if (startLine > 63)
			return false;
		return WriteCommand(static_cast<uint8_t>(Settings::Command::SetStartLine) | startLine);
	}

	bool Settings::SetChargePump(Settings::ChargePumpStatus cps){
		return WriteCommand(Settings::Command::SetChargePump) && 
				WriteCommand(static_cast<uint8_t>(cps));
	}

	bool Settings::MemoryAddressingMode(Settings::MemoryAddressingModeType memAddrMode){
		return WriteCommand(Settings::Command::SetMemoryAddressingMode) && 
				WriteCommand(static_cast<uint8_t>(memAddrMode));
	}

	bool Settings::SetPageStartAddress(uint8_t page){
		if (page > 7)
			return false;
		return WriteCommand(0xB0 | page);
	}

	bool Settings::SetColumnStartAddress(uint8_t address){
		return WriteCommand(((address >> 4) & 0x0F) | 0x10) && 
				WriteCommand(address & 0x0F);
	}

	bool Settings::SetContrast(uint8_t contrast){
		return WriteCommand(Settings::Command::SetContrast) && 
				WriteCommand(static_cast<uint8_t>(contrast));
	}

	bool Settings::SetSegmentRemap(bool remap){
		if (remap)
			return WriteCommand(static_cast<uint8_t>(Settings::Command::SetSegmentRemap) | 0x01);
		else
			return WriteCommand(Settings::Command::SetSegmentRemap);
	}

	bool Settings::SetCOMOutScanDirection(bool direction){
		if (direction)
			return WriteCommand(static_cast<uint8_t>(Settings::Command::SetCOMOutScanDirection) | 0x08);
		else
			return WriteCommand(static_cast<uint8_t>(Settings::Command::SetCOMOutScanDirection));
	}

	bool Settings::SetCOMPins(COMPinConfiguration pinConf, COMPinConfigurationRemap pinConfRemap){
		return WriteCommand(Settings::Command::SetCOMPins) &&
				WriteCommand(static_cast<uint8_t>(pinConf) | static_cast<uint8_t>(pinConfRemap));
	}

	bool Settings::SetPreChargePeriod(uint8_t period){
		if (((period & 0x0f) == 0) || ((period & 0xf0) == 0))
			return false;
		return WriteCommand(Settings::Command::SetPreChargePeriod) && 
			WriteCommand(static_cast<uint8_t>(period));
	}

	bool Settings::SetVCOMDeselectLvl(VCOMDeselectLvl level){
		return WriteCommand(Settings::Command::SetVCOMDeselectLvl) && 
			WriteCommand(static_cast<uint8_t>(level));
	}

	bool Settings::SetResumeDisplay(ResumeDisplayContent content){
		return WriteCommand(static_cast<uint8_t>(Settings::Command::SetResumeDisplay) | 
		static_cast<uint8_t>(content));
	}

	bool Settings::SetInverseDisplay(bool inverse){
		if (inverse == true)
			return WriteCommand(static_cast<uint8_t>(Settings::Command::SetInverseDisplay)| 0x01);
		else
			return WriteCommand(Settings::Command::SetNormalDisplay);
	}

} // namespace SSD1306
