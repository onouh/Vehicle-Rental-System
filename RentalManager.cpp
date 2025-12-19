#include "RentalManager.h"
#include <algorithm>

RentalManager::RentalManager() : nextId(1), nextCustomerId(1) {
}

RentalManager::~RentalManager() {
    for (Vehicle* vehicle : fleet) {
        delete vehicle;
    }
    fleet.clear();
    
    for (Customer* customer : customers) {
        delete customer;
    }
    customers.clear();
}

void RentalManager::addVehicle(Vehicle* vehicle) {
    if (vehicle) {
        fleet.push_back(vehicle);
        nextId++;
    }
}

bool RentalManager::removeVehicle(int id) {
    auto it = std::find_if(fleet.begin(), fleet.end(),
                          [id](Vehicle* v) { return v->getId() == id; });
    
    if (it != fleet.end()) {
        delete *it;
        fleet.erase(it);
        return true;
    }
    return false;
}

Vehicle* RentalManager::findVehicle(int id) {
    auto it = std::find_if(fleet.begin(), fleet.end(),
                          [id](Vehicle* v) { return v->getId() == id; });
    
    return (it != fleet.end()) ? *it : nullptr;
}

std::vector<Vehicle*> RentalManager::searchVehicles(const QString& searchTerm, const QString& filterType) const {
    std::vector<Vehicle*> results;
    QString lowerSearchTerm = searchTerm.toLower();
    
    for (Vehicle* vehicle : fleet) {
        bool matches = false;
        
        // If search term is empty, include all vehicles
        if (lowerSearchTerm.isEmpty()) {
            matches = true;
        } else {
            // Search by filter type
            if (filterType == "All") {
                // Cache lowercase strings to avoid repeated conversions
                QString lowerBrand = vehicle->getBrand().toLower();
                QString lowerModel = vehicle->getModel().toLower();
                QString lowerType = vehicle->getType().toLower();
                
                matches = QString::number(vehicle->getId()).contains(lowerSearchTerm) ||
                         lowerBrand.contains(lowerSearchTerm) ||
                         lowerModel.contains(lowerSearchTerm) ||
                         lowerType.contains(lowerSearchTerm);
            } else if (filterType == "ID") {
                matches = QString::number(vehicle->getId()).contains(lowerSearchTerm);
            } else if (filterType == "Type") {
                matches = vehicle->getType().toLower().contains(lowerSearchTerm);
            } else if (filterType == "Brand") {
                matches = vehicle->getBrand().toLower().contains(lowerSearchTerm);
            } else if (filterType == "Model") {
                matches = vehicle->getModel().toLower().contains(lowerSearchTerm);
            } else if (filterType == "Status") {
                QString status = vehicle->getIsRented() ? "rented" : "available";
                matches = status.contains(lowerSearchTerm);
            }
        }
        
        if (matches) {
            results.push_back(vehicle);
        }
    }
    
    return results;
}

bool RentalManager::rentVehicle(int id) {
    Vehicle* vehicle = findVehicle(id);
    if (vehicle && !vehicle->getIsRented()) {
        vehicle->setRented(true);
        return true;
    }
    return false;
}

bool RentalManager::returnVehicle(int id) {
    Vehicle* vehicle = findVehicle(id);
    if (vehicle && vehicle->getIsRented()) {
        vehicle->setRented(false);
        return true;
    }
    return false;
}

void RentalManager::addCustomer(Customer* customer) {
    if (customer) {
        customers.push_back(customer);
        nextCustomerId++;
    }
}

bool RentalManager::removeCustomer(int id) {
    auto it = std::find_if(customers.begin(), customers.end(),
                          [id](Customer* c) { return c->getId() == id; });
    
    if (it != customers.end()) {
        delete *it;
        customers.erase(it);
        return true;
    }
    return false;
}

Customer* RentalManager::findCustomer(int id) {
    auto it = std::find_if(customers.begin(), customers.end(),
                          [id](Customer* c) { return c->getId() == id; });
    
    return (it != customers.end()) ? *it : nullptr;
}
