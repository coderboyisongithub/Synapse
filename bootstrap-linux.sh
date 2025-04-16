#!/bin/bash
cat << "EOF"
     █████                                                        
     ██                                                             
     ███    ██   ██ ███████  ██████  ███████ █████  ██████          
        ███  ██ ██  ██   ██  ██████  ██   ██ ████  ████████         
         ███  ████  ██   ██ ██   ██  ██   ██    ███ ██              
     █████     ██   ██   ██  ██████  ██████  █████   █████         
             ███                     ██                             
             █                       █                              
EOF




rm -rf  build
# Define the local vcpkg directory within the cloned repository
VCPKG_DIR="$(pwd)/vcpkg"
VCPKG_EXE="$VCPKG_DIR/vcpkg"

# Ninja, vcpkg
# Check if vcpkg is available in the system environment
VCPKG_SYSTEM_PATH=$(command -v vcpkg)

if [ -n "$VCPKG_SYSTEM_PATH" ]; then
    echo "System-wide vcpkg found: $VCPKG_SYSTEM_PATH"
elif [ -f "$VCPKG_EXE" ]; then
    echo "Local vcpkg found: $VCPKG_EXE"
else
    echo "vcpkg not found. Installing locally..." 
    # Clone the vcpkg repository
    echo "Cloning vcpkg repository..."
    git clone https://github.com/microsoft/vcpkg.git "$VCPKG_DIR"
    
    if [ ! -d "$VCPKG_DIR" ]; then
        echo "Failed to clone vcpkg repository." 
        exit 1
    fi
    
    # Run the bootstrap script to build vcpkg
    echo "Bootstrapping vcpkg..."
    "$VCPKG_DIR/bootstrap-vcpkg.sh"
    
    if [ -f "$VCPKG_EXE" ]; then
        echo "vcpkg installation completed successfully." 
        # Add vcpkg to the environment PATH (only for this session)
        export PATH="$VCPKG_DIR:$PATH"
        echo "vcpkg set for local path env var" 
    else
        echo "vcpkg installation failed." 
        exit 1
    fi

fi

  echo "Installing dependency" 
    "$VCPKG_DIR/vcpkg" install 
    apt download libarmadillo-dev
    dpkg-deb -x libarmadillo-dev*.deb  ./local

# vcpkg section up.



# Check if CMake is installed
CMAKE_EXE=$(command -v cmake)

if [ -z "$CMAKE_EXE" ]; then
    echo "CMake not found! Installing..." 

    # Install CMake using a package manager (apt for Ubuntu/Debian-based systems, adjust for others)
    sudo apt-get install cmake -y

    # Refresh the environment to detect CMake (in most cases, this is not needed as package manager updates the environment)
    export PATH=$(getconf PATH)

    CMAKE_EXE=$(command -v cmake)

    if [ -z "$CMAKE_EXE" ]; then
        echo "CMake installation failed!" 
        exit 1
    fi
fi

# Run CMake to list available generators
CMAKE_GENERATORS=$(cmake --help | grep -A 50 "Generators")
echo "Available CMake Generators: $CMAKE_GENERATORS"

echo "switching to build directory"
mkdir -p build
cd build



# Loop for user confirmation
while true; do
    # Prompt the user to select a generator from the list
    echo "copy and paste the generator from the list"
    read -p "Selected generator: " SELECTED_GENERATOR

    echo "selected generator is: $SELECTED_GENERATOR"
    read -p "Do you want to continue? (yes/no): " RESPONSE
    RESPONSE=$(echo "$RESPONSE" | tr '[:upper:]' '[:lower:]')

    if [ "$RESPONSE" == "yes" ]; then
        echo "Proceeding..." 
        break
    elif [ "$RESPONSE" == "no" ]; then
        echo "You selected No. Asking again..." 
    else
        echo "Invalid input. Please enter 'yes' or 'no'." 
    fi
done

# Run CMake with the selected generator
cmake ../Synapse -G "$SELECTED_GENERATOR"  -DCMAKE_CXX_COMPILER=clang++ 
cmake --build .
