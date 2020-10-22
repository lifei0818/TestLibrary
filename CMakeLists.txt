cmake_minimum_required(VERSION 2.8.4)
project("TestProject")

set(CMAKE_CXX_FLAGS "-std=c++11 -fPIC")
set(CMAKE_C_FLAGS "-std=c++11 -fPIC")


#引用BaseLib
set(BASELIB_HEAD "${PROJECT_SOURCE_DIR}/../../BaseLib/" CACHE INTERNAL "BaseLib HEADER_FILE location" )
set(BASELIB_LIBRARY "${PROJECT_SOURCE_DIR}/../../BaseLib/lib/" CACHE INTERNAL "BaseLib Library location" )
IF(WIN32)
        set(BASELIB_LIBRARY "${BASELIB_LIBRARY}/${CMAKE_INTDIR}")
ENDIF()
include_directories(${BASELIB_HEAD})
link_directories(${BASELIB_LIBRARY})

include_directories(TestLib)
add_subdirectory(TestLib)
