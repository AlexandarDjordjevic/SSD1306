#include <SSD1306/Settings.hpp>

namespace SSD1306
{
	Settings::Settings(){
		m_ComInterface = SSD1306::ComInterface::GetComInterface();
	}

	bool Settings::Write(uint8_t command){
		const uint8_t data[] = {
			static_cast<uint8_t>(Settings::COMMAND),
			command
		};
		return SSD1306::ComInterface::GetComInterface()->Write(data, 2);
	}

	bool Settings::Write(Settings::Command command){
		const uint8_t data[] = {
			static_cast<uint8_t>(Settings::COMMAND),
			static_cast<uint8_t>(command)
		};
		return SSD1306::ComInterface::GetComInterface()->Write(data, 2);
	}

	bool Settings::SetWidth(uint8_t width){
		if (width > MAX_WIDTH)
			return false;
		m_Width = width;
		return true;
	}

	bool Settings::SetHeight(uint8_t height){
		if (height > MAX_HEIGHT)
			return false;
		m_Height = height;
		return true;
	}

	bool Settings::DisplayOn(){
		return Write(Settings::Command::On);
	}

	bool Settings::DisplayOff(){
		return Write(Settings::Command::Off);
	}

	bool Settings::SetClockDIV(uint8_t value){
		return Write(Settings::Command::SetClockDiv) && 
				Write(value);
	}

	bool Settings::SetMultiplex(uint8_t multiplex){
		return Write(Settings::Command::SetMultiplex) && 
				Write(multiplex);
	}

	bool Settings::SetOffset(uint8_t offset){
		return Write(Settings::Command::SetDisplayOffset) && 
				Write(offset);
	}

	bool Settings::SetStartLine(uint8_t startLine){
		if (startLine > 63)
			return false;
		return Write(static_cast<uint8_t>(Settings::Command::SetStartLine) | startLine);
	}

	bool Settings::SetChargePump(Settings::ChargePumpStatus cps){
		return Write(Settings::Command::SetChargePump) && 
				Write(static_cast<uint8_t>(cps));
	}

	bool Settings::MemoryAddressingMode(Settings::MemoryAddressingModeType memAddrMode){
		return Write(Settings::Command::SetMemoryAddressingMode) && 
				Write(static_cast<uint8_t>(memAddrMode));
	}

	bool Settings::SetPageStartAddress(uint8_t page){
		if (page > 7)
			return false;
		return Write(static_cast<uint8_t>(Settings::Command::SetPageStartAddress) | page);
	}

	bool Settings::SetColumnStartAddress(uint8_t address){
		return Write(((address >> 4) & 0x0F) | 0x10) && 
				Write(address & 0x0F);
	}

	bool Settings::SetColumnAddress(uint8_t start, uint8_t end){
		if (start > m_Width || end > m_Width)
			return false;
		return Write(Settings::Command::SetColumnAddress) &&
				Write(start),
				Write(end);
	}

	bool Settings::SetPageAddress(uint8_t start, uint8_t end){
		if (start > m_Width || end > m_Width)
			return false;
		return Write(Settings::Command::SetPageAddress) &&
				Write(start),
				Write(end);
	}

	bool Settings::SetContrast(uint8_t contrast){
		return Write(Settings::Command::SetContrast) && 
				Write(static_cast<uint8_t>(contrast));
	}

	bool Settings::SetSegmentRemap(bool remap){
		if (remap)
			return Write(static_cast<uint8_t>(Settings::Command::SetSegmentRemap) | 0x01);
		else
			return Write(Settings::Command::SetSegmentRemap);
	}

	bool Settings::SetCOMOutScanDirection(bool direction){
		if (direction)
			return Write(static_cast<uint8_t>(Settings::Command::SetCOMOutScanDirection) | 0x08);
		else
			return Write(static_cast<uint8_t>(Settings::Command::SetCOMOutScanDirection));
	}

	bool Settings::SetCOMPins(COMPinConfiguration pinConf, COMPinConfigurationRemap pinConfRemap){
		return Write(Settings::Command::SetCOMPins) &&
				Write(static_cast<uint8_t>(pinConf) | static_cast<uint8_t>(pinConfRemap));
	}

	bool Settings::SetPreChargePeriod(uint8_t period){
		if (((period & 0x0f) == 0) || ((period & 0xf0) == 0))
			return false;
		return Write(Settings::Command::SetPreChargePeriod) && 
			Write(static_cast<uint8_t>(period));
	}

	bool Settings::SetVCOMDeselectLvl(VCOMDeselectLvl level){
		return Write(Settings::Command::SetVCOMDeselectLvl) && 
			Write(static_cast<uint8_t>(level));
	}

	bool Settings::SetResumeDisplay(ResumeDisplayContent content){
		return Write(static_cast<uint8_t>(Settings::Command::SetResumeDisplay) | 
		static_cast<uint8_t>(content));
	}

	bool Settings::SetInverseDisplay(bool inverse){
		if (inverse == true)
			return Write(static_cast<uint8_t>(Settings::Command::SetInverseDisplay)| 0x01);
		else
			return Write(Settings::Command::SetNormalDisplay);
	}

} // namespace SSD1306
