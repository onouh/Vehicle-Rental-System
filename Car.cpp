#include "Car.h"

Car::Car(int id, const QString& brand, const QString& model, double baseRate, int numDoors)
    : Vehicle(id, brand, model, baseRate), numDoors(numDoors) {
}

double Car::calculateCost(int days) const {
    return baseRate * days;
}

QString Car::getType() const {
    return "Car";
}
