cmake_minimum_required(VERSION 2.6)
project(warehousebot)

INCLUDE(FindPkgConfig)

IF(CMAKE_COMPILER_IS_GNUCC)
SET(CMAKE_CXX_FLAGS
"${CMAKE_CXX_FLAGS} -Wall -std=c++0x -DBUILD_SHARED_LIBS=OFF")
ENDIF(CMAKE_COMPILER_IS_GNUCC)

# definicoes da remoteAPI para CPP
add_definitions(-DNON_MATLAB_PARSING)
add_definitions(-DMAX_EXT_API_CONNECTIONS=255)

set(SOURCES
    remoteApi/extApi.c
    #remoteApi/extApiCustom.c
    remoteApi/extApiPlatform.c
    libraries/diffdrive.cpp
    libraries/dock.cpp
    libraries/linefollow.cpp
    libraries/robot.cpp
    libraries/statemachine.cpp
    libraries/battery.cpp
)

set(HEADERS
    remoteApi/extApi.h
    #remoteApi/extApiCustom.h
    remoteApi/extApiInternal.h
    remoteApi/extApiPlatform.h
    include/v_repConst.h
    include/v_repLib.h
    libraries/diffdrive.h
    libraries/dock.h
    libraries/linefollow.h
    libraries/robot.h
    libraries/statemachine.h
    libraries/battery.h
)

include_directories("remoteApi/")
include_directories("include/")
include_directories("libraries/")

find_package(Threads REQUIRED)

add_executable(warehousebot warehousebot.cpp ${SOURCES} ${HEADERS})
add_executable(warehousedock warehousedock.cpp ${SOURCES} ${HEADERS})
add_executable(warehousebattery warehousebattery.cpp ${SOURCES} ${HEADERS})

if(WIN32)
    target_link_libraries(warehousebot ${CMAKE_THREAD_LIBS_INIT} winmm ws2_32)
    target_link_libraries(warehousedock ${CMAKE_THREAD_LIBS_INIT} winmm ws2_32)
    target_link_libraries(warehousebattery ${CMAKE_THREAD_LIBS_INIT} winmm ws2_32)
endif()

if(UNIX AND NOT APPLE)
    target_link_libraries(warehousebot ${CMAKE_THREAD_LIBS_INIT} pthread)
    target_link_libraries(warehousedock ${CMAKE_THREAD_LIBS_INIT} pthread)
    target_link_libraries(warehousebattery ${CMAKE_THREAD_LIBS_INIT} pthread)
endif()

install(TARGETS warehousebot RUNTIME DESTINATION bin)
install(TARGETS warehousedock RUNTIME DESTINATION bin)
install(TARGETS warehousebattery RUNTIME DESTINATION bin)
