#include "Vehicle.h"

Vehicle::Vehicle(int id, const QString& brand, const QString& model, double baseRate)
    : id(id), brand(brand), model(model), baseRate(baseRate), isRented(false) {
}
