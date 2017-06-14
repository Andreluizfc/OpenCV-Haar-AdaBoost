cmake_minimum_required(VERSION 2.8.12)

project( recognize )

set( OpenCV_FOUND 1 )
find_package( OpenCV 3 REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( recognize recognize.cpp )
target_link_libraries( recognize ${OpenCV_LIBS} )
