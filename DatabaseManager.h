#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QString>
#include <QVector>
#include <memory>
#include "User.h"
#include "Vehicle.h"

struct Reservation {
    int id;
    int userId;
    int vehicleId;
    QString startDate;
    QString endDate;
    double totalCost;
    QString status;  // "active", "completed", "cancelled"
};

class DatabaseManager {
private:
    QSqlDatabase db;
    static DatabaseManager* instance;
    
    // Private constructor for singleton
    DatabaseManager();
    
    // Helper methods
    bool createTables();
    
public:
    // Singleton access
    static DatabaseManager* getInstance();
    
    // Destructor
    ~DatabaseManager();
    
    // Delete copy constructor and assignment operator
    DatabaseManager(const DatabaseManager&) = delete;
    DatabaseManager& operator=(const DatabaseManager&) = delete;
    
    // Database initialization
    bool initializeDatabase();
    
    // User operations
    bool authenticateUser(const QString& username, const QString& password);
    bool addUser(const QString& username, const QString& password, 
                 const QString& role, const QString& contactInfo = "", 
                 const QString& licenseNumber = "");
    User* getUserByUsername(const QString& username);
    User* getUserById(int id);
    
    // Vehicle operations
    bool addVehicle(const QString& brand, const QString& model, 
                   const QString& category, double dailyRate, 
                   const QString& status = "available");
    bool removeVehicle(int id);
    bool updateVehicleStatus(int id, const QString& status);
    QVector<QStringList> getAllVehicles();
    QVector<QStringList> getAvailableVehicles();
    
    // Reservation operations
    bool createReservation(int userId, int vehicleId, const QString& startDate, 
                          const QString& endDate, double totalCost);
    bool updateReservationStatus(int id, const QString& status);
    QVector<Reservation> getReservationsByUserId(int userId);
    QVector<Reservation> getAllReservations();
    bool checkAvailability(int vehicleId, const QString& startDate, const QString& endDate);
    
    // Helper methods
    int getLastInsertId();
};

#endif // DATABASEMANAGER_H
