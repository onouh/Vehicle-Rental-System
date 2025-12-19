# Contributing to Vehicle Rental System

Thank you for your interest in contributing! This guide will help you get started.

## Project Structure

```
Vehicle-Rental-System/
├── CMakeLists.txt          # CMake build configuration
├── .gitignore              # Git ignore rules
├── README.md               # Project overview
├── BUILD.md                # Build instructions
├── DESIGN.md               # Architecture documentation
├── USAGE.md                # User guide
├── CONTRIBUTING.md         # This file
│
├── Core Classes (Business Logic)
│   ├── Vehicle.h/.cpp      # Abstract base class
│   ├── Car.h/.cpp          # Car vehicle type
│   ├── Bike.h/.cpp         # Bike vehicle type
│   └── RentalManager.h/.cpp # Fleet management
│
├── GUI Classes (Presentation)
│   ├── MainWindow.h/.cpp   # Main application window
│   └── main.cpp            # Application entry point
```

## Getting Started

### Prerequisites

1. Qt6 development environment
2. C++17 compatible compiler
3. CMake 3.16+
4. Basic knowledge of Qt Widgets and C++ OOP

### Setting Up Development Environment

#### Ubuntu/Debian
```bash
sudo apt-get update
sudo apt-get install build-essential cmake qt6-base-dev libqt6widgets6 git
```

#### macOS
```bash
brew install qt@6 cmake
```

#### Windows
1. Install Qt from https://www.qt.io/download
2. Install CMake from https://cmake.org/download/
3. Install Visual Studio or MinGW

### Building for Development

```bash
git clone <repository-url>
cd Vehicle-Rental-System
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build .
```

## Code Style Guidelines

### C++ Style

- **Standard**: C++17 or higher
- **Indentation**: 4 spaces (no tabs)
- **Braces**: Opening brace on same line for functions
- **Naming Conventions**:
  - Classes: `PascalCase` (e.g., `RentalManager`)
  - Functions/Methods: `camelCase` (e.g., `addVehicle`)
  - Variables: `camelCase` (e.g., `baseRate`)
  - Constants: `UPPER_SNAKE_CASE` or `kPascalCase`
  - Private members: No prefix or underscore suffix

### Example

```cpp
class Vehicle {
private:
    int id;
    QString brand;
    
public:
    Vehicle(int id, const QString& brand);
    virtual ~Vehicle() = default;
    
    virtual double calculateCost(int days) const = 0;
    int getId() const { return id; }
};
```

### Qt Conventions

- Use Qt types when interfacing with Qt: `QString`, `QList`, etc.
- Use STL containers for internal logic: `std::vector`, `std::string`
- Follow Qt naming for slots and signals: `onActionName()`
- Use Qt parent-child relationship for widget memory management

## Adding New Features

### Adding a New Vehicle Type

1. Create new header file: `Truck.h`
```cpp
#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"

class Truck : public Vehicle {
private:
    int cargoCapacity;

public:
    Truck(int id, const QString& brand, const QString& model, 
          double baseRate, int cargoCapacity);
    
    double calculateCost(int days) const override;
    QString getType() const override;
    
    int getCargoCapacity() const { return cargoCapacity; }
};

#endif // TRUCK_H
```

2. Create implementation file: `Truck.cpp`
```cpp
#include "Truck.h"

Truck::Truck(int id, const QString& brand, const QString& model,
             double baseRate, int cargoCapacity)
    : Vehicle(id, brand, model, baseRate), cargoCapacity(cargoCapacity) {
}

double Truck::calculateCost(int days) const {
    return baseRate * days * 1.5; // Trucks cost 50% more
}

QString Truck::getType() const {
    return "Truck";
}
```

3. Update `CMakeLists.txt`:
```cmake
set(SOURCES
    main.cpp
    Vehicle.cpp
    Car.cpp
    Bike.cpp
    Truck.cpp  # Add this line
    RentalManager.cpp
    MainWindow.cpp
)

set(HEADERS
    Vehicle.h
    Car.h
    Bike.h
    Truck.h    # Add this line
    RentalManager.h
    MainWindow.h
)
```

4. Update `MainWindow.cpp` to add UI support for Truck type

### Adding a New Feature to RentalManager

Example: Add a search function

```cpp
// In RentalManager.h
std::vector<Vehicle*> searchByBrand(const QString& brand) const;

// In RentalManager.cpp
std::vector<Vehicle*> RentalManager::searchByBrand(const QString& brand) const {
    std::vector<Vehicle*> results;
    for (Vehicle* v : fleet) {
        if (v->getBrand() == brand) {
            results.push_back(v);
        }
    }
    return results;
}
```

### Adding a New UI View

