cmake_minimum_required(VERSION 3.0.0)  
# 
project(1)

set (linux 0)
set (windows 0)

MESSAGE(STATUS "###################################")
MESSAGE(STATUS "operation system is ${CMAKE_SYSTEM}")
 
IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
	# MESSAGE(STATUS "current platform: Linux ")
    set(linux 1)
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows")
	# MESSAGE(STATUS "current platform: Windows")
    set(windows 1)
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
	MESSAGE(STATUS "current platform: FreeBSD")
ELSE ()
	MESSAGE(STATUS "other platform: ${CMAKE_SYSTEM_NAME}")
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Linux")

MESSAGE(STATUS "windows:${windows}")
MESSAGE(STATUS "linux:${linux}")

#if(${linux} MATCHES 1)
if(${linux})
    MESSAGE(STATUS "current platform: Linux")
    add_subdirectory (linux)
elseif(${windows})
    MESSAGE(STATUS "current platform: Windows")
    add_subdirectory(windows)
endif()
MESSAGE(STATUS "###################################")