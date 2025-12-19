# Admin GUI Screenshots - Vehicle Rental System

This document provides detailed visual representations of the Admin user interface in the Vehicle Rental System.

## Login as Admin

**Credentials**: `admin` / `admin123`

```
┌─────────────────────────────────────────────────────────────┐
│  Vehicle Rental System - Login                    ⊠ ▭ ✕     │
├─────────────────────────────────────────────────────────────┤
│                                                               │
│                                                               │
│               Vehicle Rental System                           │
│               ═════════════════════                           │
│                                                               │
│                                                               │
│               Username: ┌────────────────────────┐           │
│                        │ admin                   │           │
│                        └────────────────────────┘           │
│                                                               │
│               Password: ┌────────────────────────┐           │
│                        │ ••••••••                │           │
│                        └────────────────────────┘           │
│                                                               │
│                                                               │
│                        ┌────────┐  ┌────────┐               │
│                        │ Login  │  │Register│               │
│                        └────────┘  └────────┘               │
│                                                               │
│                                                               │
└─────────────────────────────────────────────────────────────┘
```

---

## Admin Main Window - Full Access

After logging in as admin, the user gets **full access** to all features:

```
┌──────────────────────────────────────────────────────────────────────────┐
│  Vehicle Rental System - admin (admin)                        ⊠ ▭ ✕      │
├──────────────────────────────────────────────────────────────────────────┤
│                                                                            │
│  ┌──────────┐  ┌─────────────────────────────────────────────────────┐  │
│  │          │  │                                                       │  │
│  │ SIDEBAR  │  │               MAIN CONTENT AREA                       │  │
│  │          │  │                                                       │  │
│  │ ┌──────┐ │  │  (Dashboard / Add Vehicle / Rent-Return /            │  │
│  │ │ Dash │ │  │   Manage Customers / Reservations)                   │  │
│  │ │board │ │  │                                                       │  │
│  │ └──────┘ │  │                                                       │  │
│  │          │  │                                                       │  │
│  │ ┌──────┐ │  │                                                       │  │
│  │ │ Add  │ │  │                                                       │  │
│  │ │Vehicl│ │  │                                                       │  │
│  │ └──────┘ │  │                                                       │  │
│  │          │  │                                                       │  │
│  │ ┌──────┐ │  │                                                       │  │
│  │ │ Rent/│ │  │                                                       │  │
│  │ │Return│ │  │                                                       │  │
│  │ └──────┘ │  │                                                       │  │
│  │          │  │                                                       │  │
│  │ ┌──────┐ │  │                                                       │  │
│  │ │Manage│ │  │                                                       │  │
│  │ │Custom│ │  │                                                       │  │
│  │ └──────┘ │  │                                                       │  │
│  │          │  │                                                       │  │
│  │ ┌──────┐ │  │                                                       │  │
│  │ │Reserv│ │  │                                                       │  │
│  │ │ation │ │  │                                                       │  │
│  │ └──────┘ │  │                                                       │  │
│  │          │  │                                                       │  │
│  └──────────┘  └─────────────────────────────────────────────────────┘  │
│                                                                            │
└──────────────────────────────────────────────────────────────────────────┘
```

---

## 1. Admin Dashboard View

The admin can view all vehicles in the fleet with full control:

```
┌──────────────────────────────────────────────────────────────────────────────────┐
│  Vehicle Rental System - admin (admin)                              ⊠ ▭ ✕       │
├──────────────────────────────────────────────────────────────────────────────────┤
│ ┌──────────┐ ┌──────────────────────────────────────────────────────────────┐   │
│ │Dashboard │ │                                                                │   │
│ │          │ │  Dashboard - Vehicle Fleet Management                         │   │
│ │ Add      │ │  ════════════════════════════════════════                     │   │
│ │ Vehicle  │ │                                                                │   │
│ │          │ │  Search: ┌──────────────┐  Filter: ┌─────────┐  ┌────────┐   │   │
│ │ Rent/    │ │         │ Search...     │         │  All    ▼│  │ Search │   │   │
│ │ Return   │ │         └──────────────┘         └─────────┘  └────────┘   │   │
│ │          │ │                                                                │   │
│ │ Manage   │ │  ┌────────────────────────────────────────────────────────┐  │   │
│ │Customers │ │  │ ID │ Type │ Brand    │ Model    │ Rate/Day │ Status   │  │   │
│ │          │ │  ├────┼──────┼──────────┼──────────┼──────────┼──────────┤  │   │
│ │Reserva-  │ │  │ 1  │ Car  │ Toyota   │ Camry    │ $50.00   │Available │  │   │
│ │ tions    │ │  │ 2  │ Car  │ Honda    │ Civic    │ $45.00   │Available │  │   │
│ └──────────┘ │  │ 3  │ Bike │ Yamaha   │ MT-07    │ $30.00   │Available │  │   │
│              │  │ 4  │ Bike │ Kawasaki │ Ninja400 │ $35.00   │ Rented   │  │   │
│              │  │ 5  │ Car  │ Ford     │ Mustang  │ $75.00   │Available │  │   │
│              │  │ 6  │ Bike │ Suzuki   │ GSX-R750 │ $40.00   │Available │  │   │
│              │  │ 7  │ Car  │ Tesla    │ Model 3  │ $90.00   │Available │  │   │
│              │  └────────────────────────────────────────────────────────┘  │   │
│              │                                                                │   │
│              │  ┌─────────┐  ┌──────────────┐                               │   │
│              │  │ Refresh │  │Remove Selected│                               │   │
│              │  └─────────┘  └──────────────┘                               │   │
│              │                                                                │   │
│              └──────────────────────────────────────────────────────────────┘   │
└──────────────────────────────────────────────────────────────────────────────────┘
```

