cmake_minimum_required(VERSION 3.15)

# Project Name
project(Synapse LANGUAGES CXX)

# Set C++ Standard
if(LINUX)
        set(CMAKE_CXX_EXTENSIONS OFF)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
        set(CMAKE_CXX_STANDARD 17)
        set(CMAKE_CXX_STANDARD_REQUIRED ON)
elseif(APPLE)
        set(CMAKE_CXX_EXTENSIONS OFF)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
        set(CMAKE_CXX_STANDARD 17)
        set(CMAKE_CXX_STANDARD_REQUIRED ON)
else()
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
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


# Resolve Solution Directory (Parent of CMake Directory)
set(SOLUTION_DIR ${CMAKE_SOURCE_DIR}/..)  
if(MSVC)
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


        # Link External Libraries
        target_link_libraries(Synapse PRIVATE 
            ${SOLUTION_DIR}/armadillo/lib/armadillo_x64d.lib
            ${SOLUTION_DIR}/OpenBlas/libopenblas.lib
        )



elseif(LINUX)


           # Include Paths
        include_directories(
             ${SOLUTION_DIR}/armadillo/include         
             ${SOLUTION_DIR}/vcpkg_installed/x64-linux/include  # VCPKG headers
             ${SOLUTION_DIR}/vcpkg_installed/x64-linux/include/eigen3  # VCPKG headers            
        )

        # Link External Libraries
        target_link_libraries(Synapse PRIVATE 
              ${SOLUTION_DIR}/vcpkg_installed/x64-linux/lib/libopenblas.a
              ${SOLUTION_DIR}/armadillo/lib/libarmadillo.a
        )
elseif(APPLE)


           # Include Paths
        include_directories(
             ${SOLUTION_DIR}/armadillo/include         
             ${SOLUTION_DIR}/vcpkg_installed/x64-osx/include  # VCPKG headers
             ${SOLUTION_DIR}/vcpkg_installed/x64-osx/include/eigen3  # VCPKG headers            
        )

        # Link External Libraries
        target_link_libraries(Synapse PRIVATE 
              ${SOLUTION_DIR}/vcpkg_installed/x64-osx/lib/libopenblas.a
              ${SOLUTION_DIR}/armadillo/lib/libarmadillo.a
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
