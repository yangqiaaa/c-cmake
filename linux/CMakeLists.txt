cmake_minimum_required(VERSION 3.0.0)  
# 
project(3)

# source file
file(GLOB LINUX_SOURCE_DIR 
    ./source/linux.c
    ./source/1-base/*.c)
#    ./source/main.c
#    ./source/1/*.c
#    ./source/2-student-handle-system/*.c
#    ./source/3-leetcode/*.c)
#
set(MY_INCLUDE_DIR 
    #include
    ./include/1-base)
    #lib
#    ./lib/ut
    #include
#    ./include/1-base
#    ./include/1
 #   ./include/2-student-handle-system
  #  ./include/3-leetcode)

# include file
include_directories (${MY_INCLUDE_DIR})

#link lib 编译器自带
# LINK_LIBRARIES(-lm -lpthread -lmysqlclient)
#if(${linux})
 #   LINK_LIBRARIES(-lm -lpthread)
#endif()

#if(${windows})
 #   LINK_LIBRARIES(-lm -lwsock32)
#endif()

# find lib 第三方库
#if(${linux})
 #   find_library(ORTP_LIB libortp.so.9.0.0 ${PROJECT_SOURCE_DIR}/lib/1-ortp)
 #   find_library(MELON_LIB libmelon.so ${PROJECT_SOURCE_DIR}/lib/2-melon)
#endif()

# 生成可执行文件
add_executable (main ${LINUX_SOURCE_DIR})

#可执行文件链接库
#if(${linux})
 #   target_link_libraries (main ${ORTP_LIB})
 #   target_link_libraries (main ${MELON_LIB})
#endif()

# 可执行文件生成路径
#if(${linux})
    set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#elseif(${windows})
#set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/exe)
#else()
#endif()
