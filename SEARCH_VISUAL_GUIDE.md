# Vehicle Search Feature - Visual Guide

## What Was Added

### Before (Original Dashboard)
```
┌─────────────────────────────────────────────────────────────────┐
│                    Vehicle Fleet Dashboard                       │
├─────────────────────────────────────────────────────────────────┤
│                                                                  │
│  ┌─────┬──────┬─────────┬─────────┬──────────┬───────────┐    │
│  │ ID  │ Type │  Brand  │  Model  │ Rate/Day │  Status   │    │
│  ├─────┼──────┼─────────┼─────────┼──────────┼───────────┤    │
│  │  1  │ Car  │ Toyota  │ Camry   │ $50.00   │ Available │    │
│  │  2  │ Car  │ Honda   │ Civic   │ $45.00   │ Available │    │
│  │  3  │ Bike │ Yamaha  │ MT-07   │ $30.00   │ Available │    │
│  │  4  │ Bike │ Kawasaki│ Ninja..│ $35.00   │ Available │    │
│  └─────┴──────┴─────────┴─────────┴──────────┴───────────┘    │
│                                                                  │
│  [Refresh]  [Remove Selected]                                   │
└─────────────────────────────────────────────────────────────────┘
```

### After (With Search Feature) ✨
```
┌─────────────────────────────────────────────────────────────────┐
│                    Vehicle Fleet Dashboard                       │
├─────────────────────────────────────────────────────────────────┤
│                                                                  │
│  Search: [Enter search term...          ] [All ▼]              │ ← NEW!
│                                                                  │
│  ┌─────┬──────┬─────────┬─────────┬──────────┬───────────┐    │
│  │ ID  │ Type │  Brand  │  Model  │ Rate/Day │  Status   │    │
│  ├─────┼──────┼─────────┼─────────┼──────────┼───────────┤    │
│  │  1  │ Car  │ Toyota  │ Camry   │ $50.00   │ Available │    │
│  │  2  │ Car  │ Honda   │ Civic   │ $45.00   │ Available │    │
│  │  3  │ Bike │ Yamaha  │ MT-07   │ $30.00   │ Available │    │
│  │  4  │ Bike │ Kawasaki│ Ninja..│ $35.00   │ Available │    │
│  └─────┴──────┴─────────┴─────────┴──────────┴───────────┘    │
│                                                                  │
│  [Refresh]  [Remove Selected]                                   │
└─────────────────────────────────────────────────────────────────┘
```

## Interactive Examples

### Example 1: Search for "Toyota"
```
┌─────────────────────────────────────────────────────────────────┐
│  Search: [toyota                        ] [Brand ▼]             │
│                                                                  │
│  ┌─────┬──────┬─────────┬─────────┬──────────┬───────────┐    │
│  │ ID  │ Type │  Brand  │  Model  │ Rate/Day │  Status   │    │
│  ├─────┼──────┼─────────┼─────────┼──────────┼───────────┤    │
│  │  1  │ Car  │ Toyota  │ Camry   │ $50.00   │ Available │    │ ← Only Toyota!
│  └─────┴──────┴─────────┴─────────┴──────────┴───────────┘    │
└─────────────────────────────────────────────────────────────────┘
```

### Example 2: Search for Available Vehicles
```
┌─────────────────────────────────────────────────────────────────┐
│  Search: [available                     ] [Status ▼]            │
│                                                                  │
│  ┌─────┬──────┬─────────┬─────────┬──────────┬───────────┐    │
│  │ ID  │ Type │  Brand  │  Model  │ Rate/Day │  Status   │    │
│  ├─────┼──────┼─────────┼─────────┼──────────┼───────────┤    │
│  │  1  │ Car  │ Toyota  │ Camry   │ $50.00   │ Available │    │
│  │  2  │ Car  │ Honda   │ Civic   │ $45.00   │ Available │    │
│  │  3  │ Bike │ Yamaha  │ MT-07   │ $30.00   │ Available │    │
│  │  4  │ Bike │ Kawasaki│ Ninja..│ $35.00   │ Available │    │ ← All Available!
│  └─────┴──────┴─────────┴─────────┴──────────┴───────────┘    │
└─────────────────────────────────────────────────────────────────┘
```

