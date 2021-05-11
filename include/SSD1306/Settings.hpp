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
	private:
		enum {
			COMMAND	= 0,
			DATA	= 0x40
		};

		enum class Command{
			On						= 0xA5,
			Off 					= 0xAe,
			SetClockDiv 			= 0xd5,
			SetMultiplex 			= 0xA8,
			SetDisplayOffset 		= 0xD3,
			SetStartLine			= 0x40,
			SetChargePump			= 0x8D,
			SetMemoryAddressingMode	= 0x20,
			SetContrast				= 0x81,
			SetSegmentRemap			= 0xA0,
			SetCOMOutScanDirection	= 0xc0,
			SetCOMPins				= 0xDA,
			SetPreChargePeriod		= 0xD9,
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

	public:
		/**
		 * @brief Default constructor
		 * 
		 */
		Settings() = default;

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
		bool On();

		/**
		 * @brief Disable display output
		 * 
		 * @return true - success, false - error
		 */
		bool Off();

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

	private:
		bool WriteCommand(Command command);
		bool WriteCommand(uint8_t command);
	};

} // namespace SSD1306
