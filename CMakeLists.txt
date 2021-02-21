# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# initalize pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_PATH "/home/pi/pico/pico-sdk")

# Pull in Pico SDK (must be before project)
include(pico_sdk_import.cmake)
include(../pimoroni-pico/libraries/pico_rgb_keypad/pico_rgb_keypad.cmake)

project(rainbow_keypad C CXX ASM)

# Initialise the Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(rainbow_keypad rainbow_keypad.cpp )

pico_set_program_name(rainbow_keypad "rainbow_keypad")
pico_set_program_version(rainbow_keypad "0.1")

pico_enable_stdio_uart(rainbow_keypad 0)
pico_enable_stdio_usb(rainbow_keypad 1)

# Add the standard library to the build
target_link_libraries(rainbow_keypad pico_stdlib pico_rgb_keypad)

pico_add_extra_outputs(rainbow_keypad)

