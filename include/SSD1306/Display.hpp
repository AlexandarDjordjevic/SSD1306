/**
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-11
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#pragma once
#include <SSD1306/Settings.hpp>
namespace SSD1306
{
	class Display{
	public:
		/**
		 * @brief Default constructor
		 * 
		 */
		Display();

		/**
		 * @brief Default destructor
		 * 
		 */
		~Display();

		Display(const Display&) = delete;
		Display& operator=(const Display&) = delete;
		Display(Display&&) = delete;
		Display& operator=(Display &&) = delete;

		bool Initialize();
		bool On();
		bool Update();
	private:
		Settings m_Settings;

	};

} // namespace SSD1306
