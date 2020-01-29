# Project <proj> main cmake file

cmake_minimum_required(VERSION 3.3)

project(market_proto VERSION 0.0.1)

# Option to install targets to env location
if(DEFINED ENV{MARKET_PROTO_HOME})
     message("-- Will install MARKET_PROTO_HOME binaries and libraries to location: " $ENV{MARKET_PROTO_HOME})
	 set(CMAKE_INSTALL_PREFIX $ENV{MARKET_PROTO_HOME})
else(DEFINED ENV{MARKET_PROTO_HOME})
     message("-- Will install MARKET_PROTO_HOME binaries and libraries to location: " ${CMAKE_CURRENT_BINARY_DIR})
	 set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_BINARY_DIR})
endif(DEFINED ENV{MARKET_PROTO_HOME})


# Disable some windows specific warnings for using more modern c functions
if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif(MSVC)

# Options
option(WITH_testing "Allows tests to be run" ON)
option(WITH_debug "Turns on debug related messages" OFF)

if(WITH_testing MATCHES ON)
   enable_testing()
endif(WITH_testing MATCHES ON)

if(WITH_debug MATCHES ON)
   add_definitions(-DWITH_DEBUG_F)
endif(WITH_debug MATCHES ON)

include_directories($(PROJECT_SOURCE_DIR)/include)
