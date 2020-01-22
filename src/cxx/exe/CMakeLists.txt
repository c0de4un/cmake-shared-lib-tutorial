# // ------------------------------------------------------------------------------
# 
# @About:
# This is tutorial-project to demonstrate usage of CMake in building
# shared library for C++.
# 
# License: see "LICENSE" file.
# Tools: VSCode, Ninja, CMake, MSBuild (MSVC) || GCC.
# API: C++ 11 is minimum.
# Platforms: Any with C++ 11 support.
# 
# // ------------------------------------------------------------------------------

# =================================================================================
# CMake Meta-Data
# =================================================================================

# CMake-Version
cmake_minimum_required ( VERSION 3.6 FATAL_ERROR )

# =================================================================================
# PROJECT
# =================================================================================

# Project Name
set ( PROJECT_NAME "myExe" )

# Project Version
set ( PROJECT_VERSION 1.0.0 )

# Configure Project
project ( ${PROJECT_NAME} VERSION ${PROJECT_VERSION} DESCRIPTION "My Executable" LANGUAGES C CXX )

# C Version
#set ( CMAKE_C_STANDARD 99 )

# C++ Version
#set ( CMAKE_CXX_STANDARD 11 )

# Make Build Libs & Executables to be position-independent, like SHARED libs.
#set ( CMAKE_POSITION_INDEPENDENT_CODE ON )

# =================================================================================
# CONFIG
# =================================================================================



# =================================================================================
# HEADERS
# =================================================================================

set ( MY_EXE_HEADERS
	#
	"main.hpp" )

# =================================================================================
# SOURCES
# =================================================================================

set ( MY_EXE_SOURCES
	#
	"main.cpp" )

message ( STATUS "Lib = ${mylib}" )

# =================================================================================
# BUILD
# =================================================================================

# Add Executable-Object
add_executable ( myexe ${MY_EXE_HEADERS} ${MY_EXE_SOURCES} )

# Configure Executable-Object
set_target_properties ( myexe PROPERTIES
	OUTPUT_NAME "shared_library_example"
	RUNTIME_OUTPUT_DIRECTORY "${BIN_DIR}" )

# Include MyLib Public-Headers
include_directories( "../lib/public" )

target_link_libraries ( myexe mylib )