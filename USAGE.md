# Usage Guide

This guide walks you through using the Vehicle Rental System application.

## Starting the Application

After building the project (see BUILD.md), run:

```bash
./bin/VehicleRentalSystem
```

The application will start with sample data pre-loaded.

## Main Interface

The application has a sidebar navigation with three main sections:

1. **Dashboard** - View all vehicles and their status
2. **Add Vehicle** - Add new cars or bikes to the fleet
3. **Rent/Return** - Rent or return vehicles

## Dashboard View

### Features
- View complete fleet in a table format
- See vehicle details: ID, Type, Brand, Model, Rate/Day, Status
- Select vehicles for removal
- Refresh the table to see latest updates

### Columns
- **ID**: Unique identifier for each vehicle
- **Type**: Car or Bike
- **Brand**: Manufacturer name (e.g., Toyota, Yamaha)
- **Model**: Model name (e.g., Camry, MT-07)
- **Rate/Day**: Daily rental rate in dollars
- **Status**: Available or Rented

### Actions
- **Refresh**: Updates the table with current data
- **Remove Selected**: Deletes the selected vehicle from the fleet
  - Requires confirmation
  - Cannot be undone

## Adding Vehicles

### Steps to Add a Car

1. Click "Add Vehicle" in the sidebar
2. Select "Car" from the Vehicle Type dropdown
3. Fill in the details:
   - **Brand**: Enter the car manufacturer (e.g., "Honda")
   - **Model**: Enter the car model (e.g., "Accord")
   - **Base Rate ($/day)**: Enter daily rental rate (e.g., "55.00")
   - **Number of Doors**: Select 2-5 doors (default: 4)
4. Click "Add Vehicle"
5. Success message appears
6. Vehicle is added to the fleet

### Steps to Add a Bike

1. Click "Add Vehicle" in the sidebar
2. Select "Bike" from the Vehicle Type dropdown
3. Fill in the details:
   - **Brand**: Enter the bike manufacturer (e.g., "Kawasaki")
   - **Model**: Enter the bike model (e.g., "Ninja 400")
   - **Base Rate ($/day)**: Enter daily rental rate (e.g., "35.00")
   - **Engine Capacity**: Enter engine size in cc (e.g., 399)
4. Click "Add Vehicle"
5. Success message appears
6. Bike is added to the fleet

### Input Validation

The form validates:
- All fields must be filled
- Base rate must be a positive number
- Number of doors: 2-5 range
- Engine capacity: 50-2000 cc range

Error messages appear if validation fails.

## Renting and Returning Vehicles

### Renting a Vehicle

1. Click "Rent/Return" in the sidebar
2. Browse the vehicle table
3. Select a vehicle with "Available" status
4. Click "Rent Selected"
5. Success message appears
6. Status updates to "Rented"

**Note**: You cannot rent a vehicle that is already rented.

### Returning a Vehicle

1. Click "Rent/Return" in the sidebar
2. Browse the vehicle table
3. Select a vehicle with "Rented" status
4. Click "Return Selected"
5. Success message appears
6. Status updates to "Available"

**Note**: You can only return vehicles that are currently rented.

## Cost Calculation

### Car Rental Cost
```
Cost = Base Rate × Number of Days
```

Example: Toyota Camry at $50/day for 3 days = $150

### Bike Rental Cost
```
Cost = Base Rate × Number of Days × 0.8
```

Example: Yamaha MT-07 at $30/day for 3 days = $72 (20% discount)

**Note**: Bikes have a built-in 20% discount compared to their base rate.

## Sample Data

The application comes with pre-loaded sample vehicles:

| ID | Type | Brand    | Model     | Rate/Day | Status    |
|----|------|----------|-----------|----------|-----------|
| 1  | Car  | Toyota   | Camry     | $50.00   | Available |
| 2  | Car  | Honda    | Civic     | $45.00   | Available |
| 3  | Bike | Yamaha   | MT-07     | $30.00   | Available |
| 4  | Bike | Kawasaki | Ninja 400 | $35.00   | Available |

