cmake_minimum_required(VERSION 3.12)

project(Synapse)

set(SOURCES Source.cpp)
set(HEADERS

	Activators.h
	activators_mat.h
	Auto_associator.h
	hebbs.h
	Perceptron.h
	types.h
	)

add_executable(synapse SOURCES HEADERS)

target_include_directories(synapse PUBLIC ${CMAKE_SOURCE_DIR}armadillo/lib ${CMAKE_SOURCE_DIR}OpenBlas)
target_link_directories(Synapse PUBLIC ${CMAKE_SOURCE_DIR}armadillo/lib)
target_link_libraries(Synapse armadillo_x64d.lib) 