### Example 3: Search for All Bikes
```
┌─────────────────────────────────────────────────────────────────┐
│  Search: [bike                          ] [Type ▼]              │
│                                                                  │
│  ┌─────┬──────┬─────────┬─────────┬──────────┬───────────┐    │
│  │ ID  │ Type │  Brand  │  Model  │ Rate/Day │  Status   │    │
│  ├─────┼──────┼─────────┼─────────┼──────────┼───────────┤    │
│  │  3  │ Bike │ Yamaha  │ MT-07   │ $30.00   │ Available │    │
│  │  4  │ Bike │ Kawasaki│ Ninja..│ $35.00   │ Available │    │ ← Only Bikes!
│  └─────┴──────┴─────────┴─────────┴──────────┴───────────┘    │
└─────────────────────────────────────────────────────────────────┘
```

### Example 4: Search by ID
```
┌─────────────────────────────────────────────────────────────────┐
│  Search: [3                             ] [ID ▼]                │
│                                                                  │
│  ┌─────┬──────┬─────────┬─────────┬──────────┬───────────┐    │
│  │ ID  │ Type │  Brand  │  Model  │ Rate/Day │  Status   │    │
│  ├─────┼──────┼─────────┼─────────┼──────────┼───────────┤    │
│  │  3  │ Bike │ Yamaha  │ MT-07   │ $30.00   │ Available │    │ ← Only ID 3!
│  └─────┴──────┴─────────┴─────────┴──────────┴───────────┘    │
└─────────────────────────────────────────────────────────────────┘
```

## Filter Options

The dropdown provides these filter choices:

1. **All** - Searches across ID, Type, Brand, and Model
2. **ID** - Search by vehicle ID number
3. **Type** - Search by vehicle type (Car or Bike)
4. **Brand** - Search by vehicle brand
5. **Model** - Search by vehicle model
6. **Status** - Search by rental status (Available or Rented)

## Key Features

✨ **Real-time Updates**
   - Results update as you type
   - No need to press Enter or click Search

✨ **Case-Insensitive**
   - "toyota", "Toyota", "TOYOTA" all work the same

✨ **Persistent Search**
   - Search filters remain active after:
     - Adding vehicles
     - Removing vehicles
     - Renting vehicles
     - Returning vehicles
     - Switching views and coming back

✨ **Clear Search**
   - Simply clear the search box to show all vehicles again

## User Workflow

```
1. User opens Dashboard
   ↓
2. User selects filter (e.g., "Brand")
   ↓
3. User types search term (e.g., "toyota")
   ↓
4. Table automatically filters to show only matching vehicles
   ↓
5. User performs operation (rent, remove, etc.)
   ↓
6. Search remains active - filtered view is preserved!
```

## Technical Implementation

### UI Components
- **QLineEdit**: Text input for search terms
- **QComboBox**: Dropdown for filter selection
- **QHBoxLayout**: Horizontal layout for search bar

### Event Handling
- **textChanged**: Triggers when user types
- **currentIndexChanged**: Triggers when filter changes
- **onSearchTextChanged()**: Main handler that performs filtering

### Algorithm Flow
```
User Input → onSearchTextChanged()
           ↓
     Get search term + filter
           ↓
     Call RentalManager::searchVehicles()
           ↓
     Filter vehicles based on criteria
           ↓
     Update table with results
```

## Styling

The search components match the existing dark theme:
- Dark background (#353535)
- White text (#ffffff)
- Purple accents (#6a5acd)
- Rounded corners (5px)
- Hover effects
- Focus borders

## Performance

✅ Optimized for real-time use
✅ Efficient string operations
✅ Works smoothly with hundreds of vehicles
✅ Minimal CPU usage

---

This visual guide demonstrates how the search feature integrates seamlessly with the existing application while providing powerful filtering capabilities to users.
