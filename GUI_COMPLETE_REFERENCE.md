# Complete GUI Reference - Vehicle Rental System

**Your comprehensive guide to all GUI windows, features, and screenshots**

---

## 🎯 Quick Navigation

| Resource | Description | Link |
|----------|-------------|------|
| **Complete GUI Showcase** | Full ASCII art diagrams of ALL windows | [COMPLETE_GUI_SHOWCASE.md](COMPLETE_GUI_SHOWCASE.md) |
| **Admin GUI Screenshots** ⭐ | Complete Admin interface documentation | [ADMIN_GUI_SCREENSHOT.md](ADMIN_GUI_SCREENSHOT.md) |
| **Customer GUI Screenshots** ⭐ | Complete Customer interface documentation | [CUSTOMER_GUI_SCREENSHOT.md](CUSTOMER_GUI_SCREENSHOT.md) |
| **GUI Showcase (Original)** | Overview with screenshot references | [GUI_SHOWCASE.md](GUI_SHOWCASE.md) |
| **Customer GUI Details** | Customer management feature docs | [CUSTOMER_GUI.md](CUSTOMER_GUI.md) |
| **Search Visual Guide** | Search feature detailed documentation | [SEARCH_VISUAL_GUIDE.md](SEARCH_VISUAL_GUIDE.md) |
| **Search Feature** | Search implementation details | [SEARCH_FEATURE.md](SEARCH_FEATURE.md) |

---

## 📸 Actual Screenshots

The following PNG screenshots are available in the `docs/` folder:

1. **Dashboard View** - `docs/gui_dashboard.png`
   - Shows the main vehicle fleet table
   - Search bar with filters
   - Refresh and Remove buttons

2. **Add Vehicle Form** - `docs/gui_add_vehicle.png`
   - Vehicle type selector
   - Input fields for car/bike details
   - Add vehicle button

3. **Rent/Return Interface** - `docs/gui_rent_return.png`
   - Vehicle selection table
   - Rent and Return buttons
   - Status indicators

---

## 🖥️ All GUI Windows Overview

### 1. Authentication
- **Login Window** - Secure login with admin/customer roles
  - Default Admin: `admin` / `admin123`
  - Default Customer: `customer` / `customer123`
  - SHA-256 password hashing
  - User registration feature

### 2. Main Windows (5 Total)

#### Window 1: Dashboard (Vehicle Fleet)
- **Purpose**: View and search all vehicles
- **Features**:
  - Real-time search with 6 filter options (All, ID, Type, Brand, Model, Status)
  - Case-insensitive filtering
  - Vehicle table with 6 columns (ID, Type, Brand, Model, Rate/Day, Status)
  - Refresh and Remove buttons
  - Row selection and sorting
