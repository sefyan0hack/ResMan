cmake_minimum_required(VERSION 3.25)

project(ResMan LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Define warning flags
set(WAR_PANIC "-Wall -Wextra -pedantic")
add_executable(ResMan main.cpp)
set_target_properties(ResMan PROPERTIES OUTPUT_NAME "ResMan")

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(ResMan PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        -Weverything
        -Wno-c++98-compat
        -Wno-c++98-compat-pedantic

        "$<$<CONFIG:Debug>:-g3>"
        "$<$<CONFIG:Debug>:-O0>"
        "$<$<CONFIG:Debug>:-fno-inline>"

        "$<$<CONFIG:Release>:-O3>"
        "$<$<CONFIG:Release>:-g0>"
        "$<$<CONFIG:Release>:-DNDEBUG>"
    )
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(ResMan PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        -Wduplicated-cond
        -Wlogical-op
        -Wnull-dereference

        "$<$<CONFIG:Debug>:-g3>"
        "$<$<CONFIG:Debug>:-O0>"
        "$<$<CONFIG:Debug>:-fno-inline>"

        "$<$<CONFIG:Release>:-O3>"
        "$<$<CONFIG:Release>:-g0>"
        "$<$<CONFIG:Release>:-DNDEBUG>"
    )
elseif(MSVC)
    # Existing MSVC flags
    target_compile_options(ResMan PRIVATE
        /W3
        /permissive-
        "$<$<CONFIG:Debug>:/Zi>"
        "$<$<CONFIG:Debug>:/Od>"
        "$<$<CONFIG:Debug>:/RTC1>"
        "$<$<CONFIG:Debug>:/MDd>"
        "$<$<CONFIG:Debug>:/EHsc>"
        "$<$<CONFIG:Debug>:/DEBUG>"
        "$<$<CONFIG:Debug>:/DYNAMICBASE>"
    )
endif()