cmake_minimum_required(VERSION 3.22)

# /usr/lib64 is where the .cmake files are
if(LINUX)
	set(CMAKE_PREFIX_PATH /usr/lib64)
endif()

set(CMAKE_AUTOMOC ON)

# Project name
project(reelz)

# Gather all files and store into the
# (SOURCE_FILES) variable
file(GLOB_RECURSE SOURCE_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/*.cpp)

# Find Qt library
# /usr/include/qt5
# Add modules by adding name of module to this list
find_package(Qt5 COMPONENTS Widgets Multimedia MultimediaWidgets REQUIRED)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES})
set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES OUTPUT_NAME "Reelz Simulator")

# Link Qt library
target_link_libraries(${CMAKE_PROJECT_NAME} Qt5::Widgets Qt5::Multimedia Qt5::MultimediaWidgets)
