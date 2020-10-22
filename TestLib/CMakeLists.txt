cmake_minimum_required(VERSION 2.8.4)
project("TestLib")

set(CMAKE_CXX_FLAGS "-std=c++11 -fPIC")
set(CMAKE_C_FLAGS "-std=c++11 -fPIC")


find_package(Threads)

#引用BaseLib
set(BASELIB_HEAD "${PROJECT_SOURCE_DIR}/../../BaseLib/" CACHE INTERNAL "BaseLib HEADER_FILE location" )
set(BASELIB_LIBRARY "${PROJECT_SOURCE_DIR}/../../BaseLib/lib/" CACHE INTERNAL "BaseLib Library location" )
IF(WIN32)
        set(BASELIB_LIBRARY "${BASELIB_LIBRARY}/Debug")
ENDIF()
include_directories(${BASELIB_HEAD})
link_directories(${BASELIB_LIBRARY})

include_directories(.)
aux_source_directory(src DIR_SRCS)

add_executable(TestLib main.cpp ${DIR_SRCS})
target_link_libraries(TestLib hrRobotPub)
target_link_libraries(TestLib BaseLib)
target_link_libraries(TestLib ${CMAKE_THREAD_LIBS_INIT})
