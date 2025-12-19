#include "Bike.h"

Bike::Bike(int id, const QString& brand, const QString& model, double baseRate, int engineCapacity)
    : Vehicle(id, brand, model, baseRate), engineCapacity(engineCapacity) {
}

double Bike::calculateCost(int days) const {
    return baseRate * days * 0.8; // Bikes are 20% cheaper
}

QString Bike::getType() const {
    return "Bike";
}
