#!/bin/bash

# Define the local vcpkg directory within the cloned repository
VCPKG_DIR="$(dirname "$0")/vcpkg"
VCPKG_EXE="$VCPKG_DIR/vcpkg"

# Function to print colored output
print_colored() {
    local color=$1
    local message=$2
    case $color in
        "yellow") echo -e "\033[1;33m$message\033[0m" ;;
        "green") echo -e "\033[1;32m$message\033[0m" ;;
        "red") echo -e "\033[1;31m$message\033[0m" ;;
        "cyan") echo -e "\033[1;36m$message\033[0m" ;;
        *) echo "$message" ;;
    esac
}

# Check if vcpkg is available in the system
if command -v vcpkg &> /dev/null; then
    print_colored "green" "System-wide vcpkg found: $(which vcpkg)"
elif [ -f "$VCPKG_EXE" ]; then
    print_colored "green" "Local vcpkg found: $VCPKG_EXE"
else
    print_colored "yellow" "vcpkg not found. Installing locally..."
    
    # Clone the vcpkg repository
    print_colored "yellow" "Cloning vcpkg repository..."
    git clone https://github.com/microsoft/vcpkg.git "$VCPKG_DIR"
    
    if [ ! -d "$VCPKG_DIR" ]; then
        print_colored "red" "Failed to clone vcpkg repository."
        exit 1
    fi
    
    # Run the bootstrap script to build vcpkg
    print_colored "yellow" "Bootstrapping vcpkg..."
    "$VCPKG_DIR/bootstrap-vcpkg.sh"
    
    if [ -f "$VCPKG_EXE" ]; then
        print_colored "green" "vcpkg installation completed successfully."
        # Add vcpkg to the environment PATH (only for this session)
        export PATH="$VCPKG_DIR:$PATH"
        print_colored "green" "vcpkg set for local path env var"
    else
        print_colored "red" "vcpkg installation failed."
        exit 1
    fi

    print_colored "yellow" "Installing dependencies"
    vcpkg install
fi

# Check if CMake is installed
if ! command -v cmake &> /dev/null; then
    print_colored "yellow" "CMake not found! Installing using Homebrew..."
    
    # Check if Homebrew is installed
    if ! command -v brew &> /dev/null; then
        print_colored "yellow" "Installing Homebrew..."
        /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
    fi
    
    # Install CMake using Homebrew
    brew install cmake
    
    if ! command -v cmake &> /dev/null; then
        print_colored "red" "CMake installation failed!"
        exit 1
    fi
fi

# Run CMake to list available generators
print_colored "yellow" "Available CMake Generators:"
cmake --help | grep -A 50 "Generators"

# Create and switch to build directory
print_colored "yellow" "Switching to build directory"
mkdir -p build
cd build

# Prompt for generator selection
read -p "Enter the generator from the list above: " selected_generator
print_colored "cyan" "Selected generator is: $selected_generator"

# Prompt for confirmation
while true; do
    read -p "Do you want to continue? (yes/no): " response
    response=$(echo "$response" | tr '[:upper:]' '[:lower:]' | xargs)
    
    if [ "$response" = "yes" ]; then
        print_colored "green" "Proceeding..."
        break
    elif [ "$response" = "no" ]; then
        print_colored "yellow" "You selected No. Asking again..."
    else
        print_colored "red" "Invalid input. Please enter 'yes' or 'no'."
    fi
done

# Run CMake configuration
cmake ../synapse -G "$selected_generator" 

# Run the program
print_colored "yellow" "Running the program..."
./bin/Synapse 