#include <SSD1306/Display.hpp>

namespace SSD1306{

	Display::Display(){
	}

	Display::~Display(){
	}

	bool Display::Initialize(){
		if(
			m_Settings.DisplayOff() &&
			m_Settings.SetClockDIV(0x80) &&
			m_Settings.SetMultiplex(0x3f) &&
			m_Settings.SetOffset(0) &&
			m_Settings.SetStartLine(0) &&
			m_Settings.SetChargePump(Settings::ChargePumpStatus::ENABLE) &&
			m_Settings.MemoryAddressingMode(Settings::MemoryAddressingModeType::HORIZONTAL) &&
			m_Settings.SetSegmentRemap(true) &&
			m_Settings.SetCOMOutScanDirection(true) &&
			m_Settings.SetCOMPins(Settings::COMPinConfiguration::ALTERNATIVE, 
								Settings::COMPinConfigurationRemap::DISABLE_LR_REMAP) &&
			m_Settings.SetContrast(0xcf) &&
			m_Settings.SetPreChargePeriod(0xF1) &&
			m_Settings.SetVCOMDeselectLvl(Settings::VCOMDeselectLvl::LEVEL_3) &&
			m_Settings.SetResumeDisplay(Settings::ResumeDisplayContent::RAM_CONTENT) &&
			m_Settings.SetInverseDisplay(false) &&
			m_Settings.DisplayOn()
		){
			return true;
		}
		return false;
	}

	bool Display::On(){
		return m_Settings.DisplayOn();
	}

	bool Display::Update(){
		
		return true;
	}

}//namespace SSD1306