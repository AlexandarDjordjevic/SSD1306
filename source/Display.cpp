#include <SSD1306/Display.hpp>

namespace SSD1306{

	Display::Display(){
	}

	Display::~Display(){
	}

	bool Display::Initialize(){
		if(
			settings.DisplayOff() &&
			settings.SetClockDIV(0x80) &&
			settings.SetMultiplex(0x3f) &&
			settings.SetOffset(0) &&
			settings.SetStartLine(0) &&
			settings.SetChargePump(Settings::ChargePumpStatus::ENABLE) &&
			settings.MemoryAddressingMode(Settings::MemoryAddressingModeType::HORIZONTAL) &&
			settings.SetSegmentRemap(true) &&
			settings.SetCOMOutScanDirection(true) &&
			settings.SetCOMPins(Settings::COMPinConfiguration::ALTERNATIVE, 
								Settings::COMPinConfigurationRemap::DISABLE_LR_REMAP) &&
			settings.SetContrast(0xcf) &&
			settings.SetPreChargePeriod(0xF1) &&
			settings.SetVCOMDeselectLvl(Settings::VCOMDeselectLvl::LEVEL_3) &&
			settings.SetResumeDisplay(Settings::ResumeDisplayContent::RAM_CONTENT) &&
			settings.SetInverseDisplay(false) &&
			settings.DisplayOn()
		){
			return true;
		}
		return false;
	}

	bool Display::On(){
		return settings.DisplayOn();
	}

}//namespace SSD1306