You can remove these vehicles or add your own.

## Common Workflows

### Workflow 1: Rent a Car

1. Go to "Rent/Return"
2. Find "Toyota Camry" (ID: 1)
3. Select it
4. Click "Rent Selected"
5. Confirm rental

### Workflow 2: Add and Rent a New Vehicle

1. Go to "Add Vehicle"
2. Select "Car"
3. Enter: Brand="Ford", Model="Mustang", Rate="75", Doors=2
4. Click "Add Vehicle"
5. Go to "Rent/Return"
6. Find the new Ford Mustang
7. Select and click "Rent Selected"

### Workflow 3: Return Multiple Vehicles

1. Go to "Rent/Return"
2. Select first rented vehicle
3. Click "Return Selected"
4. Select next rented vehicle
5. Click "Return Selected"
6. Repeat as needed

### Workflow 4: Remove Old Vehicles

1. Go to "Dashboard"
2. Select vehicle to remove
3. Click "Remove Selected"
4. Confirm removal
5. Vehicle is deleted from fleet

## Tips and Best Practices

1. **Regular Refreshes**: Click "Refresh" on the dashboard after major operations
2. **Data Persistence**: Data is not saved - all changes are lost when you close the app
3. **ID Numbers**: IDs are auto-incremented and won't be reused
4. **Status Tracking**: Always check vehicle status before attempting to rent
5. **Validation**: Fill all required fields to avoid error messages

## Keyboard Shortcuts

While the application doesn't implement custom shortcuts, standard Qt shortcuts work:

- **Alt + Key**: Activate menu items (if menus were added)
- **Tab**: Navigate between form fields
- **Enter**: Activate focused button
- **Arrow Keys**: Navigate table cells

## Troubleshooting

### "No Selection" Error
**Problem**: Trying to perform an action without selecting a vehicle.
**Solution**: Click on a row in the table to select it first.

### "Invalid Input" Error
**Problem**: Form validation failed.
**Solution**: Check all fields are filled with valid values:
- Brand and Model must not be empty
- Base Rate must be a positive number

### "Already Rented" Error
**Problem**: Trying to rent a vehicle that's already rented.
**Solution**: Only rent vehicles with "Available" status.

### "Not Currently Rented" Error
**Problem**: Trying to return a vehicle that's not rented.
**Solution**: Only return vehicles with "Rented" status.

## Technical Notes

### Data Storage
- All data is stored in memory
- No database or file persistence
- Closing the application loses all data
- Sample data is reloaded on each start

### Vehicle IDs
- Auto-incremented starting from 1
- Unique for each vehicle
- Not reused after vehicle deletion
- Used for all operations (rent, return, remove)

### Limitations
- No user authentication
- No date/time tracking for rentals
- No rental history
- No payment processing
- Single-user application

## Advanced Usage

### Testing Edge Cases

Try these scenarios to explore the system:

1. **Empty Fleet**: Remove all vehicles, then add new ones
2. **High Capacity**: Add 50+ vehicles to test table scrolling
3. **Rapid Operations**: Rent and return the same vehicle multiple times
4. **Invalid Data**: Try entering negative rates or empty fields
5. **Type Switching**: Switch between Car and Bike when adding vehicles

### Understanding the Code

For developers wanting to extend the application:

- See `DESIGN.md` for architecture details
- Check `BUILD.md` for compilation instructions
- Review source files for implementation details
- Refer to Qt6 documentation for widget usage

## Next Steps

After familiarizing yourself with the application:

1. **Extend Features**: Add new vehicle types or attributes
2. **Add Persistence**: Implement database storage
3. **Improve UI**: Add more styling or animations
4. **Add Tests**: Write unit tests for core logic
5. **Deploy**: Package as a distributable application

## Support

For issues or questions:
- Check the README.md for project overview
- Review DESIGN.md for architecture details
- Consult Qt6 documentation: https://doc.qt.io/qt-6/
- Examine the source code comments
