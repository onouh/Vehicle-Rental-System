# Customer GUI Screenshot Description

## Overview
This document describes what the Customer GUI looks like when the application runs.

## Main Window Layout

```
┌────────────────────────────────────────────────────────────────────────┐
│ Vehicle Rental System                                         ⊠ ▭ ✕    │
├──────────────┬─────────────────────────────────────────────────────────┤
│              │                                                           │
│  SIDEBAR     │  CONTENT AREA (Customer Management)                      │
│              │                                                           │
│ ┌──────────┐ │  Customer Management                                     │
│ │Dashboard │ │  ═══════════════════                                     │
│ └──────────┘ │                                                           │
│              │  Add New Customer                                         │
│ ┌──────────┐ │                                                           │
│ │Add       │ │  Name:     ┌────────────────────────────────────┐        │
│ │Vehicle   │ │            │ Enter customer name                │        │
│ └──────────┘ │            └────────────────────────────────────┘        │
│              │                                                           │
│ ┌──────────┐ │  Email:    ┌────────────────────────────────────┐        │
│ │Rent/     │ │            │ Enter email address                │        │
│ │Return    │ │            └────────────────────────────────────┘        │
│ └──────────┘ │                                                           │
│              │  Phone:    ┌────────────────────────────────────┐        │
│ ┌──────────┐ │            │ Enter phone number                 │        │
│ │Manage    │ │            └────────────────────────────────────┘        │
│ │Customers │ │                                                           │
│ └──────────┘ │  ┌──────────────┐                                        │
│     ↑        │  │ Add Customer │                                        │
│  (ACTIVE)    │  └──────────────┘                                        │
│              │                                                           │
│              │  Customer List                                            │
│              │  ═════════════                                            │
│              │                                                           │
│              │  ┌────┬──────────────┬─────────────────┬──────────────┐ │
│              │  │ ID │ Name         │ Email           │ Phone        │ │
│              │  ├────┼──────────────┼─────────────────┼──────────────┤ │
│              │  │  1 │ John Smith   │ john@email.com  │ 555-0100     │ │
│              │  │  2 │ Jane Doe     │ jane@email.com  │ 555-0101     │ │
│              │  │  3 │ Bob Johnson  │ bob@email.com   │ 555-0102     │ │
│              │  └────┴──────────────┴─────────────────┴──────────────┘ │
│              │                                                           │
│              │  ┌─────────────────┐                                     │
│              │  │ Remove Selected │                                     │
│              │  └─────────────────┘                                     │
│              │                                                           │
└──────────────┴─────────────────────────────────────────────────────────┘
```

## Color Scheme (Dark Theme)

### Sidebar (Left Panel)
- **Background**: Very dark gray (#1e1e1e)
- **Border**: Subtle gray border on the right (#3d3d3d)
- **Width**: Fixed 200px

### Buttons (Sidebar Navigation)
- **Normal State**:
  - Background: Medium dark gray (#3d3d3d)
  - Text: White (#ffffff)
  - Border radius: 5px rounded corners
  - Padding: 12px
  - Left-aligned text

- **Hover State**:
  - Background: Accent purple (#6a5acd)
  
- **Pressed State**:
  - Background: Darker purple (#5a4abd)

### Content Area
- **Background**: Dark gray (#2b2b2b)
- **Padding**: 30px all around

### Title
- **Text**: "Customer Management"
- **Style**: 
  - Font size: 24px
  - Font weight: Bold
  - Color: White (#ffffff)
  - Margin: 20px top and bottom

### Section Headers
- **Text**: "Add New Customer", "Customer List"
- **Style**:
  - Font size: 16px
  - Font weight: Bold
  - Color: White (#ffffff)
  - Margin: 10px top

### Form Fields
- **Input boxes**:
  - Background: Medium dark gray (#353535)
  - Text color: White (#ffffff)
  - Border: 1px solid subtle gray (#3d3d3d)
  - Border radius: 5px rounded corners
  - Padding: 8px
  - Placeholder text in light gray

- **Focus State**:
  - Border: 1px solid accent purple (#6a5acd)

### Buttons (Action Buttons)

#### "Add Customer" Button
- **Background**: Accent purple (#6a5acd)
- **Text**: White, bold
- **Hover**: Lighter purple (#7b6bd8)
- **Pressed**: Darker purple (#5a4abd)
- **Border radius**: 5px
- **Padding**: 10px horizontal, 20px vertical

#### "Remove Selected" Button
- **Background**: Red (#d32f2f)
- **Text**: White, bold
- **Hover**: Brighter red (#e53935)
- **Pressed**: Darker red (#c62828)
- **Border radius**: 5px
- **Padding**: 10px horizontal, 20px vertical

### Table
- **Background**: Medium dark gray (#353535)
- **Text**: White (#ffffff)
- **Border**: 1px solid subtle gray (#3d3d3d)
- **Border radius**: 5px rounded corners
- **Grid lines**: Subtle gray (#3d3d3d)

#### Table Headers
- **Background**: Very dark gray (#1e1e1e)
- **Text**: White, bold
- **Border bottom**: 2px accent purple (#6a5acd)
- **Padding**: 10px

#### Table Rows
- **Normal**:
  - Background: Inherited from table
  - Padding: 8px per cell

- **Selected**:
  - Background: Accent purple (#6a5acd)

## Interaction Flows

### Adding a Customer
1. User clicks "Manage Customers" in sidebar (button highlights in purple)
2. View switches to Customer Management (smooth transition)
3. User fills in Name, Email, and Phone fields
4. User clicks "Add Customer" button
5. If fields are empty: Warning dialog appears "Please fill in all customer fields."
6. If valid: Success dialog appears "Customer added successfully!"
7. Form fields clear automatically
8. Customer table updates with new entry
9. New customer appears at the bottom of the table

### Removing a Customer
1. User clicks on a row in the customer table (row highlights in purple)
2. User clicks "Remove Selected" red button
3. Confirmation dialog appears: "Are you sure you want to remove this customer?" [Yes] [No]
4. If Yes: Customer is removed, success dialog shows "Customer removed successfully!"
5. Table updates automatically
6. If No: Dialog closes, no action taken

### Error Handling
- **No selection when removing**: "Please select a customer to remove."
- **Empty fields when adding**: "Please fill in all customer fields."
- **Remove fails**: "Failed to remove customer."

## Professional Features

1. **Consistent Design**: Matches existing vehicle management views perfectly
2. **Input Validation**: Checks for empty fields before submission
3. **User Feedback**: Clear success/error messages via dialog boxes
4. **Confirmation Dialogs**: Prevents accidental deletion
5. **Auto-refresh**: Tables update automatically after changes
6. **Auto-clear**: Form clears after successful submission
7. **Professional Styling**: Modern dark theme with purple accents
8. **Responsive Layout**: Content area expands to fill available space
9. **Clear Visual Hierarchy**: Titles, forms, and tables are well-organized
10. **Accessibility**: High contrast text, clear labels, logical tab order
