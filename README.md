# Vehicle Rental System

A modern C++ application built with Qt6 for managing a vehicle rental fleet.

## Overview

This is a complete Vehicle Rental System featuring:
- **Modern C++17 OOP design** with abstract base classes and polymorphism
- **Qt6 Widgets GUI** with a professional dark theme
- **Fleet management** for cars and bikes
- **Rental operations** for renting and returning vehicles

## GUI Preview

**[📸 View GUI Screenshots and Details →](GUI_SHOWCASE.md)**

See complete screenshots and detailed documentation of all GUI views including the Dashboard, Add Vehicle form, and Rent/Return interface.

## Quick Start

See [BUILD.md](BUILD.md) for detailed build instructions.

```bash
mkdir build && cd build
cmake ..
cmake --build .
./bin/VehicleRentalSystem
```

## Features

### Core Functionality
- Add new vehicles (Cars and Bikes) to the fleet
- Remove vehicles from the fleet
- Rent available vehicles
- Return rented vehicles
- View vehicle status and details

### Technical Highlights
- **Abstract base class** `Vehicle` with pure virtual functions
- **Derived classes** `Car` (with number of doors) and `Bike` (with engine capacity)
- **RentalManager** class using `std::vector<Vehicle*>` for polymorphic fleet management
- **Modern Qt6 GUI** with QStackedWidget, QTableWidget, and custom QSS styling
- **Dark theme** with rounded corners, accent colors, and professional appearance

## Architecture

```
Vehicle (abstract base class)
├── calculateCost(int days) - pure virtual
├── getType() - pure virtual
└── Attributes: id, brand, model, baseRate, isRented

Car : Vehicle
└── Additional: numDoors

Bike : Vehicle
└── Additional: engineCapacity

RentalManager
├── std::vector<Vehicle*> fleet
├── addVehicle()
├── removeVehicle()
├── rentVehicle()
└── returnVehicle()

MainWindow : QMainWindow
├── Dashboard view (vehicle table)
├── Add Vehicle form
└── Rent/Return interface
```

## Requirements

- C++17 or higher
- Qt6 (Widgets module)
- CMake 3.16+

## License

This project is provided as-is for educational purposes.
