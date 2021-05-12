#include <SSD1306/Image.hpp>

namespace SSD1306{

	Image::Image(){

	}
	Image::~Image(){

	}

	bool DrawDot(uint8_t x, uint8_t y){

	}

	bool Image::DrawLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2){
		//Bresenhams line algorithm
		uint8_t startX = (x1 < x2) ? x1 : x2; 
		uint8_t endX = (x1 > x2) ? x1 : x2;
		uint8_t startY = (y1 < y2) ? y1 : y1;
		uint8_t endY = (y1 > y2) ? y1 : y1;

		uint8_t deltaX = endX - startX;
		uint8_t deltaY = startY - endY;

		if (deltaX == 0){
			//line is vertical!
			for (uint8_t y = startY; startY <= endY; y++){
				DrawDot(startX, y);
			}
		}else if (deltaY == 0){
			//line is horizontal!
			for (uint8_t x = startX; x <= endX; x++){
				DrawDot(x, startY);
			}
		}else{
			uint8_t y = startY;
			float slope = deltaY/deltaX;
			float error = 0;
			for (uint8_t x = startX; x <= endX; x++){
				DrawDot(x, y);
				error += slope;
				if (error > 0.5){

				}
			}
		}
	}

}//namespace SSD1306