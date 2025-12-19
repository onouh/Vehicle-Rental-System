#include "DatabaseManager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QFile>
#include <QVariant>

DatabaseManager* DatabaseManager::instance = nullptr;

DatabaseManager::DatabaseManager() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("vehicle_rental.db");
}

DatabaseManager::~DatabaseManager() {
    if (db.isOpen()) {
        db.close();
    }
}

DatabaseManager* DatabaseManager::getInstance() {
    if (instance == nullptr) {
        instance = new DatabaseManager();
    }
    return instance;
}

bool DatabaseManager::initializeDatabase() {
    if (!db.open()) {
        qDebug() << "Error: connection with database failed -" << db.lastError().text();
        return false;
    }
    
    qDebug() << "Database connected successfully";
    
    // Create tables if they don't exist
    return createTables();
}

bool DatabaseManager::createTables() {
    QSqlQuery query;
    
    // Create Users table
    QString createUsersTable = R"(
        CREATE TABLE IF NOT EXISTS Users (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            username TEXT UNIQUE NOT NULL,
            password TEXT NOT NULL,
            role TEXT NOT NULL,
            contact_info TEXT,
            license_number TEXT
        )
    )";
    
    if (!query.exec(createUsersTable)) {
        qDebug() << "Error creating Users table:" << query.lastError().text();
        return false;
    }
    
    // Create Vehicles table
    QString createVehiclesTable = R"(
        CREATE TABLE IF NOT EXISTS Vehicles (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            brand TEXT NOT NULL,
            model TEXT NOT NULL,
            category TEXT NOT NULL,
            daily_rate REAL NOT NULL,
            status TEXT NOT NULL
        )
    )";
    
    if (!query.exec(createVehiclesTable)) {
        qDebug() << "Error creating Vehicles table:" << query.lastError().text();
        return false;
    }
    
    // Create Reservations table
    QString createReservationsTable = R"(
        CREATE TABLE IF NOT EXISTS Reservations (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            user_id INTEGER NOT NULL,
            vehicle_id INTEGER NOT NULL,
            start_date TEXT NOT NULL,
            end_date TEXT NOT NULL,
            total_cost REAL NOT NULL,
            status TEXT NOT NULL,
            FOREIGN KEY (user_id) REFERENCES Users(id),
            FOREIGN KEY (vehicle_id) REFERENCES Vehicles(id)
        )
    )";
    
    if (!query.exec(createReservationsTable)) {
        qDebug() << "Error creating Reservations table:" << query.lastError().text();
        return false;
    }
    
    qDebug() << "All tables created successfully";
    return true;
}

bool DatabaseManager::authenticateUser(const QString& username, const QString& password) {
    QSqlQuery query;
    query.prepare("SELECT password FROM Users WHERE username = :username");
    query.bindValue(":username", username);
    
    if (!query.exec()) {
        qDebug() << "Error authenticating user:" << query.lastError().text();
        return false;
    }
    
    if (query.next()) {
        QString storedPassword = query.value(0).toString();
        return storedPassword == password;  // Password should already be hashed
    }
    
    return false;
}

bool DatabaseManager::addUser(const QString& username, const QString& password, 
                              const QString& role, const QString& contactInfo, 
                              const QString& licenseNumber) {
    QSqlQuery query;
    query.prepare("INSERT INTO Users (username, password, role, contact_info, license_number) "
                  "VALUES (:username, :password, :role, :contact_info, :license_number)");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    query.bindValue(":role", role);
    query.bindValue(":contact_info", contactInfo);
    query.bindValue(":license_number", licenseNumber);
    
    if (!query.exec()) {
        qDebug() << "Error adding user:" << query.lastError().text();
        return false;
    }
    
    return true;
}

