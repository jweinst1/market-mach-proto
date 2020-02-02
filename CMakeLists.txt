# Project <proj> main cmake file

cmake_minimum_required(VERSION 3.3)

project(market_proto VERSION 0.0.1)

include( CheckCSourceCompiles )

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


# The header content of the basic market types

file(READ market-types.h MARKET_TYPES_HEADER)

set(TEST_MARKET_TYPES_HEADER "${MARKET_TYPES_HEADER} int main(void) { return 0; }")

check_c_source_compiles("${TEST_MARKET_TYPES_HEADER}" WORKS_MARKET_TYPES)

set(MARKET_PROTO_HEADERS
    market-types.h
    market-order.h
    market-strategy.h
)

# Create a single header of all headers
set(MARKET_PROTO_SINGLE_HEADER "")
foreach( HFILE ${MARKET_PROTO_HEADERS})
    file(READ ${HFILE} H_HEADER_CONTENT)
    set(MARKET_PROTO_SINGLE_HEADER "${MARKET_PROTO_SINGLE_HEADER} \n${H_HEADER_CONTENT}")
endforeach()

set(MARKET_PROTO_SOURCES
    market-order.c
    market-strategy.c
)

# Create a single source file of all .c files
set(MARKET_PROTO_SINGLE_SOURCE "")
foreach( CFILE ${MARKET_PROTO_SOURCES})
    file(READ ${CFILE} C_FILE_CONTENT)
    set(MARKET_PROTO_SINGLE_SOURCE "${MARKET_PROTO_SINGLE_SOURCE} \n${C_FILE_CONTENT}")
endforeach()

# Test for __func__
check_c_source_compiles("int main(void) { const char* foo = __func__; return 0;}" WORKS_FUNC_KEYWORD)

# Build the lib

add_library(market_protos STATIC "${MARKET_PROTO_SOURCES}")

set(MARKET_PROTO_TEST_FILES
    test_market-order.c
    test_market-strategy.c
)

foreach(TFILE ${MARKET_PROTO_TEST_FILES})
    message("** Adding test for file ${TFILE}")
    # This is a temporary executable, will be something like 'foo.c.exe' on windows.
    add_executable(${TFILE} ${TFILE})
    target_link_libraries(${TFILE} PRIVATE market_protos)
    add_test("${TFILE}" ${TFILE})
endforeach()