- **Access**: Both Admin and Customer
- **Documentation**: [COMPLETE_GUI_SHOWCASE.md#3-dashboard](COMPLETE_GUI_SHOWCASE.md)

#### Window 2: Add Vehicle
- **Purpose**: Add new cars or bikes to the fleet
- **Features**:
  - Vehicle type dropdown (Car/Bike)
  - Brand, Model, and Rate inputs
  - Dynamic fields based on type:
    - Cars: Number of Doors (2-5)
    - Bikes: Engine Capacity (50-2000 cc)
  - Input validation
  - Success confirmation
- **Access**: Admin only
- **Documentation**: [COMPLETE_GUI_SHOWCASE.md#4-add-vehicle-form](COMPLETE_GUI_SHOWCASE.md)

#### Window 3: Rent/Return
- **Purpose**: Manage vehicle rental operations
- **Features**:
  - View all vehicles with current status
  - Rent available vehicles
  - Return rented vehicles
  - Real-time status updates
  - Confirmation dialogs
- **Access**: Both Admin and Customer
- **Documentation**: [COMPLETE_GUI_SHOWCASE.md#5-rentreturn-interface](COMPLETE_GUI_SHOWCASE.md)

#### Window 4: Manage Customers
- **Purpose**: Customer database management
- **Features**:
  - Add new customers (Name, Email, Phone)
  - View customer list table
  - Remove customers with confirmation
  - Automatic ID assignment
  - Input validation
- **Access**: Admin only
- **Documentation**: [COMPLETE_GUI_SHOWCASE.md#6-customer-management](COMPLETE_GUI_SHOWCASE.md)

#### Window 5: Reservations
- **Purpose**: View and track all reservations
- **Features**:
  - Display all reservations from database
  - Show user ID, vehicle ID, dates, cost, status
  - Automatic cost calculation
  - Status tracking (active/completed/cancelled)
  - Refresh functionality
- **Access**: 
  - Admin: View ALL reservations
  - Customer: View ONLY own reservations
- **Documentation**: [COMPLETE_GUI_SHOWCASE.md#7-reservations-view](COMPLETE_GUI_SHOWCASE.md)

---

## 👥 User Roles Comparison

| Feature | Admin | Customer |
|---------|-------|----------|
| **Login** | ✅ admin/admin123 | ✅ customer/customer123 |
| **View Dashboard** | ✅ Full access | ✅ Read-only |
| **Search Vehicles** | ✅ All filters | ✅ All filters |
| **Add Vehicles** | ✅ Yes | ❌ No |
| **Remove Vehicles** | ✅ Yes | ❌ No |
| **Rent Vehicles** | ✅ Yes | ✅ Yes |
| **Return Vehicles** | ✅ Yes | ✅ Yes |
| **Manage Customers** | ✅ Full CRUD | ❌ No access |
| **View Reservations** | ✅ All reservations | ✅ Own only |

**See detailed comparison**: [COMPLETE_GUI_SHOWCASE.md#8-user-roles](COMPLETE_GUI_SHOWCASE.md)

---

## 🔍 Search & Filter Feature

### Search Capabilities

The dashboard includes a powerful search system:

```
Search: [Enter text...] [Filter ▼]
```

### Filter Options:
1. **All** - Search across ID, Type, Brand, Model, Status
2. **ID** - Find vehicle by ID number
3. **Type** - Filter by Car or Bike
4. **Brand** - Filter by manufacturer
5. **Model** - Filter by model name
6. **Status** - Filter by Available or Rented

### Example Searches:

#### Find all Toyotas:
```
Search: [toyota] [Brand ▼]
Result: Shows only Toyota vehicles
```

#### Find all available bikes:
```
Search: [bike] [Type ▼]
Then filter by: [available] [Status ▼]
Result: Shows only available bikes
```

#### Find vehicle by ID:
```
Search: [5] [ID ▼]
Result: Shows vehicle with ID 5
```

**See detailed examples**: [SEARCH_VISUAL_GUIDE.md](SEARCH_VISUAL_GUIDE.md)

---

## 🎨 Design & Styling

### Color Scheme (Dark Theme)

| Element | Color | Hex Code |
|---------|-------|----------|
| Background | Dark Gray | `#2b2b2b` |
| Sidebar | Very Dark Gray | `#1e1e1e` |
| Input Fields | Medium Dark Gray | `#353535` |
| Borders | Gray | `#3d3d3d` |
| Accent | Slate Purple | `#6a5acd` |
| Accent Hover | Light Purple | `#7b6bd8` |
| Text | White | `#ffffff` |
| Remove Button | Red | `#d32f2f` |

### UI Components:
- **Sidebar**: Fixed 200px width
- **Buttons**: Rounded corners (5px radius)
- **Tables**: Sortable columns, purple selection highlight
- **Forms**: Purple focus borders
- **Dialogs**: Centered, modal confirmations

**Full styling details**: [COMPLETE_GUI_SHOWCASE.md](COMPLETE_GUI_SHOWCASE.md)

---

## 🔄 Complete User Workflows

### Workflow 1: Admin Adding a Vehicle
```
Login as Admin → Add Vehicle → Fill Form → Submit → Success
                                              ↓
                                    Vehicle appears in Dashboard
```
[View detailed steps](COMPLETE_GUI_SHOWCASE.md#workflow-1-admin-adding-a-new-vehicle)

### Workflow 2: Customer Renting a Vehicle
```
Login as Customer → Dashboard → Search for vehicle → Rent/Return
                                                          ↓
                                         Select vehicle → Rent → Confirm
                                                          ↓
                                                  Status: Available → Rented
```
[View detailed steps](COMPLETE_GUI_SHOWCASE.md#workflow-2-customer-renting-a-vehicle)

### Workflow 3: Searching and Reviewing Cars
```
Dashboard → Search bar → Select filter → Enter term → View results
                                                          ↓
                                            Review vehicle details
                                            • Brand, Model, Type
                                            • Daily rate
                                            • Availability status
```
[View detailed steps](COMPLETE_GUI_SHOWCASE.md#workflow-3-searching-and-reviewing-vehicles)

### Workflow 4: Managing Customers (Admin)
```
Login as Admin → Manage Customers → Add Customer → Fill details → Submit
                                                          ↓
                                            Customer appears in list
                                                          ↓
                                    Select customer → Remove → Confirm
```
[View detailed steps](COMPLETE_GUI_SHOWCASE.md#workflow-4-managing-customers-admin-only)

### Workflow 5: Viewing Reservations
```
Login → Reservations → View list
                          ↓
              Admin sees: ALL reservations
              Customer sees: ONLY own reservations
                          ↓
              Review: dates, costs, status
```
[View detailed steps](COMPLETE_GUI_SHOWCASE.md#workflow-5-viewing-reservations)

---

## 🛠️ Technical Implementation

### Frontend Framework
- **Qt6 Widgets** - Modern C++ GUI framework
- **QStackedWidget** - Multiple view management
- **QTableWidget** - Dynamic data tables
- **QLineEdit + QComboBox** - Search functionality
- **QSS Styling** - CSS-like custom themes

### Backend Architecture
- **Language**: C++17
- **Database**: SQLite with QSqlDatabase
- **Pattern**: MVC (Model-View-Controller)
- **Security**: SHA-256 password hashing
- **Singleton**: DatabaseManager for connection pooling

### Database Schema
```sql
Users Table:
  id, username, password (hashed), role, contact_info, license_number

Vehicles Table:
  id, brand, model, category, daily_rate, status

Reservations Table:
  id, user_id, vehicle_id, start_date, end_date, total_cost, status
```

### Key Classes
- `LoginWindow` - Authentication UI
- `MainWindow` - Main application window
- `AuthManager` - User authentication logic
- `RentalManager` - Business logic for rentals
- `DatabaseManager` - Singleton database access
- `Vehicle/Car/Bike` - Data models
- `User` - User data model
- `Customer` - Customer data model

---

## 📚 Documentation Index

### Getting Started
1. [README.md](README.md) - Project overview
2. [QUICKSTART.md](QUICKSTART.md) - 5-minute setup guide
3. [BUILD.md](BUILD.md) - Build instructions

### GUI Documentation
1. **[COMPLETE_GUI_SHOWCASE.md](COMPLETE_GUI_SHOWCASE.md)** ⭐ **START HERE**
   - Complete visual guide with ASCII diagrams
   - All windows and features
   - User workflows
   - Role comparisons

2. **[ADMIN_GUI_SCREENSHOT.md](ADMIN_GUI_SCREENSHOT.md)** ⭐ **NEW**
   - Complete Admin role interface
   - All admin-accessible views
   - Admin-specific features
   - Full capabilities overview
   
3. **[CUSTOMER_GUI_SCREENSHOT.md](CUSTOMER_GUI_SCREENSHOT.md)** ⭐ **NEW**
   - Complete Customer role interface
   - Customer-accessible views
   - Rental workflows
   - Customer capabilities overview
   
4. [GUI_SHOWCASE.md](GUI_SHOWCASE.md)
   - Original GUI overview
   - Links to actual screenshots
   
5. [CUSTOMER_GUI.md](CUSTOMER_GUI.md)
   - Customer management feature
   - Technical implementation
   
6. [SEARCH_VISUAL_GUIDE.md](SEARCH_VISUAL_GUIDE.md)
   - Search feature examples
   - Filter demonstrations
   
7. [SEARCH_FEATURE.md](SEARCH_FEATURE.md)
   - Search implementation details

### Technical Documentation
1. [DATABASE_GUIDE.md](DATABASE_GUIDE.md) - Database schema and queries
2. [DESIGN.md](DESIGN.md) - Architecture and design decisions
3. [ARCHITECTURE.txt](ARCHITECTURE.txt) - System architecture
4. [IMPLEMENTATION_STATUS.md](IMPLEMENTATION_STATUS.md) - Feature status
5. [IMPLEMENTATION_SUMMARY.md](IMPLEMENTATION_SUMMARY.md) - Implementation notes

### Development Guides
1. [CONTRIBUTING.md](CONTRIBUTING.md) - Contribution guidelines
2. [USAGE.md](USAGE.md) - User manual

---

## 🚀 Quick Start

### 1. Install Dependencies
```bash
# Ubuntu/Debian
sudo apt-get install qt6-base-dev libqt6widgets6 cmake

# macOS
brew install qt@6 cmake
```

### 2. Build Application
```bash
mkdir build && cd build
cmake ..
cmake --build .
```

### 3. Run Application
```bash
./bin/VehicleRentalSystem
```

### 4. Login
```
Admin:
  Username: admin
  Password: admin123

Customer:
  Username: customer
  Password: customer123
```

### 5. Explore All Windows
1. ✅ Dashboard - Browse and search vehicles
2. ✅ Add Vehicle - Add new cars/bikes (admin only)
3. ✅ Rent/Return - Manage rentals
4. ✅ Manage Customers - Customer database (admin only)
5. ✅ Reservations - View rental history

---

## 📖 How to Use This Reference

### For Visual Learners:
1. Start with **[COMPLETE_GUI_SHOWCASE.md](COMPLETE_GUI_SHOWCASE.md)** for ASCII diagrams
2. View actual screenshots in `docs/` folder
3. Follow workflows section for step-by-step guides

### For Developers:
1. Read [DESIGN.md](DESIGN.md) for architecture
2. Check [DATABASE_GUIDE.md](DATABASE_GUIDE.md) for schema
3. Review [IMPLEMENTATION_STATUS.md](IMPLEMENTATION_STATUS.md) for features

### For Users:
1. Follow [QUICKSTART.md](QUICKSTART.md) for setup
2. Use [USAGE.md](USAGE.md) for user manual
3. Try workflows in [COMPLETE_GUI_SHOWCASE.md](COMPLETE_GUI_SHOWCASE.md)

### For Understanding Roles:
1. Review role comparison table in this document
2. See [COMPLETE_GUI_SHOWCASE.md#8](COMPLETE_GUI_SHOWCASE.md) for details
3. Test both admin and customer accounts

---

## ✨ Features Summary

### Authentication & Security
✅ Secure login with SHA-256 hashing
✅ Role-based access control (Admin/Customer)
✅ User registration
✅ SQL injection prevention

### Vehicle Management
✅ Add/Remove vehicles (Admin)
✅ View vehicle fleet (All users)
✅ Search with 6 filter options
✅ Real-time status tracking
✅ Support for Cars and Bikes

### Rental Operations
✅ Rent available vehicles
✅ Return rented vehicles
✅ Status updates (Available/Rented)
✅ Confirmation dialogs

### Customer Management
✅ Add customers (Admin)
✅ Remove customers (Admin)
✅ Customer database view
✅ Automatic ID assignment

### Reservations
✅ View all reservations (Admin)
✅ View own reservations (Customer)
✅ Track dates and costs
✅ Status monitoring (active/completed/cancelled)

### UI/UX
✅ Modern dark theme
✅ Responsive layout
✅ Sortable tables
✅ Real-time search
✅ Input validation
✅ Confirmation dialogs

---

## 🎯 What You Can Do

### As Admin:
- ✅ Manage entire vehicle fleet
- ✅ Add new cars and bikes
- ✅ Remove vehicles from system
- ✅ View and search all vehicles
- ✅ Rent and return vehicles
- ✅ Manage customer database
- ✅ Add and remove customers
- ✅ View all reservations system-wide
- ✅ Track rental history

### As Customer:
- ✅ Browse vehicle catalog
- ✅ Search available vehicles
- ✅ Filter by type, brand, status
- ✅ Rent available vehicles
- ✅ Return rented vehicles
- ✅ View own reservations
- ✅ Track personal rental history

---

## 📞 Support & Resources

### Documentation Files
- All markdown files in repository root
- Screenshots in `docs/` folder
- Code comments in source files

### Key Contacts
- Check repository issues for questions
- Review CONTRIBUTING.md for guidelines

### External Resources
- [Qt6 Documentation](https://doc.qt.io/qt-6/)
- [SQLite Documentation](https://www.sqlite.org/docs.html)
- [C++17 Reference](https://en.cppreference.com/)

---

## 🎓 Learning Path

### Beginner (Understand the System)
1. ✅ Read README.md
2. ✅ View COMPLETE_GUI_SHOWCASE.md
3. ✅ Build and run application
4. ✅ Try both admin and customer logins
5. ✅ Test each window/feature

### Intermediate (Explore Details)
1. ✅ Read DESIGN.md for architecture
2. ✅ Review DATABASE_GUIDE.md for schema
3. ✅ Test all search filters
4. ✅ Understand role differences
5. ✅ Follow all user workflows

### Advanced (Extend the System)
1. ✅ Read source code in .h/.cpp files
2. ✅ Understand MVC pattern implementation
3. ✅ Review database queries
4. ✅ Study Qt6 widgets usage
5. ✅ Plan custom extensions

---

## 📋 Checklist: Have You Seen All Windows?

### Login & Authentication
- [ ] Login window with username/password
- [ ] Tested admin account (admin/admin123)
- [ ] Tested customer account (customer/customer123)

### Main Windows (All 5)
- [ ] Dashboard with vehicle fleet
- [ ] Add Vehicle form
- [ ] Rent/Return interface
- [ ] Manage Customers view
- [ ] Reservations display

### Search & Filter
- [ ] Search by All (global search)
- [ ] Search by ID
- [ ] Search by Type (Car/Bike)
- [ ] Search by Brand
- [ ] Search by Model
- [ ] Search by Status (Available/Rented)

### Operations Tested
- [ ] Added a new vehicle (Admin)
- [ ] Rented a vehicle
- [ ] Returned a vehicle
- [ ] Added a customer (Admin)
- [ ] Removed a customer (Admin)
- [ ] Viewed reservations

### Role Differences
- [ ] Tested admin full access
- [ ] Tested customer limited access
- [ ] Understood feature restrictions

---

## 🏆 Summary

The Vehicle Rental System provides a **complete, production-ready GUI application** with:

- **7 Windows/Views** (Login + 5 main windows + Registration)
- **2 User Roles** (Admin with full access, Customer with limited)
- **6 Search Filters** (All, ID, Type, Brand, Model, Status)
- **3 Database Tables** (Users, Vehicles, Reservations)
- **5 Main Operations** (Add, Remove, Rent, Return, Manage)
- **Modern Dark Theme** with purple accents
- **Complete Documentation** with visual guides

**Everything is documented, implemented, and ready to use!**

---

**📚 For the complete visual guide with ASCII diagrams of all windows, workflows, and examples:**
## ➡️ [READ COMPLETE_GUI_SHOWCASE.md](COMPLETE_GUI_SHOWCASE.md) ⭐

---

*Last Updated: 2024*  
*Qt Version: 6.x*  
*C++ Standard: C++17*  
*Database: SQLite*
