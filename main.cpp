#include <cstdlib>
#include <iostream>
#include  <iomanip>
#include <SSD1306/ComInterface.hpp>
#include <SSD1306/Display.hpp>

bool I2CWrite(const uint8_t* data, size_t size){
	std::cout << "[I2C Write] Size: " << size << " , Data: ";
	for (size_t i = 0; i < size; i++){
		std::cout << "0x" << std::setfill('0') << std::setw(2) << std::hex << (int)data[i] << " ";
	}
	std::cout << std::dec << std::endl;
	return true;
}

int main(){
	SSD1306::ComInterface::GetComInterface().SetWriteDelegate(I2CWrite);
	SSD1306::Display display;
    display.Initialize();
	return EXIT_SUCCESS;
}