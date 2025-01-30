cmake_minimum_required(VERSION 3.25)

project(ResMan LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Define warning flags
set(WAR_PANIC "-Wall -Wextra -pedantic")

if(MSVC)
    target_compile_options(ResMan PRIVATE
        # Debug flags
        "$<$<CONFIG:Debug>:/Zi>"
        "$<$<CONFIG:Debug>:/Od>"
        "$<$<CONFIG:Debug>:/RTC1>"
        "$<$<CONFIG:Debug>:/MDd>"
        "$<$<CONFIG:Debug>:/EHsc>"
        "$<$<CONFIG:Debug>:/DEBUG>"
        "$<$<CONFIG:Debug>:/DYNAMICBASE>"
        "$<$<CONFIG:Debug>:/analyze>"

        # Release flags
        "$<$<CONFIG:Release>:/O2>"
        "$<$<CONFIG:Release>:/MD>"
        "$<$<CONFIG:Release>:/DNDEBUG>"
    )
else()
# Compiler-specific flags
set(CMAKE_CXX_FLAGS_RELEASE "${WAR_PANIC} -O2 -s -flto -fdata-sections -ffunction-sections -Wl,--gc-sections -mwindows")  # Optimize for GCC/Clang
set(CMAKE_CXX_FLAGS_DEBUG "${WAR_PANIC} -O0 -g3 -ggdb ")  # Debugging for GCC/Clang
endif()


add_executable(ResMan main.cpp)