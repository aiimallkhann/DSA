cmake_minimum_required(VERSION 3.20)
project(DSA CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Search for all .cpp files recursively in the project folder.
# CONFIGURE_DEPENDS tells CMake to re-check for new/deleted files automatically on build!
file(GLOB_RECURSE ALL_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

# 2. Loop through every found .cpp file and make it an independent executable
foreach(SOURCE_FILE ${ALL_SOURCES})
    # Ignore any files generated inside the build directory
    if(NOT SOURCE_FILE MATCHES "cmake-build-")
        # Get the filename without extension (e.g., "reverse-array.cpp" -> "reverse-array")
        get_filename_component(TARGET_NAME ${SOURCE_FILE} NAME_WE)

        # Dynamically create an executable target named after the file
        add_executable(${TARGET_NAME} "${SOURCE_FILE}"
                "2D-Arrays Vectors/two-sum.cpp")
    endif()
endforeach()