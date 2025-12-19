# Vehicle Rental System - Build Instructions

## Prerequisites

To build and run this project, you need:

1. **C++17 or higher compiler** (GCC 7+, Clang 5+, MSVC 2017+)
2. **CMake 3.16 or higher**
3. **Qt6 with Widgets module**

## Installing Qt6

### Ubuntu/Debian
```bash
sudo apt-get update
sudo apt-get install qt6-base-dev libqt6widgets6
```

### macOS (using Homebrew)
```bash
brew install qt@6
```

### Windows
Download and install Qt from: https://www.qt.io/download

## Building the Project

1. Create a build directory:
```bash
mkdir build
cd build
```

2. Configure with CMake:
```bash
cmake ..
```

If Qt6 is installed in a custom location, you may need to specify the Qt path:
```bash
cmake -DCMAKE_PREFIX_PATH=/path/to/Qt/6.x.x/gcc_64 ..
```

3. Build the project:
```bash
cmake --build .
```

4. Run the application:
```bash
./bin/VehicleRentalSystem
```

## Project Structure

```
Vehicle-Rental-System/
├── CMakeLists.txt          # Build configuration
├── Vehicle.h/cpp           # Abstract base class
├── Car.h/cpp               # Car derived class
├── Bike.h/cpp              # Bike derived class
├── RentalManager.h/cpp     # Fleet management logic
├── MainWindow.h/cpp        # Qt GUI implementation
├── main.cpp                # Application entry point
└── BUILD.md                # This file
```

## Features

- **Object-Oriented Design**: Abstract Vehicle base class with Car and Bike derived classes
- **Fleet Management**: Add, remove, rent, and return vehicles
- **Modern Qt6 GUI**: 
  - Dark theme with custom QSS styling
  - Sidebar navigation with Dashboard, Add Vehicle, and Rent/Return views
  - QTableWidget for vehicle display
  - QFormLayout for input forms
- **C++17 Standard**: Uses modern C++ features including std::vector and polymorphism

## Troubleshooting

### Qt6 not found
If CMake cannot find Qt6, set the CMAKE_PREFIX_PATH:
```bash
export CMAKE_PREFIX_PATH=/path/to/Qt/6.x.x/gcc_64
```

### Build errors
Make sure you have:
- A C++17 compatible compiler
- Qt6 Widgets module installed
- CMake 3.16 or higher

## Technical Details

### Architecture
- **Language**: C++17
- **Framework**: Qt6 Widgets Module
- **Build System**: CMake
- **Design Pattern**: Polymorphism with abstract base classes

### Class Hierarchy
```
Vehicle (abstract)
├── Car (adds numDoors)
└── Bike (adds engineCapacity)

RentalManager
└── std::vector<Vehicle*> fleet
```

### GUI Components
- **QMainWindow**: Main application window
- **QStackedWidget**: Multiple view container
- **QTableWidget**: Vehicle fleet display
- **QFormLayout**: Input forms
- **QSS Styling**: Modern dark theme
