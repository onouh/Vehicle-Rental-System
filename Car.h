#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle {
private:
    int numDoors;

public:
    Car(int id, const QString& brand, const QString& model, double baseRate, int numDoors);

    double calculateCost(int days) const override;
    QString getType() const override;

    int getNumDoors() const { return numDoors; }
};

#endif // CAR_H
