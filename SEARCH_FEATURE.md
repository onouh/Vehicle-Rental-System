# Vehicle Search Feature

## Overview

The Vehicle Rental System now includes a powerful search functionality that allows users to quickly find vehicles in the fleet based on various criteria.

## Location

The search feature is integrated into the **Dashboard** view, located at the top of the vehicle table.

## Components

### Search Input Field
- A text input field where users can enter their search term
- Placeholder text: "Enter search term..."
- Real-time search: Results update as you type
- Case-insensitive search

### Filter Dropdown
- Allows users to narrow down their search to specific attributes
- Available filter options:
  - **All**: Searches across ID, Type, Brand, and Model
  - **ID**: Search by vehicle ID number
  - **Type**: Search by vehicle type (Car or Bike)
  - **Brand**: Search by vehicle brand
  - **Model**: Search by vehicle model
  - **Status**: Search by rental status (Available or Rented)

## How to Use

1. **Navigate to Dashboard**: Click the "Dashboard" button in the sidebar
2. **Choose a Filter** (optional): Select a specific attribute from the dropdown (defaults to "All")
3. **Enter Search Term**: Type your search query in the search box
4. **View Results**: The table automatically updates to show matching vehicles

## Search Examples

### Example 1: Find all Toyotas
- Filter: "Brand" or "All"
- Search term: "toyota"
- Result: All Toyota vehicles in the fleet

### Example 2: Find available vehicles
- Filter: "Status"
- Search term: "available"
- Result: All vehicles that are not currently rented

### Example 3: Find all bikes
- Filter: "Type"
- Search term: "bike"
- Result: All Bike vehicles in the fleet

### Example 4: Find vehicle by ID
- Filter: "ID"
- Search term: "3"
- Result: Vehicle with ID 3 (or vehicles with IDs containing "3")

### Example 5: Clear search
- Simply clear the search box to show all vehicles again

## Technical Implementation

### RentalManager Class
New method added:
```cpp
std::vector<Vehicle*> searchVehicles(const QString& searchTerm, const QString& filterType) const;
```

This method:
- Takes a search term and filter type as parameters
- Returns a vector of matching vehicles
- Performs case-insensitive string matching
- Handles empty search terms by returning all vehicles

### MainWindow Class
New components:
- `QLineEdit* searchInput` - The search text input
- `QComboBox* searchFilterCombo` - The filter dropdown
- `void onSearchTextChanged()` - Slot that handles search events

### Search Algorithm
1. User types in the search box or changes the filter
2. `onSearchTextChanged()` slot is triggered
3. Current search term and filter type are retrieved
4. `RentalManager::searchVehicles()` is called
5. Results are filtered based on the selected filter type
6. Vehicle table is updated with matching results

## Benefits

- **Fast Access**: Quickly locate specific vehicles in large fleets
- **Flexible Filtering**: Search by the attribute that matters most
- **Real-time Updates**: See results instantly as you type
- **User-Friendly**: Simple and intuitive interface
- **No Extra Clicks**: Search functionality is always visible on the dashboard

## Future Enhancements

Potential improvements for future versions:
- Multi-attribute search (e.g., "Toyota AND Available")
- Advanced filters (price range, doors, engine capacity)
- Search history
- Save favorite searches
- Export search results
