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

# Check if running on macOS
if [[ "$OSTYPE" != "darwin"* ]]; then
    print_colored "red" "This script is for macOS only. Please use bootstrap.ps1 for Windows."
    exit 1
fi

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

# Check if Homebrew is installed
if ! command -v brew &> /dev/null; then
    print_colored "yellow" "Homebrew not found! Installing Homebrew..."
    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
fi

# Install required packages
print_colored "yellow" "Installing required packages..."
brew install cmake armadillo openblas eigen

# Create build directory in the Synapse subdirectory
print_colored "yellow" "Creating build directory..."
cd Synapse

# Show available build systems and prompt for choice
print_colored "cyan" "Available CMake Generators:"
cmake --help | grep -A 50 "Generators" | grep -v "Generators"

print_colored "yellow" "Please copy and paste the generator name from the list above"
read -p "Enter generator name: " selected_generator

print_colored "cyan" "Selected generator: $selected_generator"

while true; do
    read -p "Do you want to continue? (yes/no): " response
    response=$(echo "$response" | tr '[:upper:]' '[:lower:]' | tr -d ' ')
    
    if [ "$response" = "yes" ]; then
        print_colored "green" "Proceeding..."
        break
    elif [ "$response" = "no" ]; then
        print_colored "yellow" "You selected No. Asking again..."
    else
        print_colored "red" "Invalid input. Please enter 'yes' or 'no'."
    fi
done

print_colored "yellow" "Cleaning build directory..."
rm -rf build
mkdir -p build
cd build

print_colored "cyan" "Configuring with $selected_generator..."
cmake .. -G "$selected_generator"

print_colored "cyan" "Building..."
if [[ "$selected_generator" == "Ninja" ]]; then
    ninja
elif [[ "$selected_generator" == "Xcode" ]]; then
    xcodebuild -configuration Debug
else
    make
fi

print_colored "green" "Build complete!" 