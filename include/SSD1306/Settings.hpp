/**
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#pragma once
#include <SSD1306/ComInterface.hpp>

namespace SSD1306
{
	class Settings{

	#define MAX_WIDTH 128
	#define MAX_HEIGHT 64

	private:
		enum {
			COMMAND	= 0,
			DATA	= 0x40
		};

		enum class Command{
			On						= 0xA5,
			Off 					= 0xAe,
			SetCOMPins				= 0xDA,
			SetClockDiv 			= 0xd5,
			SetContrast				= 0x81,
			SetMultiplex 			= 0xA8,
			SetStartLine			= 0x40,
			SetChargePump			= 0x8D,
			SetPageAddress			= 0x22,
			SetSegmentRemap			= 0xA0,
			SetDisplayOffset 		= 0xD3,
			SetResumeDisplay		= 0xA4,
			SetNormalDisplay		= 0xA6,
			SetColumnAddress		= 0x21,
			SetInverseDisplay		= 0xA7,
			SetPreChargePeriod		= 0xD9,
			SetVCOMDeselectLvl		= 0xDB,
			SetPageStartAddress		= 0xB0,
			SetCOMOutScanDirection	= 0xc0,
			SetMemoryAddressingMode	= 0x20,
		};

	public:
		enum class ChargePumpStatus{
			ENABLE	= 0x14,
			DISABLE	= 0x10
		};

		enum class MemoryAddressingModeType{
			HORIZONTAL	= 0x00,
			VERTICAL	= 0x01,
			PAGE		= 0x10
		};

		enum class COMPinConfiguration{
			SEQUENTIAL 	= 0x02,
			ALTERNATIVE = 0x22
		};

		enum class COMPinConfigurationRemap{
			DISABLE_LR_REMAP	= 0x02,
			ENABLE_LR_REMAP		= 0x12
		};

		enum class VCOMDeselectLvl{
			LEVEL_1	= 0x0, ///< ~ 0.65 x VCC
			LEVEL_2 = 0x20, ///< ~ 0.77 x VCC (RESET)
			LEVEL_3	= 0x30 ///< ~ 0.83 x VCC
		};

		enum class ResumeDisplayContent{
			RAM_CONTENT,
			ALL_ON
		};

	public:
		/**
		 * @brief Default constructor
		 * 
		 */
		Settings();

		/**
		 * @brief Default destructor
		 * 
		 */
		~Settings() = default;

		Settings(const Settings&) = delete;
		Settings& operator=(const Settings&) = delete;
		Settings(Settings&&) = delete;
		Settings& operator=(Settings &&) = delete;

		/**
		 * @brief Enable display outputs according to the GDDRAM contents.
		 * 
		 * @return true - success, false - error
		 */
		bool DisplayOn();

		/**
		 * @brief Disable display output
		 * 
		 * @return true - success, false - error
		 */
		bool DisplayOff();

		/**
		 * @brief Set the display width
		 * 
		 * @return true - success, false - error
		 */
		bool SetWidth(uint8_t width);

		/**
		 * @brief Set the display height
		 * 
		 * @return true - success, false - error
		 */
		bool SetHeight(uint8_t height);

		/**
		 * @brief Set the clock divide ratio and oscillator frequency.
		 * Settings Clock Divide Ratio Value[3:0]
		 * Set the divide ratio to generate DCLK (Settings Clock) from CLK.
		 * The divide ratio is from 1 to 16, with reset value = 1.
		 * Oscillator Frequency Value[7:4]
		 * Program the oscillator frequency Fosc that is the source of CLK if CLS pin is pulled high. 
		 * The 4-bit value results in 16 different frequency settings available. 
		 * The default setting is 1000b. 
		 * 
		 * @param value clock divider and oscillator frequency values
		 * 
		 * @return true - success, false - error
		 */
		bool SetClockDIV(uint8_t value);

		/**
		 * @brief Switches the default 63 multiplex mode to any multiplex ratio, ranging from 16 to 63
		 * 
		 * @param multiplex value between 16 - 63
		 * 
		 * @return true - success, false - error
		 */
		bool SetMultiplex(uint8_t multiplex);
		
		/**
		 * @brief Set the mapping of the display start line to one of COM0~COM63
		 * 
		 * @param offset value between 0 - 63
		 * 
		 * @return true - success, false - error
		 */
		bool SetOffset(uint8_t offset);

		/**
		 * @brief This command sets the Display Start Line register to determine 
		 * starting address of display RAM, by selecting a value from 0 to 63.
		 * 
		 * @param startLine value between 0 - 63
		 * 
		 * @return true - success, false - error
		 */
		bool SetStartLine(uint8_t startLine);

		/**
		 * @brief Disable or enable charge pump
		 * 
		 * @param cps - new charge pump status (ENABLE/DISABLE)
		 * 
		 * @return true - success, false - error
		 */
		bool SetChargePump(ChargePumpStatus cps);

		/**
		 * @brief Select addresing mode. There are 3 different memory addressing mode.
		 * 
		 * @param memAddrMode value - horizontal, vertical or page addresing mode
		 * 
		 * @return true - success, false - error
		 */
		bool MemoryAddressingMode(MemoryAddressingModeType memAddrMode);

		/**
		 * @brief Set the column start address and end address of the display data RAM. 
		 * This command also sets the column address pointer to column start address. 
		 * This pointer is used to define the current read/write column address in graphic 
		 * display data RAM
		 * 
		 * @param start start column address value (0 - 127)
		 * @param end end column address (0 - 127)
		 * 
		 * @return true - success, false - error
		 */
		bool SetColumnAddress(uint8_t start, uint8_t end);

		/**
		 * @brief Set the page start address and end address of the display data RAM. 
		 * This command also sets the page address pointer to page start address. 
		 * This pointer is used to define the current read/write page address in graphic 
		 * display data RAM
		 * 
		 * @param start start page address value (0 - 127)
		 * @param end end page address (0 - 127)
		 * 
		 * @return true - success, false - error
		 */
		bool SetPageAddress(uint8_t start, uint8_t end);

		/**
		 * @brief This command positions the page start address from 0 to 7 in GDDRAM 
		 * under Page Addressing Mode
		 * 
		 * @param page value between 0 - 7
		 * 
		 * @return true - success, false - error
		 */
		bool SetPageStartAddress(uint8_t page);

		/**
		 * @brief This command specifies the 8-bit column start address for the display data RAM 
		 * under Page Addressing Mode. 
		 * The column address will be incremented by each data access.
		 * 
		 * @param address value between 0 - 127
		 * 
		 * @return true - success, false - error
		 */
		bool SetColumnStartAddress(uint8_t address);

		/**
		 * @brief This command sets the Contrast Setting of the display. 
		 * The chip has 256 contrast steps from 00h to FFh. 
		 * The segment output current increases as the contrast step value increases.
		 * 
		 * @param contrast contrast value (0x00 - oxff)
		 * 
		 * @return true - success, false - error
		 */
		bool SetContrast(uint8_t contrast);

		/**
		 * @brief This command changes the mapping between the display data column address 
		 * and the segment driver. It allows flexibility in OLED module design.
		 * 
		 * @param remap - true to enable remap, false to disable remap
		 * 
		 * @return true - success, false - error
		 */
		bool SetSegmentRemap(bool remap);

		/**
		 * @brief This command sets the scan direction of the COM output, 
		 * allowing layout flexibility in the OLED module design
		 * 
		 * @param direction true - direction is 63 -> 0; false - direction is 0 -> 63
		 * 
		 * @return true - success, false - error
		 */
		bool SetCOMOutScanDirection(bool direction);

		/**
		 * @brief This command sets the COM signals pin configuration to match the 
		 * OLED panel hardware layout
		 * 
		 * @param pinConf - COM output scan direction
		 * @param pinConfRemap - enable/disable left/right remap
		 * 
		 * @return true - success, false - error
		 */
		bool SetCOMPins(COMPinConfiguration pinConf, COMPinConfigurationRemap pinConfRemap);

		/**
		 * @brief This command is used to set the duration of the pre-charge period. 
		 * The interval is counted in number of DCLK
		 * 
		 * @param period Bits [3:0] - Phase 1 period of up to 15 DCLK clocks 0 is invalid entry (RESET=2h)
		 * Bits [7:4] : Phase 2 period of up to 15 DCLK clocks 0 is invalid entry (RESET=2h)
		 * 
		 * @return true - success, false - error
		 */
		bool SetPreChargePeriod(uint8_t period);

		/**
		 * @brief This command adjusts the VCOMH regulator output.
		 * 
		 * @param level deselect level: LEVEL_1 ~ 0.65 x VCC, LEVEL_2 ~ 0.77 x VCC (RESET)
		 * or LEVEL_3 ~ 0.83 x VCC
		 * 
		 * @return true - success, false - error
		 */
		bool SetVCOMDeselectLvl(VCOMDeselectLvl level);

		/**
		 * @brief Resume display ON
		 * 
		 * @param content value RAM_CONTENT or ALL_ON
		 * 
		 * @return true - success, false - error
		 */
		bool SetResumeDisplay(ResumeDisplayContent content);

		/**
		 * @brief This command sets the display to be either normal or inverse. 
		 * In normal display a RAM data of 1 indicates an “ON” pixel while in 
		 * inverse display a RAM data of 0 indicates an “ON” pixel.
		 * 
		 * @param inverse true - inverse the display
		 * 
		 * @return true - success, false - error
		 */
		bool SetInverseDisplay(bool inverse);

	private:
		uint8_t m_Width;
		uint8_t m_Height;
		bool Write(Command command);
		bool Write(uint8_t command);
		SSD1306::ComInterface* m_ComInterface;
	};

} // namespace SSD1306
