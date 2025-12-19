#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include "AuthManager.h"

class LoginWindow : public QWidget {
    Q_OBJECT

private:
    AuthManager* authManager;
    
    QLineEdit* usernameInput;
    QLineEdit* passwordInput;
    QPushButton* loginButton;
    QPushButton* registerButton;
    QLabel* statusLabel;
    
    void setupUI();
    void applyStyles();

private slots:
    void onLoginClicked();
    void onRegisterClicked();

signals:
    void loginSuccessful(User* user);

public:
    LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();
};

#endif // LOGINWINDOW_H
