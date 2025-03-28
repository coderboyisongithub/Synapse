cmake_minimum_required(VERSION 3.10)

# Project Name
project(Synapse)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Windows-specific configuration
if(WIN32)
    set(CMAKE_PREFIX_PATH "C:/Program Files/Armadillo")
    set(CMAKE_INCLUDE_PATH "C:/Program Files/Armadillo/include")
    set(CMAKE_LIBRARY_PATH "C:/Program Files/Armadillo/lib")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/lib)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/lib)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/lib)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/lib)
endif()

# macOS-specific configuration
if(APPLE)
    # Find required packages using Homebrew paths
    set(CMAKE_PREFIX_PATH "/opt/homebrew/opt/armadillo;/opt/homebrew/opt/openblas;/opt/homebrew/opt/eigen")
    set(CMAKE_INCLUDE_PATH "/opt/homebrew/opt/armadillo/include;/opt/homebrew/opt/openblas/include;/opt/homebrew/opt/eigen/include")
    set(CMAKE_LIBRARY_PATH "/opt/homebrew/opt/armadillo/lib;/opt/homebrew/opt/openblas/lib")
    
    # Set Armadillo paths for macOS
    set(ARMADILLO_INCLUDE_DIRS "/opt/homebrew/opt/armadillo/include")
    set(ARMADILLO_LIBRARIES "/opt/homebrew/opt/armadillo/lib/libarmadillo.dylib")
    
    # Set OpenBLAS paths for macOS
    set(OpenBLAS_INCLUDE_DIRS "/opt/homebrew/opt/openblas/include")
    set(OpenBLAS_LIBRARIES "/opt/homebrew/opt/openblas/lib/libopenblas.dylib")
    
    # Set Eigen paths for macOS
    set(EIGEN3_INCLUDE_DIR "/opt/homebrew/opt/eigen/include/eigen3")
endif()

# Find required packages
find_package(Armadillo REQUIRED)
find_package(OpenBLAS REQUIRED)
find_package(Eigen3 REQUIRED)

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
if(APPLE)
    target_link_libraries(Synapse PRIVATE ${ARMADILLO_LIBRARIES} ${OpenBLAS_LIBRARIES})
else()
    target_link_libraries(Synapse PRIVATE Armadillo::Armadillo OpenBLAS::OpenBLAS)
endif()

# Include directories
target_include_directories(Synapse PRIVATE 
    ${ARMADILLO_INCLUDE_DIRS} 
    ${OpenBLAS_INCLUDE_DIRS}
    ${EIGEN3_INCLUDE_DIR}
)

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
