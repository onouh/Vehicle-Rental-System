#ifndef USER_H
#define USER_H

#include <QString>

class User {
private:
    int id;
    QString username;
    QString password;  // Hashed password
    QString role;      // "admin" or "customer"
    QString contactInfo;
    QString licenseNumber;

public:
    User(int id, const QString& username, const QString& password, 
         const QString& role, const QString& contactInfo = "", 
         const QString& licenseNumber = "");
    ~User() = default;

    // Getters
    int getId() const { return id; }
    QString getUsername() const { return username; }
    QString getPassword() const { return password; }
    QString getRole() const { return role; }
    QString getContactInfo() const { return contactInfo; }
    QString getLicenseNumber() const { return licenseNumber; }

    // Setters
    void setPassword(const QString& pwd) { password = pwd; }
    void setContactInfo(const QString& info) { contactInfo = info; }
    void setLicenseNumber(const QString& license) { licenseNumber = license; }
};

#endif // USER_H