**Admin Dashboard Features:**
- ✅ View all vehicles in the fleet
- ✅ Search and filter vehicles by type, brand, model, or status
- ✅ Real-time status updates (Available/Rented)
- ✅ Remove vehicles from the fleet
- ✅ Refresh vehicle list from database

---

## 2. Admin Add Vehicle Form

Admins can add new vehicles (Cars or Bikes) to the fleet:

```
┌──────────────────────────────────────────────────────────────────────────────────┐
│  Vehicle Rental System - admin (admin)                              ⊠ ▭ ✕       │
├──────────────────────────────────────────────────────────────────────────────────┤
│ ┌──────────┐ ┌──────────────────────────────────────────────────────────────┐   │
│ │Dashboard │ │                                                                │   │
│ │          │ │  Add Vehicle Form                                              │   │
│ │[Add      │ │  ════════════════                                              │   │
│ │ Vehicle] │ │                                                                │   │
│ │          │ │                                                                │   │
│ │ Rent/    │ │  Vehicle Type:  ┌────────────┐                                │   │
│ │ Return   │ │                 │ Car       ▼│                                │   │
│ │          │ │                 └────────────┘                                │   │
│ │ Manage   │ │                                                                │   │
│ │Customers │ │  Brand:  ┌──────────────────────────┐                         │   │
│ │          │ │          │ e.g., Toyota, Honda      │                         │   │
│ │Reserva-  │ │          └──────────────────────────┘                         │   │
│ │ tions    │ │                                                                │   │
│ └──────────┘ │  Model:  ┌──────────────────────────┐                         │   │
│              │          │ e.g., Camry, Civic       │                         │   │
│              │          └──────────────────────────┘                         │   │
│              │                                                                │   │
│              │  Base Rate ($/day):  ┌──────────────┐                         │   │
│              │                      │ 50.00        │                         │   │
│              │                      └──────────────┘                         │   │
│              │                                                                │   │
│              │  ┌─────────────────────────────────────────┐                  │   │
│              │  │ For Cars:                               │                  │   │
│              │  │  Number of Doors:  ┌──┐                │                  │   │
│              │  │                    │4▼│                │                  │   │
│              │  │                    └──┘                │                  │   │
│              │  └─────────────────────────────────────────┘                  │   │
│              │                                                                │   │
│              │  ┌──────────────┐                                             │   │
│              │  │ Add Vehicle  │                                             │   │
│              │  └──────────────┘                                             │   │
│              │                                                                │   │
│              └──────────────────────────────────────────────────────────────┘   │
└──────────────────────────────────────────────────────────────────────────────────┘
```

**Admin Add Vehicle Features:**
- ✅ Choose vehicle type (Car or Bike)
- ✅ Enter brand and model
- ✅ Set daily rental rate
- ✅ Car-specific: Select number of doors (2-5)
- ✅ Bike-specific: Enter engine capacity (50-2000 cc)
- ✅ Form validation and error messages
- ✅ Automatic addition to database

---

## 3. Admin Rent/Return Interface

Admins can manage vehicle rentals:

