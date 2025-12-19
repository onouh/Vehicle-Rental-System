#ifndef BIKE_H
#define BIKE_H

#include "Vehicle.h"

class Bike : public Vehicle {
private:
    int engineCapacity;

public:
    Bike(int id, const QString& brand, const QString& model, double baseRate, int engineCapacity);

    double calculateCost(int days) const override;
    QString getType() const override;

    int getEngineCapacity() const { return engineCapacity; }
};

#endif // BIKE_H
