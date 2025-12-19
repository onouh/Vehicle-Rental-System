#ifndef RENTALMANAGER_H
#define RENTALMANAGER_H

#include <vector>
#include <QString>
#include "Vehicle.h"

class RentalManager {
private:
    std::vector<Vehicle*> fleet;
    int nextId;

public:
    RentalManager();
    ~RentalManager();

    // Fleet management
    void addVehicle(Vehicle* vehicle);
    bool removeVehicle(int id);
    Vehicle* findVehicle(int id);
    std::vector<Vehicle*> searchVehicles(const QString& searchTerm, const QString& filterType) const;

    // Rental operations
    bool rentVehicle(int id);
    bool returnVehicle(int id);

    // Getters
    const std::vector<Vehicle*>& getFleet() const { return fleet; }
    int getNextId() const { return nextId; }
};

#endif // RENTALMANAGER_H
