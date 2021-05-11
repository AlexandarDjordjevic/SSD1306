#include <SSD1306/Display.hpp>

namespace SSD1306{

	Display::Display(){
	}

	Display::~Display(){
	}


    // ssd1306_command(SSD1306_COMSCANDEC); // rotate screen 180
    // ssd1306_command(SSD1306_SETCOMPINS);                    // 0xDA
    // ssd1306_command(0x12);
    // ssd1306_command(SSD1306_SETCONTRAST);                   // 0x81
    // ssd1306_command(0xCF);
    // ssd1306_command(SSD1306_SETPRECHARGE);                  // 0xd9
    // ssd1306_command(0xF1);
    // ssd1306_command(SSD1306_SETVCOMDETECT);                 // 0xDB
    // ssd1306_command(0x40);
    // ssd1306_command(SSD1306_DISPLAYALLON_RESUME);           // 0xA4
    // ssd1306_command(SSD1306_NORMALDISPLAY);                 // 0xA6
    // ssd1306_command(SSD1306_DISPLAYON);                     //switch on OLED

	bool Display::Initialize(){
		settings.Off();
		settings.SetClockDIV(0x80);
		settings.SetMultiplex(0x3f);
		settings.SetOffset(0);
		settings.SetStartLine(0);
		settings.SetChargePump(Settings::ChargePumpStatus::ENABLE);
		settings.MemoryAddressingMode(Settings::MemoryAddressingModeType::HORIZONTAL);
		settings.SetSegmentRemap(true);
		settings.SetCOMOutScanDirection(true);
		settings.SetCOMPins(Settings::COMPinConfiguration::ALTERNATIVE, 
							Settings::COMPinConfigurationRemap::DISABLE_LR_REMAP);
		settings.SetContrast(0xcf);
		
		return true;
	}

	bool Display::On(){
		return settings.On();
	}

}//namespace SSD1306