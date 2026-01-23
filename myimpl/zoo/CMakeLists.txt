cmake_minimum_required(VERSION 3.10)

# Project name
project(ZooProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Source files
set(SOURCES
    main.cpp
    zoo.cpp
    animals.cpp
    amphibian.cpp
)

# Create executable
add_executable(zoo ${SOURCES})