```
┌──────────────────────────────────────────────────────────────────────────────────┐
│  Vehicle Rental System - admin (admin)                              ⊠ ▭ ✕       │
├──────────────────────────────────────────────────────────────────────────────────┤
│ ┌──────────┐ ┌──────────────────────────────────────────────────────────────┐   │
│ │Dashboard │ │                                                                │   │
│ │          │ │  Rent/Return Vehicles                                          │   │
│ │ Add      │ │  ═══════════════════                                           │   │
│ │ Vehicle  │ │                                                                │   │
│ │          │ │  ┌────────────────────────────────────────────────────────┐   │   │
│ │[Rent/    │ │  │ ID │ Type │ Brand    │ Model    │ Rate/Day │ Status   │   │   │
│ │ Return]  │ │  ├────┼──────┼──────────┼──────────┼──────────┼──────────┤   │   │
│ │          │ │  │ 1  │ Car  │ Toyota   │ Camry    │ $50.00   │Available │   │   │
│ │ Manage   │ │  │ 2  │ Car  │ Honda    │ Civic    │ $45.00   │Available │   │   │
│ │Customers │ │  │ 3  │ Bike │ Yamaha   │ MT-07    │ $30.00   │Available │   │   │
│ │          │ │  │ 4  │ Bike │ Kawasaki │ Ninja400 │ $35.00   │ Rented   │   │   │
│ │Reserva-  │ │  │ 5  │ Car  │ Ford     │ Mustang  │ $75.00   │Available │   │   │
│ │ tions    │ │  │ 6  │ Bike │ Suzuki   │ GSX-R750 │ $40.00   │Available │   │   │
│ └──────────┘ │  │ 7  │ Car  │ Tesla    │ Model 3  │ $90.00   │Available │   │   │
│              │  └────────────────────────────────────────────────────────┘   │   │
│              │                                                                │   │
│              │  ┌──────────────┐  ┌────────────────┐                         │   │
│              │  │Rent Selected │  │Return Selected │                         │   │
│              │  └──────────────┘  └────────────────┘                         │   │
│              │                                                                │   │
│              │  Instructions:                                                 │   │
│              │  • Select a vehicle from the table                             │   │
│              │  • Click "Rent Selected" to mark as rented                     │   │
│              │  • Click "Return Selected" to mark as available                │   │
│              │                                                                │   │
│              └──────────────────────────────────────────────────────────────┘   │
└──────────────────────────────────────────────────────────────────────────────────┘
```

