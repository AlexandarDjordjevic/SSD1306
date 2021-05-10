cmake_minimum_required(VERSION 3.8)

project(SSD1306)

set(this SSD1306)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_C_FLAGS "-Wall -Werror")
set(CMAKE_CXX_FLAGS "-Wall -Werror")

set(include
	include/SSD1306/ComInterface.hpp
	include/SSD1306/Display.hpp
)

set(source
	source/ComInterface.cpp
	source/Display.cpp
	main.cpp
)

add_executable(${this} ${source})

target_include_directories(${this} PUBLIC include)

#target_link_libraries(${this})

#add_subdirectory(test)
