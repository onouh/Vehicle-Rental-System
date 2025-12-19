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

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    RentalManager* rentalManager;
    
    // Main widgets
    QStackedWidget* stackedWidget;
    QTableWidget* vehicleTable;
    
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
    
    // Methods
    void setupUI();
    void applyStyles();
    void createDashboard();
    void createAddVehicleForm();
    void createRentReturnForm();
    void refreshVehicleTable();
    void populateTable(const std::vector<Vehicle*>& vehicles);

private slots:
    void showDashboard();
    void showAddVehicleForm();
    void showRentReturnForm();
    void addVehicle();
    void removeSelectedVehicle();
    void rentSelectedVehicle();
    void returnSelectedVehicle();
    void onVehicleTypeChanged(int index);
    void onSearchTextChanged();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};

#endif // MAINWINDOW_H