User* DatabaseManager::getUserByUsername(const QString& username) {
    QSqlQuery query;
    query.prepare("SELECT id, username, password, role, contact_info, license_number "
                  "FROM Users WHERE username = :username");
    query.bindValue(":username", username);
    
    if (!query.exec()) {
        qDebug() << "Error getting user:" << query.lastError().text();
        return nullptr;
    }
    
    if (query.next()) {
        return new User(
            query.value(0).toInt(),
            query.value(1).toString(),
            query.value(2).toString(),
            query.value(3).toString(),
            query.value(4).toString(),
            query.value(5).toString()
        );
    }
    
    return nullptr;
}

User* DatabaseManager::getUserById(int id) {
    QSqlQuery query;
    query.prepare("SELECT id, username, password, role, contact_info, license_number "
                  "FROM Users WHERE id = :id");
    query.bindValue(":id", id);
    
    if (!query.exec()) {
        qDebug() << "Error getting user:" << query.lastError().text();
        return nullptr;
    }
    
    if (query.next()) {
        return new User(
            query.value(0).toInt(),
            query.value(1).toString(),
            query.value(2).toString(),
            query.value(3).toString(),
            query.value(4).toString(),
            query.value(5).toString()
        );
    }
    
    return nullptr;
}

bool DatabaseManager::addVehicle(const QString& brand, const QString& model, 
                                 const QString& category, double dailyRate, 
                                 const QString& status) {
    QSqlQuery query;
    query.prepare("INSERT INTO Vehicles (brand, model, category, daily_rate, status) "
                  "VALUES (:brand, :model, :category, :daily_rate, :status)");
    query.bindValue(":brand", brand);
    query.bindValue(":model", model);
    query.bindValue(":category", category);
    query.bindValue(":daily_rate", dailyRate);
    query.bindValue(":status", status);
    
    if (!query.exec()) {
        qDebug() << "Error adding vehicle:" << query.lastError().text();
        return false;
    }
    
    return true;
}

bool DatabaseManager::removeVehicle(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM Vehicles WHERE id = :id");
    query.bindValue(":id", id);
    
    if (!query.exec()) {
        qDebug() << "Error removing vehicle:" << query.lastError().text();
        return false;
    }
    
    return query.numRowsAffected() > 0;
}

bool DatabaseManager::updateVehicleStatus(int id, const QString& status) {
    QSqlQuery query;
    query.prepare("UPDATE Vehicles SET status = :status WHERE id = :id");
    query.bindValue(":status", status);
    query.bindValue(":id", id);
    
    if (!query.exec()) {
        qDebug() << "Error updating vehicle status:" << query.lastError().text();
        return false;
    }
    
    return query.numRowsAffected() > 0;
}

QVector<QStringList> DatabaseManager::getAllVehicles() {
    QVector<QStringList> vehicles;
    QSqlQuery query("SELECT id, brand, model, category, daily_rate, status FROM Vehicles");
    
    if (!query.exec()) {
        qDebug() << "Error getting all vehicles:" << query.lastError().text();
        return vehicles;
    }
    
    while (query.next()) {
        QStringList vehicle;
        vehicle << QString::number(query.value(0).toInt())    // id
                << query.value(1).toString()                  // brand
                << query.value(2).toString()                  // model
                << query.value(3).toString()                  // category
                << QString::number(query.value(4).toDouble()) // daily_rate
                << query.value(5).toString();                 // status
        vehicles.append(vehicle);
    }
    
    return vehicles;
}

QVector<QStringList> DatabaseManager::getAvailableVehicles() {
    QVector<QStringList> vehicles;
    QSqlQuery query("SELECT id, brand, model, category, daily_rate, status FROM Vehicles WHERE status = 'available'");
    
    if (!query.exec()) {
        qDebug() << "Error getting available vehicles:" << query.lastError().text();
        return vehicles;
    }
    
    while (query.next()) {
        QStringList vehicle;
        vehicle << QString::number(query.value(0).toInt())    // id
                << query.value(1).toString()                  // brand
                << query.value(2).toString()                  // model
                << query.value(3).toString()                  // category
                << QString::number(query.value(4).toDouble()) // daily_rate
                << query.value(5).toString();                 // status
        vehicles.append(vehicle);
    }
    
    return vehicles;
}