1. Add new page to `MainWindow::setupUI()`
2. Create a method like `createNewView()`
3. Add button in sidebar to switch to new view
4. Connect button to show the new view

## Testing

### Manual Testing Checklist

- [ ] Add a new car
- [ ] Add a new bike
- [ ] Rent a vehicle
- [ ] Return a vehicle
- [ ] Remove a vehicle
- [ ] Test with empty fleet
- [ ] Test with many vehicles (50+)
- [ ] Test invalid inputs
- [ ] Test all navigation buttons

### Unit Testing (Recommended to Add)

Consider adding Google Test or Qt Test:

```cpp
// Example test
TEST(VehicleTest, CalculateCarCost) {
    Car car(1, "Toyota", "Camry", 50.0, 4);
    EXPECT_EQ(car.calculateCost(3), 150.0);
}
```

## Commit Guidelines

### Commit Message Format

```
<type>: <subject>

<body>

<footer>
```

### Types

- `feat`: New feature
- `fix`: Bug fix
- `docs`: Documentation changes
- `style`: Code style changes (formatting)
- `refactor`: Code refactoring
- `test`: Adding tests
- `chore`: Build process or auxiliary tool changes

### Examples

```
feat: Add Truck vehicle type

- Create Truck class inheriting from Vehicle
- Add cargo capacity attribute
- Implement cost calculation with 1.5x multiplier
- Update UI to support adding trucks

Closes #123
```

```
fix: Correct rent/return table refresh logic

Previously, the rent/return form was not properly updating
the status column after operations. Now it correctly refreshes
both the local table and the main dashboard.
```

## Pull Request Process

1. **Fork** the repository
2. **Create** a feature branch: `git checkout -b feature/amazing-feature`
3. **Commit** your changes: `git commit -m 'feat: Add amazing feature'`
4. **Push** to your fork: `git push origin feature/amazing-feature`
5. **Open** a Pull Request with description of changes
6. **Respond** to review feedback
7. **Merge** once approved

## Code Review Checklist

Before submitting a PR, ensure:

- [ ] Code compiles without warnings
- [ ] All features work as expected
- [ ] No memory leaks (check with valgrind if possible)
- [ ] Code follows project style guidelines
- [ ] Documentation is updated if needed
- [ ] Comments explain complex logic
- [ ] No debug code or TODO comments left
- [ ] CMakeLists.txt is updated if new files added

## Common Development Tasks

### Adding a New Attribute to Vehicle

1. Add to `Vehicle.h` class definition
2. Update constructor in `Vehicle.cpp`
3. Add getter/setter methods
4. Update derived classes as needed
5. Update UI to display/edit new attribute

### Changing the Color Scheme

Edit the QSS in `MainWindow::applyStyles()`:

```cpp
QString styleSheet = R"(
    QMainWindow {
        background-color: #1a1a1a;  // Change this
    }
    
    QPushButton {
        background-color: #ff6b6b;  // Change accent color
    }
    // ... more styles
)";
```

### Adding Persistence (Database)

1. Add Qt SQL module to `CMakeLists.txt`:
```cmake
find_package(Qt6 REQUIRED COMPONENTS Widgets Sql)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets Qt6::Sql)
```

2. Create database connection in `main.cpp`
3. Add save/load methods to `RentalManager`
4. Update UI to save on changes

## Debugging Tips

### Using Qt Creator

1. Open `CMakeLists.txt` in Qt Creator
2. Set breakpoints in code
3. Run in Debug mode (Ctrl+F5)
4. Inspect variables in debugger

### Command Line Debugging

```bash
# Build with debug symbols
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build .

# Run with gdb
gdb ./bin/VehicleRentalSystem
(gdb) break MainWindow::addVehicle
(gdb) run
```

### Memory Leak Detection

```bash
valgrind --leak-check=full ./bin/VehicleRentalSystem
```

## Resources

### Qt Documentation
- Qt6 Widgets: https://doc.qt.io/qt-6/qtwidgets-index.html
- Qt Style Sheets: https://doc.qt.io/qt-6/stylesheet.html
- Qt Layouts: https://doc.qt.io/qt-6/layout.html

### C++ Resources
- C++ Reference: https://en.cppreference.com/
- C++ Core Guidelines: https://isocpp.github.io/CppCoreGuidelines/

### CMake
- CMake Tutorial: https://cmake.org/cmake/help/latest/guide/tutorial/

## Getting Help

If you need help:

1. Check existing documentation (README, BUILD, DESIGN, USAGE)
2. Search Qt documentation
3. Open an issue on GitHub
4. Ask in the project's discussion forum

## License

By contributing, you agree that your contributions will be licensed under the same license as the project.

---

Thank you for contributing to Vehicle Rental System!
