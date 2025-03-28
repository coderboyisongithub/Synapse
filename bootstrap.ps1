# Define the local vcpkg directory within the cloned repository
$vcpkgDir = "$PSScriptRoot\vcpkg"
$vcpkgExe = "$vcpkgDir\vcpkg.exe"

# Check if Ninja is installed
$ninjaExe = (Get-Command ninja -ErrorAction SilentlyContinue).Source
if (-not $ninjaExe) {
    Write-Host "Ninja not found! Installing using winget..." -ForegroundColor Yellow
    winget install Ninja-build.Ninja --silent
    $env:Path = [System.Environment]::GetEnvironmentVariable("Path", "Machine") + ";" + [System.Environment]::GetEnvironmentVariable("Path", "User")
    $ninjaExe = (Get-Command ninja -ErrorAction SilentlyContinue).Source
    if (-not $ninjaExe) {
        Write-Host "Ninja installation failed!" -ForegroundColor Red
        exit 1
    }
}

# Ninja,vcpkg
# Check if vcpkg is available in the system environment
$vcpkgSystemPath = (Get-Command vcpkg -ErrorAction SilentlyContinue).Source

if ($vcpkgSystemPath) 
{
    Write-Host "System-wide vcpkg found: $vcpkgSystemPath" 
} 
elseif (Test-Path $vcpkgExe)
{
    Write-Host "Local vcpkg found: $vcpkgExe"
} 
else 
{
    Write-Host "vcpkg not found. Installing locally..." -ForegroundColor Yellow
    
    # Clone the vcpkg repository
    Write-Host "Cloning vcpkg repository..."
    git clone https://github.com/microsoft/vcpkg.git $vcpkgDir
    
    if (!(Test-Path $vcpkgDir)) {
        Write-Host "Failed to clone vcpkg repository." -ForegroundColor Red
        exit 1
    }
    
    # Run the bootstrap script to build vcpkg
    Write-Host "Bootstrapping vcpkg..."
    & "$vcpkgDir\bootstrap-vcpkg.bat"
    
    if (Test-Path $vcpkgExe) 
    {
        Write-Host "vcpkg installation completed successfully." -ForegroundColor Green
        # Add vcpkg to the environment PATH (only for this session)
        $env:PATH = "$vcpkgDir;$env:PATH"
        Write-Host "vcpkg set for local path env var" 
    } else {
        Write-Host "vcpkg installation failed." -ForegroundColor Red
        exit 1
    }

    Write-Host "Installing dependency" -ForegroundColor Yellow
    & vcpkg install 
}

# vcpkg section up.

Write-Host "Performing Cmake Configuration" -ForegroundColor Yellow
# Check if CMake is installed
$cmakeExe = (Get-Command cmake -ErrorAction SilentlyContinue).Source

if (-not $cmakeExe) 
{
    Write-Host "CMake not found! Installing using winget..." -ForegroundColor Yellow

    # Install CMake using winget
    winget install Kitware.CMake --silent

    # Refresh the environment to detect CMake
    $env:Path = [System.Environment]::GetEnvironmentVariable("Path", "Machine") + ";" + [System.Environment]::GetEnvironmentVariable("Path", "User")
    $cmakeExe = (Get-Command cmake -ErrorAction SilentlyContinue).Source

    if (-not $cmakeExe) {
        Write-Host "CMake installation failed!" -ForegroundColor Red
        exit 1
    }
}

# Run CMake to list available generators
$cmakeGenerators = & cmake --help | Select-String "Generators" -Context 0,50 | Out-String
Write-Host "Available CMake Generators: $cmakeGenerators" 

Write-Host "switching to build directory" -ForegroundColor DarkYellow
& mkdir build -ErrorAction ignore
& cd build 

$selected_generator=Read-Host "copy and paste the genrator from the list"

Write-host "selected generator is: $selected_generator" -BackgroundColor Cyan
do {
    # Prompt user for input
    $response = Read-Host "Do you want to continue? (yes/no)"

    # Convert input to lowercase for case-insensitive comparison
    $response = $response.Trim().ToLower()

    if ($response -eq "yes") {
        Write-Host "Proceeding..." -ForegroundColor Green
        break  # Exit loop
    }
    elseif ($response -eq "no") {
        Write-Host "You selected No. Asking again..." -ForegroundColor Yellow
    }
    else {
        Write-Host "Invalid input. Please enter 'yes' or 'no'." -ForegroundColor Red
    }

} while ($true)  # Infinite loop until 'yes' is entered
 
& cmake ../synapse -G $selected_generator
& ninja
& .\bin\Synapse.exe 