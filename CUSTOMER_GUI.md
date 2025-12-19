# Customer GUI Documentation

## Overview

The Customer Management GUI has been added to the Vehicle Rental System to allow managing customer information. This feature follows the same design patterns and styling as the existing application.

## Features

### Customer Management View

The new "Manage Customers" view includes:

1. **Add New Customer Form**
   - Name field (text input)
   - Email field (text input)
   - Phone field (text input)
   - "Add Customer" button to submit the form

2. **Customer List Table**
   - Displays all customers in a table format
   - Columns: ID, Name, Email, Phone
   - Selection mode: Single row selection
   - Read-only display

3. **Remove Customer Functionality**
   - "Remove Selected" button (styled in red like other remove buttons)
   - Confirmation dialog before deletion
   - Updates the table after successful removal

## Navigation

A new "Manage Customers" button has been added to the sidebar navigation, below the "Rent/Return" button. The sidebar now contains:

1. Dashboard
2. Add Vehicle
3. Rent/Return
4. **Manage Customers** (NEW)

## Technical Implementation

### New Files

- **Customer.h**: Header file defining the Customer class with private fields (id, name, email, phone) and public getters/setters
- **Customer.cpp**: Implementation of the Customer constructor

### Modified Files

- **RentalManager.h**: Added customer management methods and storage
  - `std::vector<Customer*> customers` - stores customer pointers
  - `int nextCustomerId` - tracks next customer ID
  - `addCustomer()`, `removeCustomer()`, `findCustomer()` methods
  - `getCustomers()` and `getNextCustomerId()` getters

- **RentalManager.cpp**: Implemented customer management methods
  - Constructor initializes `nextCustomerId` to 1
  - Destructor properly cleans up customer memory
  - Customer CRUD operations follow same pattern as vehicle operations

- **MainWindow.h**: Added customer UI components and methods
  - `QTableWidget* customerTable` - displays customer list
  - Input fields: `customerNameInput`, `customerEmailInput`, `customerPhoneInput`
  - Methods: `createCustomerManagementView()`, `showCustomerManagement()`, `addCustomer()`, `removeSelectedCustomer()`, `refreshCustomerTable()`

- **MainWindow.cpp**: Implemented customer management view
  - Created new stacked widget page (index 3)
  - Form layout for adding customers
  - Table widget for displaying customers
  - Connected buttons to slot methods
  - Input validation for customer data

- **CMakeLists.txt**: Added Customer.cpp and Customer.h to build configuration

## UI Design

The Customer Management view follows the existing dark theme design:

- **Background**: Dark gray (#2b2b2b)
- **Title**: Large, bold, white text ("Customer Management")
- **Form inputs**: Dark input fields (#353535) with white text
- **Table**: Dark theme matching the vehicle table
- **Buttons**: 
  - "Add Customer" button in accent color (#6a5acd)
  - "Remove Selected" button in red (#d32f2f)

## User Workflow

### Adding a Customer

1. Click "Manage Customers" in the sidebar
2. Fill in the customer name, email, and phone number
3. Click "Add Customer"
4. See success confirmation message
5. Customer appears in the table below

### Removing a Customer

1. Select a customer row in the table
2. Click "Remove Selected"
3. Confirm deletion in the dialog
4. See success confirmation message
5. Customer is removed from the table

## Code Quality

- Follows the existing code patterns and conventions
- Consistent naming with existing code
- Proper memory management (delete in destructor)
- Input validation with user-friendly error messages
- Uses Qt's signal-slot mechanism for event handling
- Consistent styling with QSS

## Future Enhancements

Potential improvements for customer management:

1. Link customers to vehicle rentals (track who rented which vehicle)
2. Add customer search/filter functionality
3. Edit existing customer information
4. Customer rental history
5. Data persistence (save/load customer data)
6. Email validation with regex
7. Phone number formatting
