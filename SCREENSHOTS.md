# GUI Screenshots - Vehicle Rental System

This directory contains PNG screenshots of all GUI windows in the Vehicle Rental System application.

## Screenshots Overview

### 1. Login Window (`01_login_window.png`)
- **Size**: 400x350 pixels
- **Description**: The initial login screen where users authenticate
- **Features**:
  - Username and password input fields
  - Login button to authenticate existing users
  - Register button to create new accounts
  - Modern dark theme with purple accent buttons

### 2. Main Dashboard (`02_main_dashboard.png`)
- **Size**: 1200x700 pixels
- **Description**: The main vehicle fleet dashboard view
- **Features**:
  - Sidebar navigation with 5 menu options
  - Vehicle Fleet Dashboard table showing ID, Type, Brand, Model, Rate/Day, Status
  - Search functionality with filter dropdown
  - Refresh and Remove Selected buttons
  - Empty state (no vehicles initially)

### 3. Add Vehicle Form (`03_add_vehicle_form.png`)
- **Size**: 1200x700 pixels
- **Description**: Form for adding new vehicles to the fleet
- **Features**:
  - Vehicle Type dropdown (Car/Bike)
  - Number of Doors input (for cars)
  - Brand name input field
  - Model name input field
  - Base Rate ($/day) input field
  - Add Vehicle button
  - Dynamic form fields based on vehicle type

### 4. Rent/Return Interface (`04_rent_return_interface.png`)
- **Size**: 1200x700 pixels
- **Description**: Interface for renting and returning vehicles
- **Features**:
  - Vehicle selection table with columns: ID, Type, Brand, Model, Rate/Day, Status
  - Rent Selected button (purple)
  - Return Selected button (purple)
  - Clear instructions at the top

### 5. Customer Management (`05_customer_management.png`)
- **Size**: 1200x700 pixels
- **Description**: Customer management interface
- **Features**:
  - Add New Customer form with fields:
    - Name
    - Email
    - Phone
  - Add Customer button
  - Customer List table showing ID, Name, Email, Phone
  - Remove Selected button for deleting customers

### 6. Reservations View (`06_reservations_view.png`)
- **Size**: 1200x700 pixels
- **Description**: View showing all vehicle reservations
- **Features**:
  - Table structure for displaying reservations
  - Tracks rental history and active rentals
  - Integrated with the database system

## Technical Details

### How Screenshots Were Captured

The screenshots were generated using a custom Qt C++ tool (`screenshot_main.cpp`) that:
1. Initializes the application with a virtual display (xvfb)
2. Creates and displays each GUI window
3. Navigates through different views by simulating button clicks
4. Captures each window using Qt's `QWidget::grab()` method
5. Saves each screenshot as a PNG file

### Theme and Styling

All screenshots showcase the application's **modern dark theme**:
- Background: Dark gray (#2b2b2b, #333333)
- Text: White/Light gray
- Accent color: Purple (#7c5cde)
- Tables: Dark theme with alternating row colors
- Buttons: Styled with hover effects and rounded corners

### File Naming Convention

Screenshots are numbered sequentially to show the typical user flow:
1. `01_login_window.png` - Entry point
2. `02_main_dashboard.png` - First view after login
3. `03_add_vehicle_form.png` - Adding vehicles
4. `04_rent_return_interface.png` - Renting operations
5. `05_customer_management.png` - Managing customers
6. `06_reservations_view.png` - Viewing reservations

## Reproducing Screenshots

To regenerate the screenshots:

```bash
# Build the screenshot capture tool
cd Vehicle-Rental-System
mkdir -p build && cd build
cmake ..
cmake --build .

# Run with xvfb (virtual display)
cd ..
xvfb-run -a -s "-screen 0 1920x1080x24" ./build/bin/ScreenshotCapture
```

The tool will automatically:
- Create the database
- Display each window
- Capture screenshots
- Save them as PNG files in the project root

## Usage in Documentation

These screenshots can be used in:
- README.md files
- User documentation
- GitHub repository display
- Presentations and demos
- Training materials

## Resolution and Quality

- **Format**: PNG (Portable Network Graphics)
- **Color depth**: 8-bit/color RGB
- **Compression**: Non-interlaced
- **Resolutions**:
  - Login: 400x350 (compact authentication window)
  - Main windows: 1200x700 (full application interface)

---

**Generated on**: December 19, 2025
**Tool**: Custom Qt C++ screenshot capture utility
**Display**: Virtual X server (xvfb) at 1920x1080x24
