# Vehicle Rental System - MVC Architecture with SQL Database

## Overview

This is a fully functional Vehicle Rental System built with **C++17**, **Qt6**, and **SQLite** database, following the **MVC (Model-View-Controller)** architecture pattern.

## Features

### 1. Authentication System
- **Login Window** with username/password authentication
- **Registration** dialog for new users
- **Password Hashing** using SHA-256 for security
- **Role-based Access** (Admin and Customer roles)

### 2. Database Layer (Model)
- **SQLite Database** with three main tables:
  - `Users` - User authentication and profile information
  - `Vehicles` - Vehicle inventory management
  - `Reservations` - Rental reservations and history
- **DatabaseManager** - Singleton class for all database operations
- Automatic schema creation on first run

### 3. User Management
- Default users created automatically:
  - **Admin**: username: `admin`, password: `admin123`
  - **Customer**: username: `customer`, password: `customer123`
- Add new users via registration

### 4. Vehicle Management
- Add vehicles (Cars and Bikes)
- Remove vehicles
- View all vehicles in the fleet
- Search and filter vehicles
- Track vehicle status (available/rented)

### 5. Reservation System
- Create new reservations
- View all reservations
- Track reservation status (active/completed/cancelled)
- Calculate total costs based on daily rates

### 6. Modern UI
- **Dark Theme** with professional styling
- Sidebar navigation
- Multiple views: Dashboard, Add Vehicle, Rent/Return, Manage Customers, Reservations
- Responsive tables and forms

## Architecture

### MVC Pattern Implementation

```
┌─────────────────────────────────────────────────────────┐
│                    VIEW LAYER (Qt6 GUI)                 │
│  ┌──────────────┐  ┌──────────────┐  ┌──────────────┐ │
│  │ LoginWindow  │  │ MainWindow   │  │ Dialogs      │ │
│  └──────────────┘  └──────────────┘  └──────────────┘ │
└─────────────────────────────────────────────────────────┘
                            │
                            ▼
┌─────────────────────────────────────────────────────────┐
│              CONTROLLER LAYER (Logic)                   │
│  ┌──────────────┐  ┌──────────────┐                    │
│  │ AuthManager  │  │RentalManager │                    │
│  └──────────────┘  └──────────────┘                    │
└─────────────────────────────────────────────────────────┘
                            │
                            ▼
┌─────────────────────────────────────────────────────────┐
│         MODEL LAYER (Database & Data Classes)           │
│  ┌──────────────┐  ┌──────────────┐  ┌──────────────┐ │
│  │DatabaseMgr   │  │    User      │  │  Vehicle     │ │
│  │ (Singleton)  │  │   Customer   │  │ Reservation  │ │
│  └──────────────┘  └──────────────┘  └──────────────┘ │
└─────────────────────────────────────────────────────────┘
```

## Building the Project

### Prerequisites
- CMake 3.16+
- C++17 compiler (GCC, Clang, or MSVC)
- Qt6 (with Widgets and Sql modules)

### Build Steps

```bash
# Create build directory
mkdir build && cd build

# Configure with CMake
cmake ..

# Build
cmake --build .

# Run
./bin/VehicleRentalSystem
```

## Database Schema

### Users Table
```sql
CREATE TABLE Users (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    username TEXT UNIQUE NOT NULL,
    password TEXT NOT NULL,           -- SHA-256 hashed
    role TEXT NOT NULL,                -- "admin" or "customer"
    contact_info TEXT,
    license_number TEXT
);
```

### Vehicles Table
```sql
CREATE TABLE Vehicles (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    brand TEXT NOT NULL,
    model TEXT NOT NULL,
    category TEXT NOT NULL,            -- "Car" or "Bike"
    daily_rate REAL NOT NULL,
    status TEXT NOT NULL               -- "available" or "rented"
);
```

### Reservations Table
```sql
CREATE TABLE Reservations (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    user_id INTEGER NOT NULL,
    vehicle_id INTEGER NOT NULL,
    start_date TEXT NOT NULL,
    end_date TEXT NOT NULL,
    total_cost REAL NOT NULL,
    status TEXT NOT NULL,              -- "active", "completed", "cancelled"
    FOREIGN KEY (user_id) REFERENCES Users(id),
    FOREIGN KEY (vehicle_id) REFERENCES Vehicles(id)
);
```

## Key Classes

### DatabaseManager (Singleton)
- `getInstance()` - Get singleton instance
- `initializeDatabase()` - Initialize database and create tables
- `authenticateUser()` - Verify user credentials
- `addVehicle()`, `removeVehicle()`, `getAllVehicles()` - Vehicle CRUD
- `createReservation()`, `getReservationsByUserId()` - Reservation management

### AuthManager
- `login()` - Authenticate user
- `logout()` - Clear current session
- `registerUser()` - Register new user
- `hashPassword()` - Hash password with SHA-256

### RentalManager
- Vehicle fleet management
- Customer management
- Integration with DatabaseManager

### LoginWindow
- User login interface
- Registration dialog
- Dark theme styling

### MainWindow
- Multi-view dashboard
- Vehicle management
- Customer management
- Reservations view

## Usage

1. **Start Application**: The login window appears automatically
2. **Login**: Use default credentials or register a new user
3. **Dashboard**: View all vehicles in the database
4. **Add Vehicle**: Navigate to "Add Vehicle" to add new vehicles
5. **Reservations**: Click "Reservations" to view all rental records
6. **Manage Customers**: Add and manage customer profiles

## Technical Highlights

- ✅ **MVC Architecture** - Clear separation of concerns
- ✅ **Singleton Pattern** - DatabaseManager ensures single database connection
- ✅ **SQL Database** - Persistent storage with SQLite
- ✅ **Security** - Password hashing with SHA-256
- ✅ **Modern C++17** - Using latest C++ features
- ✅ **Qt6 Framework** - Cross-platform GUI
- ✅ **Dark Theme** - Professional QSS styling
- ✅ **Error Handling** - Comprehensive error checking
- ✅ **Memory Management** - Proper cleanup and no leaks

## Sample Data

The system comes pre-populated with:
- 2 default users (admin and customer)
- 5 sample vehicles (3 cars, 2 bikes)

## Files Structure

```
Vehicle-Rental-System/
├── CMakeLists.txt           # Build configuration
├── main.cpp                 # Application entry point
├── DatabaseManager.h/cpp    # Database layer (Singleton)
├── AuthManager.h/cpp        # Authentication controller
├── RentalManager.h/cpp      # Business logic controller
├── LoginWindow.h/cpp        # Login view
├── MainWindow.h/cpp         # Main dashboard view
├── User.h/cpp               # User model
├── Vehicle.h/cpp            # Vehicle base model
├── Car.h/cpp                # Car model (inherits Vehicle)
├── Bike.h/cpp               # Bike model (inherits Vehicle)
└── Customer.h/cpp           # Customer model
```

## License

This is a demonstration project showcasing MVC architecture with Qt6 and SQL database.
