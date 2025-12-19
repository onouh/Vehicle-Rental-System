#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QString>

class Customer {
private:
    int id;
    QString name;
    QString email;
    QString phone;

public:
    Customer(int id, const QString& name, const QString& email, const QString& phone);
    ~Customer() = default;

    // Getters
    int getId() const { return id; }
    QString getName() const { return name; }
    QString getEmail() const { return email; }
    QString getPhone() const { return phone; }

    // Setters
    void setName(const QString& n) { name = n; }
    void setEmail(const QString& e) { email = e; }
    void setPhone(const QString& p) { phone = p; }
};

#endif // CUSTOMER_H
