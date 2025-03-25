cmake_minimum_required(VERSION 3.15)

# Project Name
project(Synapse LANGUAGES CXX)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required packages
find_package(Eigen3 REQUIRED)
find_package(Armadillo REQUIRED)

# On macOS, OpenBLAS is installed by Homebrew in a specific location
if(APPLE)
    set(OpenBLAS_HOME "/opt/homebrew/opt/openblas")
    set(OpenBLAS_INCLUDE_DIRS "${OpenBLAS_HOME}/include")
    set(OpenBLAS_LIBRARIES "${OpenBLAS_HOME}/lib/libopenblas.dylib")
endif()

# Source Files
set(SOURCES 
    Source.cpp
    Adapters/Adapter.cpp
    Adapters/Matf_.cpp
)

# Header Files
set(HEADERS
    Activators.h
    activators_mat.h
    Auto_associator.h
    hebbs.h
    Perceptron.h
    types.h
    Adapters/Adapter.h
    Adapters/Matf_.h
)

# Create Executable
add_executable(Synapse ${SOURCES} ${HEADERS})

# Link External Libraries
target_link_libraries(Synapse PRIVATE 
    Eigen3::Eigen
    ${ARMADILLO_LIBRARIES}
    ${OpenBLAS_LIBRARIES}
)

# Include directories
target_include_directories(Synapse PRIVATE
    ${ARMADILLO_INCLUDE_DIRS}
    ${OpenBLAS_INCLUDE_DIRS}
)

# Enable Debug Symbols in Debug Mode
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(Synapse PRIVATE DEBUG_MODE)
endif()

# Set Output Directory for Binaries
set_target_properties(Synapse PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
