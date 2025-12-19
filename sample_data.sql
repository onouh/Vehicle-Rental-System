-- Sample data initialization script for Vehicle Rental System
-- Run this after first launch to populate with sample data

-- Note: Default users are created automatically by the application:
-- Username: admin, Password: admin123, Role: admin
-- Username: customer, Password: customer123, Role: customer

-- Insert sample vehicles
INSERT INTO Vehicles (brand, model, category, daily_rate, status) VALUES 
('Toyota', 'Camry', 'Car', 50.00, 'available'),
('Honda', 'Civic', 'Car', 45.00, 'available'),
('Ford', 'Mustang', 'Car', 75.00, 'available'),
('Yamaha', 'MT-07', 'Bike', 30.00, 'available'),
('Harley-Davidson', 'Street 750', 'Bike', 60.00, 'available'),
('BMW', '3 Series', 'Car', 85.00, 'available'),
('Ducati', 'Monster 821', 'Bike', 70.00, 'available');

-- Insert sample reservations (uncomment after vehicles are rented)
-- INSERT INTO Reservations (user_id, vehicle_id, start_date, end_date, total_cost, status) VALUES 
-- (2, 1, '2024-01-01', '2024-01-05', 200.00, 'completed'),
-- (2, 4, '2024-01-10', '2024-01-12', 60.00, 'active');
