#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QTableWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QSpinBox>
#include "RentalManager.h"
#include "User.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    RentalManager* rentalManager;
    User* currentUser;  // Current logged-in user
    
    // Main widgets
    QStackedWidget* stackedWidget;
    QTableWidget* vehicleTable;
    QTableWidget* customerTable;
    QTableWidget* reservationTable;
    QTableWidget* dbVehicleTable;  // For database-driven vehicle view
    
    // Search widgets
    QLineEdit* searchInput;
    QComboBox* searchFilterCombo;
    
    // Input widgets for adding vehicles
    QLineEdit* brandInput;
    QLineEdit* modelInput;
    QLineEdit* baseRateInput;
    QComboBox* typeComboBox;
    QSpinBox* numDoorsInput;
    QSpinBox* engineCapacityInput;
    QWidget* numDoorsWidget;
    QWidget* engineCapacityWidget;
    
    // Input widgets for adding customers
    QLineEdit* customerNameInput;
    QLineEdit* customerEmailInput;
    QLineEdit* customerPhoneInput;
    
    // Methods
    void setupUI();
    void applyStyles();
    void createDashboard();
    void createAddVehicleForm();
    void createRentReturnForm();
    void createCustomerManagementView();
    void createReservationView();
    void refreshVehicleTable();
    void refreshVehicleTableFromDB();
    void populateTable(const std::vector<Vehicle*>& vehicles);
    void refreshCustomerTable();

private slots:
    void showDashboard();
    void showAddVehicleForm();
    void showRentReturnForm();
    void showCustomerManagement();
    void showReservations();
    void addVehicle();
    void removeSelectedVehicle();
    void rentSelectedVehicle();
    void returnSelectedVehicle();
    void addCustomer();
    void removeSelectedCustomer();
    void onVehicleTypeChanged(int index);
    void onSearchTextChanged();

public:
    MainWindow(User* user = nullptr, QWidget *parent = nullptr);
    ~MainWindow();
};

#endif // MAINWINDOW_H
