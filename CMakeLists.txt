# cmake_minimum_required(VERSION 3.5.0)
# project(spd VERSION 0.1.0 LANGUAGES C CXX)

# add_executable(spd main.cpp)

# include(CTest)
# enable_testing()
cmake_minimum_required(VERSION 3.10)

# Project name
project(SpdlogExample)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find and link spdlog (make sure it's installed)
find_package(spdlog REQUIRED)

add_library(logger logging.cpp)

# Add the executable
add_executable(SpdlogExample project.cpp )

# Link spdlog to the project
target_link_libraries(SpdlogExample PRIVATE spdlog::spdlog logger)

