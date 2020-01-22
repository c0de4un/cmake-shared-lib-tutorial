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
set ( PROJECT_NAME "cmake_shared_lib_tutorial" )

# Project Version
set ( PROJECT_VERSION 1.0.0 )

# Configure Project
project ( ${PROJECT_NAME} VERSION ${PROJECT_VERSION} DESCRIPTION "CMake Shared-Library Tutorial" LANGUAGES C CXX )

# C Version
#set ( CMAKE_C_STANDARD 99 )

# C++ Version
#set ( CMAKE_CXX_STANDARD 11 )

# Make Build Libs & Executables to be position-independent, like SHARED libs.
#set ( CMAKE_POSITION_INDEPENDENT_CODE ON )

# =================================================================================
# CONFIGS
# =================================================================================

# Platform, Build-Type, ABI
include ( "${CMAKE_SOURCE_DIR}/cmake/platform_defines.cmake" )

# Binary Output Dir
set ( BIN_DIR "${CMAKE_SOURCE_DIR}/bin/${PLATFORM_DIR}/${BUILD_TYPE_DIR}" )

# =================================================================================
# MODULES
# =================================================================================

# Library
add_subdirectory ( "src/cxx/lib" )

# Executable
add_subdirectory ( "src/cxx/exe" )