# Design Documentation

## Overview

This document explains the key design decisions and architecture of the Vehicle Rental System.

## Architecture Pattern

### Object-Oriented Design with Polymorphism

The system follows classic OOP principles with an abstract base class and concrete derived classes:

```
┌─────────────────┐
│    Vehicle      │ (Abstract Base Class)
│   (abstract)    │
├─────────────────┤
│ - id            │
│ - brand         │
│ - model         │
│ - baseRate      │
│ - isRented      │
├─────────────────┤
│ + calculateCost()│ (pure virtual)
│ + getType()     │ (pure virtual)
└────────┬────────┘
         │
    ┌────┴─────┐
    │          │
┌───▼──┐   ┌───▼──┐
│ Car  │   │ Bike │
├──────┤   ├──────┤
│+doors│   │+cc   │
└──────┘   └──────┘
```

### Fleet Management

The `RentalManager` class uses a `std::vector<Vehicle*>` to manage the fleet polymorphically:

```cpp
std::vector<Vehicle*> fleet;
```

This allows storing both Cars and Bikes in the same collection while maintaining their specific behaviors through virtual function dispatch.

## Design Decisions

### 1. Raw Pointers vs Smart Pointers

**Decision**: Use raw pointers with manual memory management.

**Rationale**:
- The RentalManager has clear ownership semantics (destructor cleans up all vehicles)
- Qt framework commonly uses raw pointers for widget management
- Simpler for educational purposes
- Future enhancement: Could migrate to `std::unique_ptr<Vehicle>` for automatic cleanup

### 2. Pure Virtual Functions

**Decision**: Make `calculateCost()` and `getType()` pure virtual.

**Rationale**:
- Forces all derived classes to implement these methods
- Prevents instantiation of the abstract Vehicle class
- Enforces polymorphic behavior
- Makes the intent of the base class clear

### 3. Qt6 Widgets Module

**Decision**: Use Qt Widgets instead of QML/Quick.

**Rationale**:
- More straightforward for C++ developers
- Better integration with existing C++ code
- Mature and stable API
- Easier to style with QSS (similar to CSS)

### 4. QStackedWidget for Navigation

**Decision**: Use QStackedWidget for switching between views.

**Rationale**:
- Clean separation of concerns (each view is independent)
- Easy to add new views
- Efficient (views are created once, not regenerated)
- Smooth transitions between different screens

### 5. Dark Theme with Custom QSS

**Decision**: Apply a modern dark theme using QSS (Qt Style Sheets).

**Rationale**:
- Modern applications often use dark themes
- Reduces eye strain
- Professional appearance
- QSS provides CSS-like syntax for easy styling

**Color Scheme**:
- Background: `#2b2b2b` (dark gray)
- Sidebar: `#1e1e1e` (darker gray)
- Accent: `#6a5acd` (slate blue)
- Text: `#ffffff` (white)

## Component Responsibilities

### Vehicle (Abstract Base Class)
- Defines common attributes for all vehicles
- Declares interface through pure virtual functions
- Manages rental state (isRented flag)

### Car / Bike (Concrete Classes)
- Implement specific vehicle types
- Override virtual methods with type-specific behavior
- Add type-specific attributes (numDoors, engineCapacity)

### RentalManager (Business Logic)
- Owns the vehicle fleet
- Handles CRUD operations (Create, Read, Update, Delete)
- Manages rental transactions (rent/return)
- Generates unique IDs for new vehicles

### MainWindow (Presentation Layer)
- Manages the Qt GUI
- Displays vehicle data in tables
- Handles user input through forms
- Applies visual styling
- Bridges UI events to business logic

## Data Flow

### Adding a Vehicle

```
User Input → MainWindow::addVehicle()
           → Validate input
           → Create Car/Bike object
           → RentalManager::addVehicle()
           → Add to fleet vector
           → Refresh UI
```

### Renting a Vehicle

```
User Selection → Get vehicle ID from table
               → RentalManager::rentVehicle(id)
               → Find vehicle in fleet
               → Check if available
               → Set isRented = true
               → Return success/failure
               → Update UI status
```

## Extension Points

The design allows for easy extensions:

1. **New Vehicle Types**: Create new derived classes (e.g., Truck, Motorcycle)
2. **Additional Attributes**: Add fields to Vehicle or derived classes
3. **Complex Pricing**: Override calculateCost() with different algorithms
4. **Persistence**: Add save/load functionality to RentalManager
5. **User Authentication**: Add User class and login system
6. **Reservation System**: Add date-based rental periods
7. **Payment Processing**: Integrate payment gateway

## Testing Strategy

### Unit Testing (Recommended)
- Test Vehicle, Car, Bike classes independently
- Test RentalManager operations (add, remove, rent, return)
- Mock Qt dependencies for faster tests

### Integration Testing
- Test UI interactions with business logic
- Verify data flow from UI to RentalManager

### Manual Testing
- UI/UX validation
- Visual styling verification
- End-to-end user workflows

## Performance Considerations

- **Fleet Size**: Current implementation uses `std::vector` which is efficient for small to medium fleets (< 10,000 vehicles)
- **Search Operations**: Linear search O(n) is acceptable for typical use cases
- **Memory**: Manual memory management requires careful cleanup to avoid leaks
- **UI Updates**: Table refresh could be optimized to update only changed rows

## Security Considerations

- **Input Validation**: Basic validation on user inputs (empty fields, negative values)
- **Memory Safety**: Proper cleanup in RentalManager destructor
- **No User Authentication**: Not implemented in current version
- **No Database**: Data exists only in memory (lost on application close)

## Future Enhancements

1. **Data Persistence**
   - SQLite database integration
   - JSON export/import
   - Configuration file support

2. **Advanced Features**
   - Rental history tracking
   - Customer management
   - Date-based reservations
   - Pricing tiers and discounts

3. **Code Quality**
   - Migrate to smart pointers
   - Add comprehensive unit tests
   - Implement logging system
   - Add error handling framework

4. **UI/UX**
   - Add search and filter capabilities
   - Implement sorting in tables
   - Add vehicle images
   - Generate rental receipts
