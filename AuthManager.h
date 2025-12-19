#ifndef AUTHMANAGER_H
#define AUTHMANAGER_H

#include <QString>
#include "User.h"

class AuthManager {
private:
    User* currentUser;
    
public:
    AuthManager();
    ~AuthManager();
    
    // Authentication methods
    bool login(const QString& username, const QString& password);
    void logout();
    bool registerUser(const QString& username, const QString& password, 
                     const QString& role, const QString& contactInfo = "", 
                     const QString& licenseNumber = "");
    
    // Password hashing (simple hash for demo)
    static QString hashPassword(const QString& password);
    
    // Current user management
    User* getCurrentUser() const { return currentUser; }
    bool isLoggedIn() const { return currentUser != nullptr; }
    bool isAdmin() const;
    bool isCustomer() const;
};

#endif // AUTHMANAGER_H
