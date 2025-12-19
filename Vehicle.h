#ifndef VEHICLE_H
#define VEHICLE_H

#include <QString>

class Vehicle {
protected:
    int id;
    QString brand;
    QString model;
    double baseRate;
    bool isRented;

public:
    Vehicle(int id, const QString& brand, const QString& model, double baseRate);
    virtual ~Vehicle() = default;

    // Pure virtual functions
    virtual double calculateCost(int days) const = 0;
    virtual QString getType() const = 0;

    // Getters
    int getId() const { return id; }
    QString getBrand() const { return brand; }
    QString getModel() const { return model; }
    double getBaseRate() const { return baseRate; }
    bool getIsRented() const { return isRented; }

    // Setters
    void setRented(bool rented) { isRented = rented; }
};

#endif // VEHICLE_H
