# // ------------------------------------------------------------------------------
# 
# Target-Platform related defines.
# 
# // ------------------------------------------------------------------------------

# DETECT LINUX
if ( NOT ANDROID AND UNIX AND NOT DEFINED LINUX AND NOT APPLE )
		
	# LINUX ON
	set ( LINUX ON )
	
endif ( NOT ANDROID AND UNIX AND NOT DEFINED LINUX AND NOT APPLE )

# PLATFORM
if ( ANDROID ) # ANDROID

	# Set Directory Prefix
	set ( PLATFORM_DIR "android" )
	
elseif ( WIN32 ) # WINDOWS

	# Set Directory Prefix
    set ( PLATFORM_DIR "win32" )
    add_definitions( -DWINDOWS=1 )
elseif ( WIN64 ) # WINDOWS x64

	# Set Directory Prefix
    set ( PLATFORM_DIR "win64" )
    add_definitions( -DWINDOWS=1 )
elseif ( LINUX ) # LINUX
	
	# Set Directory Prefix
	set ( PLATFORM_DIR "linux" )
    add_definitions( -DLINUX=1 )
elseif ( APPLE ) # APPLE

	# Set Directory Prefix
    set ( PLATFORM_DIR "apple" )
    add_definitions( -DAPPLE=1 )
else ( ANDROID ) # ?
	
	# ERROR
	message ( SEND_ERROR "${ROOT_PROJECT_NAME} - unknown platform ! Configuration required." )
	
	# Set Directory Prefix
	set ( PLATFORM_DIR "unix" )
	
endif ( ANDROID )

# Build-Type Sub-Dir
if ( CMAKE_BUILD_TYPE STREQUAL "Debug" )

	# Add Definition
	add_definitions ( -DDEBUG=1 )
	
	# Set Build-Type Dir
	set ( BUILD_TYPE_DIR "debug" )
	
else ( CMAKE_BUILD_TYPE STREQUAL "Debug" )

	# Set Build-Type Dir
	set ( BUILD_TYPE_DIR "release" )
	
endif ( CMAKE_BUILD_TYPE STREQUAL "Debug" )