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
#include <stdint.h>
#include <stdbool.h>

namespace SSD1306
{
	class Image{
	public:
		/**
		 * @brief Default constructor
		 * 
		 */
		Image();

		/**
		 * @brief Default destructor
		 * 
		 */
		~Image();

		Image(const Image&) = delete;
		Image& operator=(const Image&) = delete;
		Image(Image&&) = delete;
		Image& operator=(Image &&) = delete;

		bool DrawLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);
		bool DrawCircle(uint8_t x, uint8_t y, uint8_t radius, bool fill);
		bool DrawRectangel(uint8_t x, uint8_t y, uint8_t width, uint8_t height, bool fill);
		bool FromFile(uint8_t x, uint8_t y, const char* image_uri);
		bool InsertText(uint8_t x, uint8_t y, const char* font_uri, const char* text);
		
	private:
	};

} // namespace SSD1306
