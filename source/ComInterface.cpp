#include <SSD1306/ComInterface.hpp>

namespace SSD1306
{

	ComInterface::~ComInterface(){
	}

	ComInterface* ComInterface::GetComInterface(){
		static ComInterface instance;
		return &instance;
	}

	void ComInterface::SetWriteDelegate(const writeDelegate_t delegate){
		writeDelegate = delegate;
	}

	void ComInterface::SetReadDelegate(const readDelegate_t delegate){
		readDelegate = delegate;
	}

	bool ComInterface::Write(const uint8_t* data, size_t size) const{
		if(writeDelegate == nullptr)
			return false;

		return writeDelegate(data, size);
	}

} // namespace SSD1306
