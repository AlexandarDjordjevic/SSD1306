/**
 * @author Aleksandar Djordjevic (aleksandar1608@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#pragma once
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

namespace SSD1306
{
	class ComInterface{
	public:
		typedef bool(*writeDelegate_t)(const uint8_t* source, size_t size);
		typedef bool(*readDelegate_t)(uint8_t* destination, size_t max_size);

	private:
		/**
		 * @brief Default constructor
		 * 
		 */
		ComInterface() = default;

	public:
		/**
		 * @brief Default destructor
		 * 
		 */
		~ComInterface();

		ComInterface(const ComInterface&) = delete;
		ComInterface& operator=(const ComInterface&) = delete;
		ComInterface(ComInterface&&) = delete;
		ComInterface& operator=(ComInterface &&) = delete;

		static ComInterface* GetComInterface();

		void SetWriteDelegate(const writeDelegate_t delegate);
		void SetReadDelegate(const readDelegate_t delegate);

		bool Write(const uint8_t* source, size_t size) const;
		bool Read(uint8_t* source, size_t size) const;

	private:
		writeDelegate_t writeDelegate;
		readDelegate_t readDelegate;
	};

} // namespace SSD1306
