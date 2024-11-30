cmake_minimum_required(VERSION 3.12)

project(Synapse)

set(SYNAPSE_DIR ${CMAKE_SOURCE_DIR}/synapse)

include_directories(${SYNAPSE_DIR})
#set(SOURCES ${SYNAPSE_DIR}/Source.cpp Auto_associator.cpp Perceptron.cpp)
file(GLOB SOURCES "${SYNAPSE_DIR}/*.cpp")

# Grab all .h files in the synapse directory
file(GLOB HEADERS "${SYNAPSE_DIR}/*.h")

add_executable(Synapse ${SOURCES} ${HEADERS})

target_include_directories(Synapse PUBLIC ${CMAKE_SOURCE_DIR}/armadillo/include)
target_link_directories(Synapse PUBLIC ${CMAKE_SOURCE_DIR}/armadillo/lib ${CMAKE_SOURCE_DIR}/OpenBlas)
target_link_libraries(Synapse armadillo_x64d.lib libopenblas.lib) 

