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

	class Display{

	private:
	enum {
		COMMAND = 0,
		DATA = 0x40
	};

	enum class Command{
		Off = 0xAe,
		SetClockDiv = 0xd5,
	};

	public:
		/**
		 * @brief Default constructor
		 * 
		 */
		Display() = default;

		/**
		 * @brief Default destructor
		 * 
		 */
		~Display() = default;

		Display(const Display&) = delete;
		Display& operator=(const Display&) = delete;
		Display(Display&&) = delete;
		Display& operator=(Display &&) = delete;

		bool TurnOff();
		bool SetClockDIV(uint8_t value);

	private:
		bool WriteCommand(Display::Command command);
		bool WriteCommand(uint8_t command);

	private:

	};

} // namespace SSD1306
