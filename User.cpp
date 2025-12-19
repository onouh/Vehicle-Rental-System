#include "User.h"

User::User(int id, const QString& username, const QString& password, 
           const QString& role, const QString& contactInfo, 
           const QString& licenseNumber)
    : id(id), username(username), password(password), role(role),
      contactInfo(contactInfo), licenseNumber(licenseNumber) {
}