**Admin Rent/Return Features:**
- ✅ View all vehicles with current status
- ✅ Rent available vehicles
- ✅ Return rented vehicles
- ✅ Status validation (can't rent already-rented vehicles)
- ✅ Confirmation dialogs
- ✅ Real-time status updates

---

## 4. Admin Manage Customers View

Admins can manage customer records:

```
┌──────────────────────────────────────────────────────────────────────────────────┐
│  Vehicle Rental System - admin (admin)                              ⊠ ▭ ✕       │
├──────────────────────────────────────────────────────────────────────────────────┤
│ ┌──────────┐ ┌──────────────────────────────────────────────────────────────┐   │
│ │Dashboard │ │                                                                │   │
│ │          │ │  Customer Management                                           │   │
│ │ Add      │ │  ══════════════════                                            │   │
│ │ Vehicle  │ │                                                                │   │
│ │          │ │  Add New Customer                                              │   │
│ │ Rent/    │ │  ─────────────────                                             │   │
│ │ Return   │ │                                                                │   │
│ │          │ │  Name:   ┌──────────────────────────┐                          │   │
│ │[Manage   │ │          │ John Doe                 │                          │   │
│ │Customers]│ │          └──────────────────────────┘                          │   │
│ │          │ │                                                                │   │
│ │Reserva-  │ │  Email:  ┌──────────────────────────┐                          │   │
│ │ tions    │ │          │ john.doe@email.com       │                          │   │
│ └──────────┘ │          └──────────────────────────┘                          │   │
│              │                                                                │   │
│              │  Phone:  ┌──────────────────────────┐                          │   │
│              │          │ 555-1234                 │                          │   │
│              │          └──────────────────────────┘                          │   │
│              │                                                                │   │
│              │  ┌──────────────┐                                              │   │
│              │  │Add Customer  │                                              │   │
│              │  └──────────────┘                                              │   │
│              │                                                                │   │
│              │  Customer List                                                 │   │
│              │  ─────────────                                                 │   │
│              │  ┌────────────────────────────────────────────────────────┐   │   │
│              │  │ ID │ Name         │ Email              │ Phone        │   │   │
│              │  ├────┼──────────────┼────────────────────┼──────────────┤   │   │
│              │  │ 1  │ John Smith   │ john@example.com   │ 555-0101     │   │   │
│              │  │ 2  │ Jane Wilson  │ jane@example.com   │ 555-0202     │   │   │
│              │  │ 3  │ Bob Johnson  │ bob@example.com    │ 555-0303     │   │   │
│              │  └────────────────────────────────────────────────────────┘   │   │
│              │                                                                │   │
│              │  ┌────────────────┐                                            │   │
│              │  │Remove Selected │                                            │   │
│              │  └────────────────┘                                            │   │
│              └──────────────────────────────────────────────────────────────┘   │
└──────────────────────────────────────────────────────────────────────────────────┘
```

**Admin Manage Customers Features:**
- ✅ Add new customers with name, email, and phone
- ✅ View all customer records
- ✅ Remove customers from the system
- ✅ Input validation
- ✅ Confirmation dialogs

---

## 5. Admin Reservations View

Admins can view and manage all reservations:

```
┌──────────────────────────────────────────────────────────────────────────────────┐
│  Vehicle Rental System - admin (admin)                              ⊠ ▭ ✕       │
├──────────────────────────────────────────────────────────────────────────────────┤
│ ┌──────────┐ ┌──────────────────────────────────────────────────────────────┐   │
│ │Dashboard │ │                                                                │   │
│ │          │ │  Reservations Management                                       │   │
│ │ Add      │ │  ═══════════════════════                                       │   │
│ │ Vehicle  │ │                                                                │   │
│ │          │ │  ┌──────────────────────────────────────────────────────────┐ │   │
│ │ Rent/    │ │  │ Reservation │ User    │ Vehicle  │ Start    │ End       │ │   │
│ │ Return   │ │  │ ID          │ ID      │ ID       │ Date     │ Date      │ │   │
│ │          │ │  ├─────────────┼─────────┼──────────┼──────────┼───────────┤ │   │
│ │ Manage   │ │  │ 1           │ 2       │ 4        │2024-01-15│2024-01-20 │ │   │
│ │Customers │ │  │ 2           │ 2       │ 1        │2024-01-18│2024-01-22 │ │   │
│ │          │ │  │ 3           │ 3       │ 3        │2024-01-20│2024-01-25 │ │   │
│ │[Reserva- │ │  └──────────────────────────────────────────────────────────┘ │   │
│ │ tions]   │ │                                                                │   │
│ └──────────┘ │  ┌──────────────────────────────────────────────────────────┐ │   │
│              │  │ Total Cost  │ Status     │ Created At                     │ │   │
│              │  ├─────────────┼────────────┼────────────────────────────────┤ │   │
│              │  │ $175.00     │ active     │ 2024-01-14 10:30:00           │ │   │
│              │  │ $200.00     │ active     │ 2024-01-17 14:15:00           │ │   │
│              │  │ $150.00     │ completed  │ 2024-01-19 09:45:00           │ │   │
│              │  └──────────────────────────────────────────────────────────┘ │   │
│              │                                                                │   │
│              │  ┌─────────┐                                                   │   │
│              │  │ Refresh │                                                   │   │
│              │  └─────────┘                                                   │   │
│              │                                                                │   │
│              └──────────────────────────────────────────────────────────────┘   │
└──────────────────────────────────────────────────────────────────────────────────┘
```

**Admin Reservations Features:**
- ✅ View all reservations in the system
- ✅ See reservation details (user, vehicle, dates, cost)
- ✅ Track reservation status (active/completed/cancelled)
- ✅ Database-backed persistence
- ✅ Real-time updates

---

## Summary: Admin Role Capabilities

As an **Admin**, users have **full access** to all system features:

| Feature | Admin Access |
|---------|--------------|
| View Dashboard | ✅ Yes |
| Add Vehicles | ✅ Yes |
| Remove Vehicles | ✅ Yes |
| Rent Vehicles | ✅ Yes |
| Return Vehicles | ✅ Yes |
| Manage Customers | ✅ Yes |
| View Reservations | ✅ Yes |
| Search & Filter | ✅ Yes |
| Database Access | ✅ Full |

---

## Color Scheme (Dark Theme)

The admin interface uses a professional dark theme:

- **Background**: Dark gray (#2b2b2b)
- **Sidebar**: Darker gray (#1e1e1e)
- **Accent Color**: Slate purple (#6a5acd)
- **Text**: White (#ffffff)
- **Borders**: Medium gray (#3d3d3d)
- **Remove Buttons**: Red (#d32f2f)
- **Interactive Elements**: Hover effects with lighter shades

---

**Note**: All admin features are protected by the authentication system with SHA-256 password hashing.
