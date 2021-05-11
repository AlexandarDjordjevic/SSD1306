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
            ChargePump				= 0x8D,
            MemoryAddressingMode	= 0x20,
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
         * @brief Enable display output
         * 
         * @return true - success
         * @return false - error
         */
        bool On();

        /**
         * @brief Disable display output
         * 
         * @return true - success, false - error
         */
        bool Off();

        /**
         * @brief 
         * Set the clock divide ratio and oscillator frequency.
         * Settings Clock Divide Ratio Value[3:0]
         *	Set the divide ratio to generate DCLK (Settings Clock) from CLK. The divide ratio is from 1 to 16,
         *	with reset value = 1.
         * Oscillator Frequency Value[7:4]
         *	Program the oscillator frequency Fosc that is the source of CLK if CLS pin is pulled high. The 4-bit
         *	value results in 16 different frequency settings available. The default setting is 1000b. 
         * 
         * @param value Clock divide and oscillator frequency values
         * 
         * @return true - success, false - error
         */
        bool SetClockDIV(uint8_t value);

        /**
         * @brief Switches the default 63 multiplex mode to any multiplex ratio, ranging from 16 to 63
         * 
         * @param value 
         * @return true - success, false - error
         */
        bool SetMultiplex(uint8_t value);

        
        bool SetOffset(uint8_t value);
        bool SetStartLine(uint8_t value);
   
        bool ChargePump(ChargePumpStatus cps);

        bool MemoryAddressingMode(MemoryAddressingModeType mamt);

    private:
        bool WriteCommand(Command command);
        bool WriteCommand(uint8_t command);
    };

} // namespace SSD1306
