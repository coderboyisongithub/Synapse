cmake_minimum_required(VERSION 3.15)

# Project Name
project(Synapse LANGUAGES CXX)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Eigen
find_package(Eigen3 REQUIRED)

# Resolve Solution Directory (Parent of CMake Directory)
set(SOLUTION_DIR ${CMAKE_SOURCE_DIR}/..)  

# Include Paths
include_directories(
    ${SOLUTION_DIR}/armadillo/include       # Armadillo headers
    ${SOLUTION_DIR}/vcpkg_installed/x64-windows/include  # VCPKG headers
)

# Library Paths
link_directories(
    ${SOLUTION_DIR}/armadillo/lib           # Armadillo libraries
    ${SOLUTION_DIR}/OpenBlas                # OpenBLAS libraries
)

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
    ${SOLUTION_DIR}/armadillo/lib/armadillo_x64d.lib
    ${SOLUTION_DIR}/OpenBlas/libopenblas.lib
)

# macOS-specific settings
if(APPLE)
    # Set OpenBLAS paths for macOS
    set(OpenBLAS_HOME "/opt/homebrew/opt/openblas")
    set(OpenBLAS_INCLUDE_DIRS "${OpenBLAS_HOME}/include")
    set(OpenBLAS_LIBRARIES "${OpenBLAS_HOME}/lib/libopenblas.dylib")
    
    # Override library paths for macOS
    target_link_libraries(Synapse PRIVATE 
        Eigen3::Eigen
        ${SOLUTION_DIR}/armadillo/lib/libarmadillo.dylib
        ${OpenBLAS_LIBRARIES}
    )
    
    # Add OpenBLAS include directory for macOS
    target_include_directories(Synapse PRIVATE
        ${OpenBLAS_INCLUDE_DIRS}
    )
endif()

# Enable Debug Symbols in Debug Mode
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(Synapse PRIVATE DEBUG_MODE)
endif()

# Set Output Directory for Binaries
set_target_properties(Synapse PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# VCPKG Integration (if using)
if(DEFINED CMAKE_TOOLCHAIN_FILE)
    message(STATUS "Using VCPKG toolchain: ${CMAKE_TOOLCHAIN_FILE}")
endif()
