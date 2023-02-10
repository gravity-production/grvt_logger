cmake_minimum_required(VERSION 3.24)
project(logger)

set(CMAKE_CXX_STANDARD 17)

set(Directories
        )

Set(Sources
        logger.hpp logger.cpp)

add_library(logger STATIC ${Sources})
target_include_directories(logger PRIVATE ${Directories})
