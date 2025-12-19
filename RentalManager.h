#ifndef RENTALMANAGER_H
#define RENTALMANAGER_H

#include <vector>
#include <QString>
#include "Vehicle.h"
#include "Customer.h"

class RentalManager {
private:
    std::vector<Vehicle*> fleet;
    std::vector<Customer*> customers;
    int nextId;
    int nextCustomerId;

public:
    RentalManager();
    ~RentalManager();

    // Fleet management
    void addVehicle(Vehicle* vehicle);
    bool removeVehicle(int id);
    Vehicle* findVehicle(int id);

    // Rental operations
    bool rentVehicle(int id);
    bool returnVehicle(int id);

    // Customer management
    void addCustomer(Customer* customer);
    bool removeCustomer(int id);
    Customer* findCustomer(int id);

    // Getters
    const std::vector<Vehicle*>& getFleet() const { return fleet; }
    const std::vector<Customer*>& getCustomers() const { return customers; }
    int getNextId() const { return nextId; }
    int getNextCustomerId() const { return nextCustomerId; }
};

#endif // RENTALMANAGER_H
