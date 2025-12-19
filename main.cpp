#include <QApplication>
#include <QMessageBox>
#include "MainWindow.h"
#include "LoginWindow.h"
#include "DatabaseManager.h"
#include "AuthManager.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    
    // Initialize database
    DatabaseManager* dbManager = DatabaseManager::getInstance();
    if (!dbManager->initializeDatabase()) {
        QMessageBox::critical(nullptr, "Database Error", 
            "Failed to initialize database. Application will exit.");
        return 1;
    }
    
    // Create default admin user if database is empty
    AuthManager authManager;
    if (dbManager->getUserByUsername("admin") == nullptr) {
        authManager.registerUser("admin", "admin123", "admin", "admin@rental.com", "ADMIN001");
        qDebug() << "Default admin user created (username: admin, password: admin123)";
    }
    if (dbManager->getUserByUsername("customer") == nullptr) {
        authManager.registerUser("customer", "customer123", "customer", "customer@rental.com", "LIC001");
        qDebug() << "Default customer user created (username: customer, password: customer123)";
    }
    
    // Show login window
    LoginWindow* loginWindow = new LoginWindow();
    
    // Connect login successful signal to show main window
    QObject::connect(loginWindow, &LoginWindow::loginSuccessful, [&](User* user) {
        MainWindow* mainWindow = new MainWindow(user);  // Pass user to MainWindow
        mainWindow->show();
        
        // Clean up login window
        loginWindow->deleteLater();
    });
    
    loginWindow->show();
    
    return app.exec();
}

