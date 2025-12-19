# Vehicle Rental System - Complete MVC Implementation

## 🚗 Overview

A full-featured **Vehicle Rental System** built with **C++17**, **Qt6**, and **SQLite** database, following the **MVC (Model-View-Controller)** architecture pattern.

![Login Screen](https://github.com/user-attachments/assets/82c9174c-46a2-44e1-a933-813016d033e2)
![Dashboard](https://github.com/user-attachments/assets/15386fdf-10f1-4476-bdd9-5e184472c5db)
![Add Vehicle Form](https://github.com/user-attachments/assets/caccc3e4-1bd9-4c20-8ce6-3eb41a48a767)

## ✨ Key Features

### 🔐 Authentication & Security
- Login System with username/password authentication
- User Registration with role assignment (Admin/Customer)
- **SHA-256 Password Hashing** for security
- Role-Based Access Control
- Default users: `admin`/`admin123`, `customer`/`customer123`

### 🗄️ Database Layer (SQLite)
- **DatabaseManager Singleton** - Centralized database operations
- Three-table schema: Users, Vehicles, Reservations
- Automatic schema creation on first run
- Foreign key constraints for data integrity
- 7 sample vehicles pre-populated

### 🚙 Vehicle Management
- Add/Remove vehicles (Cars and Bikes)
- View complete vehicle fleet
- Search and filter by type, brand, model, status
- Real-time status tracking (available/rented)
- Database-backed persistence

### 📅 Reservation System
- Create and manage reservations
- Track status (active/completed/cancelled)
- Automatic cost calculation: `rate × days`
- Check availability before booking

### 🎨 Modern Dark Theme UI
- Professional QSS styling
- Sidebar navigation
- Multiple views: Dashboard, Add Vehicle, Reservations, Customers
- Responsive tables and forms

## 🏗️ MVC Architecture

```
VIEW (Qt6 GUI)
    ↕
CONTROLLER (AuthManager, RentalManager)
    ↕
MODEL (DatabaseManager, Entities)
```

## 🛠️ Technical Stack

- **Language**: C++17
- **GUI**: Qt6 (Widgets + Sql modules)
- **Database**: SQLite
- **Build**: CMake 3.16+
- **Patterns**: MVC, Singleton
- **Security**: SHA-256 hashing

## 📦 Quick Start

```bash
# Build
mkdir build && cd build
cmake ..
cmake --build .

# Run
./bin/VehicleRentalSystem
```

## 🗃️ Database Schema

### Users
- id, username, password (hashed), role, contact_info, license_number

### Vehicles
- id, brand, model, category, daily_rate, status

### Reservations
- id, user_id, vehicle_id, start_date, end_date, total_cost, status

## 📂 Key Files

- `DatabaseManager.h/cpp` - Database singleton
- `AuthManager.h/cpp` - Authentication controller
- `RentalManager.h/cpp` - Business logic
- `LoginWindow.h/cpp` - Login view
- `MainWindow.h/cpp` - Main dashboard
- `User.h/cpp`, `Vehicle.h/cpp` - Data models

## ✅ Requirements Implemented

✓ C++17 with Qt6  
✓ SQLite database (QSqlDatabase, QSqlQuery)  
✓ MVC architecture  
✓ DatabaseManager singleton with all CRUD methods  
✓ Three tables: Users, Vehicles, Reservations  
✓ AuthManager with password hashing  
✓ RentalManager with cost calculation  
✓ LoginWindow with authentication  
✓ MainWindow with multiple views  
✓ Dark theme styling (QSS)  
✓ CMakeLists.txt with Qt6::Sql  

## 🔒 Security

- SHA-256 password hashing
- Prepared SQL statements (injection prevention)
- Input validation
- CodeQL scan: **0 vulnerabilities**

## 📝 Documentation

### GUI Documentation
- **`GUI_COMPLETE_REFERENCE.md`** - Your complete navigation guide to all GUI resources
- **`COMPLETE_GUI_SHOWCASE.md`** - Full visual guide with ASCII diagrams of all windows
- `GUI_SHOWCASE.md` - Original GUI overview with screenshots
- `CUSTOMER_GUI.md` - Customer management feature details
- `SEARCH_VISUAL_GUIDE.md` - Search feature examples and demos

### Technical Documentation
- `DATABASE_GUIDE.md` - Complete database documentation
- `DESIGN.md` - Architecture and design decisions
- `ARCHITECTURE.txt` - System architecture overview
- `sample_data.sql` - Sample data initialization script
- Inline code comments

## 🧪 Tested

✓ Database initialization  
✓ User authentication  
✓ Vehicle CRUD operations  
✓ Code review passed  
✓ Security scan passed  
✓ No memory leaks  

## 📸 Screenshots & GUI Documentation

See images above for Login, Dashboard, and Add Vehicle views.

### 🎨 Complete GUI Reference

**Want to see ALL GUI windows with detailed visual guides?**

📖 **[GUI_COMPLETE_REFERENCE.md](GUI_COMPLETE_REFERENCE.md)** - Your comprehensive navigation guide to all GUI documentation

### 👤 Role-Specific GUI Documentation

📋 **[ADMIN_GUI_SCREENSHOT.md](ADMIN_GUI_SCREENSHOT.md)** - Complete Admin interface documentation:
- Login Window for Admin
- Dashboard with Full Fleet Management
- Add Vehicle Form (Cars & Bikes)
- Rent/Return Interface
- Customer Management
- Reservations View
- All Admin Features & Capabilities

👥 **[CUSTOMER_GUI_SCREENSHOT.md](CUSTOMER_GUI_SCREENSHOT.md)** - Complete Customer interface documentation:
- Login Window for Customer
- Dashboard for Browsing Vehicles
- Add Your Own Vehicle
- Rent/Return Interface
- Customer Directory
- Personal Reservations
- Customer Workflow Examples

📋 **[COMPLETE_GUI_SHOWCASE.md](COMPLETE_GUI_SHOWCASE.md)** - Complete ASCII art diagrams of all windows including:
- Login Window (Admin & Customer)
- Dashboard with Search & Filters
- Add Vehicle Form (Cars & Bikes)
- Rent/Return Interface
- Customer Management
- Reservations View
- Complete User Workflows
- Role Comparisons (Admin vs Customer)

**All features documented with detailed visual examples!**

---

**Complete MVC implementation with Qt6 and SQL database following all specified requirements.**
