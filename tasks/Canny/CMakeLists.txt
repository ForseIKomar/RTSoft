cmake_minimum_required(VERSION 2.8)

project( cam02-10 )

find_package( OpenCV REQUIRED )
find_package( OpenGL )

if(OPENGL_FOUND)
  include_directories( ${OpenCV_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS} )
else()
  include_directories( ${OpenCV_INCLUDE_DIRS} )
endif()


add_executable( cam02-10 example_02-10.cpp  )


target_link_libraries( cam02-10 ${OpenCV_LIBS} )
