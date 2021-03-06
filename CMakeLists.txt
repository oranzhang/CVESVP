cmake_minimum_required(VERSION 2.8.4)
project(CVESVP)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

add_definitions(-std=gnu99 -Wall)

if(${CMAKE_SYSTEM_PROCESSOR} MATCHES armv7l)
    #Make it support armv7 platform
    add_definitions(-march=armv7 -mfloat-abi=hard -mfpu=neon)
elseif(${CMAKE_SYSTEM_PROCESSOR} MATCHES x86_64* OR ${CMAKE_SYSTEM_PROCESSOR} MATCHES amd64* OR ${CMAKE_SYSTEM_NAME} MATCHES Darwin*)
    add_definitions(-march=x86-64 -mtune=generic -mtune=core2 -mtune=core-avx-i)
elseif(${CMAKE_SYSTEM_PROCESSOR} MATCHES i686* OR ${CMAKE_SYSTEM_PROCESSOR} MATCHES i386*)
    add_definitions(-march=i686 -mtune=generic -mtune=core2 -mtune=core-avx-i)
else()
    message(FATAL_ERROR ${CMAKE_SYSTEM_PROCESSOR}: "Your system is unsupported!")
endif()


# Because of inline functions, we cannot use -O0 for debug.
set(CMAKE_C_FLAGS_DEBUG "-O2 -ffast-math -g")
set(CMAKE_C_FLAGS_RELEASE "-Ofast -DNDEBUG")

set(CMAKE_LD_FLAGS_DEBUG "-Wl,-O0")
set(CMAKE_LD_FLAGS_RELEASE "-Wl,-O1,--as-needed,--sort-common")

enable_testing()

include(GNUInstallDirs)

# uninstall target
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
    IMMEDIATE @ONLY)

add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)

add_subdirectory(src)
add_subdirectory(doc)
add_subdirectory(test)

