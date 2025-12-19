#include "AuthManager.h"
#include "DatabaseManager.h"
#include <QCryptographicHash>
#include <QDebug>

AuthManager::AuthManager() : currentUser(nullptr) {
}

AuthManager::~AuthManager() {
    if (currentUser != nullptr) {
        delete currentUser;
        currentUser = nullptr;
    }
}

bool AuthManager::login(const QString& username, const QString& password) {
    // Hash the password
    QString hashedPassword = hashPassword(password);
    
    // Authenticate with database
    DatabaseManager* dbManager = DatabaseManager::getInstance();
    if (dbManager->authenticateUser(username, hashedPassword)) {
        currentUser = dbManager->getUserByUsername(username);
        if (currentUser != nullptr) {
            qDebug() << "User logged in successfully:" << username;
            return true;
        }
    }
    
    qDebug() << "Login failed for user:" << username;
    return false;
}

void AuthManager::logout() {
    if (currentUser != nullptr) {
        qDebug() << "User logged out:" << currentUser->getUsername();
        delete currentUser;
        currentUser = nullptr;
    }
}

bool AuthManager::registerUser(const QString& username, const QString& password, 
                              const QString& role, const QString& contactInfo, 
                              const QString& licenseNumber) {
    // Hash the password
    QString hashedPassword = hashPassword(password);
    
    // Add user to database
    DatabaseManager* dbManager = DatabaseManager::getInstance();
    return dbManager->addUser(username, hashedPassword, role, contactInfo, licenseNumber);
}

QString AuthManager::hashPassword(const QString& password) {
    // Simple SHA-256 hash for demo purposes
    QByteArray hash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    return QString(hash.toHex());
}

bool AuthManager::isAdmin() const {
    return currentUser != nullptr && currentUser->getRole() == "admin";
}

bool AuthManager::isCustomer() const {
    return currentUser != nullptr && currentUser->getRole() == "customer";
}
