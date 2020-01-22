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
set ( PROJECT_NAME "mylib" )

# Project Version
set ( PROJECT_VERSION 1.0.0 )

# Configure Project
project ( ${PROJECT_NAME} VERSION ${PROJECT_VERSION} DESCRIPTION "My Library" LANGUAGES C CXX )

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

set ( MY_LIB_HEADERS
	#
	"public/mylib.h" )

# =================================================================================
# SOURCES
# =================================================================================

set ( MY_LIB_SOURCES
	#
	"private/mylib.cpp" )

# =================================================================================
# BUILD
# =================================================================================

# Create SHARED Library Object
add_library ( mylib SHARED ${MY_LIB_HEADERS} ${MY_LIB_SOURCES} )

# Configure SHARED Library Object
set_target_properties ( mylib PROPERTIES
	VERSION ${PROJECT_VERSION} )