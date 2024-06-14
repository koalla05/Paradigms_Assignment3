cmake_minimum_required(VERSION 3.28)
project(Paradigms_Assignment3)

set(CMAKE_CXX_STANDARD 17)

# Create the shared library (DLL)
add_library(cezar SHARED cezar.cpp)

# Add the executable
add_executable(Paradigms_Assignment3 main.cpp)

# Link the shared library to the executable
target_link_libraries(Paradigms_Assignment3 cezar)
add_custom_command(TARGET Paradigms_Assignment3 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:cezar>
        $<TARGET_FILE_DIR:Paradigms_Assignment3>)