bool DatabaseManager::createReservation(int userId, int vehicleId, const QString& startDate, 
                                       const QString& endDate, double totalCost) {
    QSqlQuery query;
    query.prepare("INSERT INTO Reservations (user_id, vehicle_id, start_date, end_date, total_cost, status) "
                  "VALUES (:user_id, :vehicle_id, :start_date, :end_date, :total_cost, :status)");
    query.bindValue(":user_id", userId);
    query.bindValue(":vehicle_id", vehicleId);
    query.bindValue(":start_date", startDate);
    query.bindValue(":end_date", endDate);
    query.bindValue(":total_cost", totalCost);
    query.bindValue(":status", "active");
    
    if (!query.exec()) {
        qDebug() << "Error creating reservation:" << query.lastError().text();
        return false;
    }
    
    // Update vehicle status to rented
    return updateVehicleStatus(vehicleId, "rented");
}

bool DatabaseManager::updateReservationStatus(int id, const QString& status) {
    QSqlQuery query;
    query.prepare("UPDATE Reservations SET status = :status WHERE id = :id");
    query.bindValue(":status", status);
    query.bindValue(":id", id);
    
    if (!query.exec()) {
        qDebug() << "Error updating reservation status:" << query.lastError().text();
        return false;
    }
    
    return query.numRowsAffected() > 0;
}

QVector<Reservation> DatabaseManager::getReservationsByUserId(int userId) {
    QVector<Reservation> reservations;
    QSqlQuery query;
    query.prepare("SELECT id, user_id, vehicle_id, start_date, end_date, total_cost, status "
                  "FROM Reservations WHERE user_id = :user_id");
    query.bindValue(":user_id", userId);
    
    if (!query.exec()) {
        qDebug() << "Error getting reservations:" << query.lastError().text();
        return reservations;
    }
    
    while (query.next()) {
        Reservation res;
        res.id = query.value(0).toInt();
        res.userId = query.value(1).toInt();
        res.vehicleId = query.value(2).toInt();
        res.startDate = query.value(3).toString();
        res.endDate = query.value(4).toString();
        res.totalCost = query.value(5).toDouble();
        res.status = query.value(6).toString();
        reservations.append(res);
    }
    
    return reservations;
}

QVector<Reservation> DatabaseManager::getAllReservations() {
    QVector<Reservation> reservations;
    QSqlQuery query("SELECT id, user_id, vehicle_id, start_date, end_date, total_cost, status FROM Reservations");
    
    if (!query.exec()) {
        qDebug() << "Error getting all reservations:" << query.lastError().text();
        return reservations;
    }
    
    while (query.next()) {
        Reservation res;
        res.id = query.value(0).toInt();
        res.userId = query.value(1).toInt();
        res.vehicleId = query.value(2).toInt();
        res.startDate = query.value(3).toString();
        res.endDate = query.value(4).toString();
        res.totalCost = query.value(5).toDouble();
        res.status = query.value(6).toString();
        reservations.append(res);
    }
    
    return reservations;
}

bool DatabaseManager::checkAvailability(int vehicleId, const QString& startDate, const QString& endDate) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM Reservations WHERE vehicle_id = :vehicle_id "
                  "AND status = 'active' AND ("
                  "(start_date <= :start_date AND end_date >= :start_date) OR "
                  "(start_date <= :end_date AND end_date >= :end_date) OR "
                  "(start_date >= :start_date AND end_date <= :end_date))");
    query.bindValue(":vehicle_id", vehicleId);
    query.bindValue(":start_date", startDate);
    query.bindValue(":end_date", endDate);
    
    if (!query.exec()) {
        qDebug() << "Error checking availability:" << query.lastError().text();
        return false;
    }
    
    if (query.next()) {
        int count = query.value(0).toInt();
        return count == 0;  // Available if no overlapping reservations
    }
    
    return false;
}

int DatabaseManager::getLastInsertId() {
    QSqlQuery query("SELECT last_insert_rowid()");
    if (query.next()) {
        return query.value(0).toInt();
    }
    return -1;
}
