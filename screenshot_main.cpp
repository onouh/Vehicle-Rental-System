#include <QApplication>
#include <QTimer>
#include <QPixmap>
#include <QScreen>
#include <QWidget>
#include <QPushButton>
#include <QDebug>
#include "LoginWindow.h"
#include "MainWindow.h"
#include "DatabaseManager.h"
#include "User.h"

class ScreenshotHelper : public QObject {
    Q_OBJECT
public:
    ScreenshotHelper(QApplication* app) : app(app), currentStep(0) {
        // Initialize database
        DatabaseManager* dbManager = DatabaseManager::getInstance();
        dbManager->initializeDatabase();
    }
    
    void start() {
        QTimer::singleShot(500, this, &ScreenshotHelper::captureNext);
    }
    
private slots:
    void captureNext() {
        if (currentStep == 0) {
            // Step 1: Capture Login Window (will be ~400x350 with window decorations)
            qDebug() << "Capturing Login Window...";
            loginWindow = new LoginWindow();
            loginWindow->show();
            loginWindow->resize(400, 300);
            QTimer::singleShot(1000, this, [this]() {
                captureWindow(loginWindow, "01_login_window.png");
                QTimer::singleShot(500, this, &ScreenshotHelper::captureNext);
            });
        }
        else if (currentStep == 1) {
            // Step 2: Capture Main Window - Dashboard (as Admin)
            qDebug() << "Capturing Main Window - Dashboard...";
            loginWindow->hide();
            
            // Create admin user
            User* adminUser = new User(1, "admin", "admin", "Admin");
            mainWindow = new MainWindow(adminUser);
            mainWindow->show();
            mainWindow->resize(1200, 700);
            
            QTimer::singleShot(1000, this, [this]() {
                captureWindow(mainWindow, "02_main_dashboard.png");
                QTimer::singleShot(500, this, &ScreenshotHelper::captureNext);
            });
        }
        else if (currentStep == 2) {
            // Step 3: Click "Add Vehicle" button
            qDebug() << "Capturing Add Vehicle Form...";
            // Find and click the Add Vehicle button
            auto buttons = mainWindow->findChildren<QPushButton*>();
            for (auto* btn : buttons) {
                if (btn->text() == "Add Vehicle") {
                    btn->click();
                    break;
                }
            }
            
            QTimer::singleShot(1000, this, [this]() {
                captureWindow(mainWindow, "03_add_vehicle_form.png");
                QTimer::singleShot(500, this, &ScreenshotHelper::captureNext);
            });
        }
        else if (currentStep == 3) {
            // Step 4: Click "Rent/Return" button
            qDebug() << "Capturing Rent/Return Interface...";
            auto buttons = mainWindow->findChildren<QPushButton*>();
            for (auto* btn : buttons) {
                if (btn->text() == "Rent/Return") {
                    btn->click();
                    break;
                }
            }
            
            QTimer::singleShot(1000, this, [this]() {
                captureWindow(mainWindow, "04_rent_return_interface.png");
                QTimer::singleShot(500, this, &ScreenshotHelper::captureNext);
            });
        }
        else if (currentStep == 4) {
            // Step 5: Click "Manage Customers" button
            qDebug() << "Capturing Customer Management...";
            auto buttons = mainWindow->findChildren<QPushButton*>();
            for (auto* btn : buttons) {
                if (btn->text() == "Manage Customers") {
                    btn->click();
                    break;
                }
            }
            
            QTimer::singleShot(1000, this, [this]() {
                captureWindow(mainWindow, "05_customer_management.png");
                QTimer::singleShot(500, this, &ScreenshotHelper::captureNext);
            });
        }
        else if (currentStep == 5) {
            // Step 6: Click "Reservations" button
            qDebug() << "Capturing Reservations View...";
            auto buttons = mainWindow->findChildren<QPushButton*>();
            for (auto* btn : buttons) {
                if (btn->text() == "Reservations") {
                    btn->click();
                    break;
                }
            }
            
            QTimer::singleShot(1000, this, [this]() {
                captureWindow(mainWindow, "06_reservations_view.png");
                QTimer::singleShot(500, this, &ScreenshotHelper::captureNext);
            });
        }
        else {
            // Done
            qDebug() << "All screenshots captured successfully!";
            QTimer::singleShot(500, app, &QApplication::quit);
            return;
        }
        
        currentStep++;
    }
    
    void captureWindow(QWidget* window, const QString& filename) {
        QString outputPath = QString("/home/runner/work/Vehicle-Rental-System/Vehicle-Rental-System/") + filename;
        QPixmap pixmap = window->grab();
        if (pixmap.save(outputPath)) {
            qDebug() << "Saved screenshot:" << outputPath;
        } else {
            qDebug() << "Failed to save screenshot:" << outputPath;
        }
    }
    
private:
    QApplication* app;
    LoginWindow* loginWindow = nullptr;
    MainWindow* mainWindow = nullptr;
    int currentStep;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    
    ScreenshotHelper helper(&app);
    helper.start();
    
    return app.exec();
}

#include "screenshot_main.moc"
