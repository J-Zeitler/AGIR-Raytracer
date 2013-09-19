project(AGIR-Raytracer)
cmake_minimum_required(VERSION 2.8)

list(APPEND INCLUDE_DIRS
        ${CMAKE_SOURCE_DIR}/
	${CMAKE_SOURCE_DIR}/lib
	${CMAKE_SOURCE_DIR}/lib/glm
)

include_directories(	
	${INCLUDE_DIRS}
)

aux_source_directory(. SRC_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST})
