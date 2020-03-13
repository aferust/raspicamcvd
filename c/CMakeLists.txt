cmake_minimum_required(VERSION 2.8)

set (CMAKE_CXX_STANDARD 11)

add_definitions(-std=c++11 -Werror=return-type)

file(GLOB rpcamd_SRC
    "*.h"
    "*.cpp"
)
find_package(raspicam REQUIRED)
find_package( OpenCV REQUIRED )

find_package(PkgConfig)

set(CMAKE_EXE_LINKER_FLAGS " -lstdc++")

add_library( rpcamdcapi STATIC ${rpcamd_SRC})

target_link_libraries(rpcamdcapi ${OpenCV_LIBS})
target_link_libraries (rpcamdcapi ${raspicam_CV_LIBS})
