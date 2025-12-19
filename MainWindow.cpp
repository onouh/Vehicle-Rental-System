#include "MainWindow.h"
#include "Car.h"
#include "Bike.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QMessageBox>
#include <QHeaderView>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), rentalManager(new RentalManager()) {
    setupUI();
    applyStyles();
    
    // Add some sample vehicles
    rentalManager->addVehicle(new Car(rentalManager->getNextId(), "Toyota", "Camry", 50.0, 4));
    rentalManager->addVehicle(new Car(rentalManager->getNextId(), "Honda", "Civic", 45.0, 4));
    rentalManager->addVehicle(new Bike(rentalManager->getNextId(), "Yamaha", "MT-07", 30.0, 689));
    rentalManager->addVehicle(new Bike(rentalManager->getNextId(), "Kawasaki", "Ninja 400", 35.0, 399));
    
    refreshVehicleTable();
}

MainWindow::~MainWindow() {
    delete rentalManager;
}

void MainWindow::setupUI() {
    setWindowTitle("Vehicle Rental System");
    resize(1000, 600);
    
    // Create central widget
    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    
    // Main layout
    QHBoxLayout* mainLayout = new QHBoxLayout(centralWidget);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);
    
    // Sidebar
    QWidget* sidebar = new QWidget();
    sidebar->setObjectName("sidebar");
    sidebar->setFixedWidth(200);
    QVBoxLayout* sidebarLayout = new QVBoxLayout(sidebar);
    sidebarLayout->setContentsMargins(10, 20, 10, 20);
    sidebarLayout->setSpacing(10);
    
    // Sidebar buttons
    QPushButton* dashboardBtn = new QPushButton("Dashboard");
    dashboardBtn->setObjectName("sidebarButton");
    connect(dashboardBtn, &QPushButton::clicked, this, &MainWindow::showDashboard);
    
    QPushButton* addVehicleBtn = new QPushButton("Add Vehicle");
    addVehicleBtn->setObjectName("sidebarButton");
    connect(addVehicleBtn, &QPushButton::clicked, this, &MainWindow::showAddVehicleForm);
    
    QPushButton* rentReturnBtn = new QPushButton("Rent/Return");
    rentReturnBtn->setObjectName("sidebarButton");
    connect(rentReturnBtn, &QPushButton::clicked, this, &MainWindow::showRentReturnForm);
    
    sidebarLayout->addWidget(dashboardBtn);
    sidebarLayout->addWidget(addVehicleBtn);
    sidebarLayout->addWidget(rentReturnBtn);
    sidebarLayout->addStretch();
    
    // Stacked widget for content
    stackedWidget = new QStackedWidget();
    
    createDashboard();
    createAddVehicleForm();
    createRentReturnForm();
    
    // Add widgets to main layout
    mainLayout->addWidget(sidebar);
    mainLayout->addWidget(stackedWidget, 1);
}

void MainWindow::applyStyles() {
    QString styleSheet = R"(
        QMainWindow {
            background-color: #2b2b2b;
        }
        
        QWidget#sidebar {
            background-color: #1e1e1e;
            border-right: 1px solid #3d3d3d;
        }
        
        QPushButton#sidebarButton {
            background-color: #3d3d3d;
            color: #ffffff;
            border: none;
            border-radius: 5px;
            padding: 12px;
            text-align: left;
            font-size: 14px;
        }
        
        QPushButton#sidebarButton:hover {
            background-color: #6a5acd;
        }
        
        QPushButton#sidebarButton:pressed {
            background-color: #5a4abd;
        }
        
        QWidget#contentWidget {
            background-color: #2b2b2b;
        }
        
        QLabel {
            color: #ffffff;
            font-size: 14px;
        }
        
        QLabel#titleLabel {
            color: #ffffff;
            font-size: 24px;
            font-weight: bold;
            margin: 20px 0;
        }
        
        QTableWidget {
            background-color: #353535;
            color: #ffffff;
            border: 1px solid #3d3d3d;
            border-radius: 5px;
            gridline-color: #3d3d3d;
        }
        
        QTableWidget::item {
            padding: 8px;
        }
        
        QTableWidget::item:selected {
            background-color: #6a5acd;
        }
        
        QHeaderView::section {
            background-color: #1e1e1e;
            color: #ffffff;
            padding: 10px;
            border: none;
            border-bottom: 2px solid #6a5acd;
            font-weight: bold;
        }
        
        QLineEdit, QSpinBox, QDoubleSpinBox, QComboBox {
            background-color: #353535;
            color: #ffffff;
            border: 1px solid #3d3d3d;
            border-radius: 5px;
            padding: 8px;
            font-size: 14px;
        }
        
        QLineEdit:focus, QSpinBox:focus, QDoubleSpinBox:focus, QComboBox:focus {
            border: 1px solid #6a5acd;
        }
        
        QComboBox::drop-down {
            border: none;
            width: 30px;
        }
        
        QComboBox::down-arrow {
            image: none;
            border-left: 5px solid transparent;
            border-right: 5px solid transparent;
            border-top: 5px solid #ffffff;
            margin-right: 10px;
        }
        
        QComboBox QAbstractItemView {
            background-color: #353535;
            color: #ffffff;
            selection-background-color: #6a5acd;
            border: 1px solid #3d3d3d;
        }
        
        QPushButton {
            background-color: #6a5acd;
            color: #ffffff;
            border: none;
            border-radius: 5px;
            padding: 10px 20px;
            font-size: 14px;
            font-weight: bold;
        }
        
        QPushButton:hover {
            background-color: #7b6bd8;
        }
        
        QPushButton:pressed {
            background-color: #5a4abd;
        }
        
        QPushButton:disabled {
            background-color: #3d3d3d;
            color: #666666;
        }
        
        QPushButton#removeButton {
            background-color: #d32f2f;
        }
        
        QPushButton#removeButton:hover {
            background-color: #e53935;
        }
        
        QPushButton#removeButton:pressed {
            background-color: #c62828;
        }
    )";
    
    setStyleSheet(styleSheet);
}

void MainWindow::createDashboard() {
    QWidget* dashboardWidget = new QWidget();
    dashboardWidget->setObjectName("contentWidget");
    QVBoxLayout* layout = new QVBoxLayout(dashboardWidget);
    layout->setContentsMargins(30, 30, 30, 30);
    layout->setSpacing(20);
    
    // Title
    QLabel* titleLabel = new QLabel("Vehicle Fleet Dashboard");
    titleLabel->setObjectName("titleLabel");
    layout->addWidget(titleLabel);
    
    // Search bar
    QHBoxLayout* searchLayout = new QHBoxLayout();
    searchLayout->setSpacing(10);
    
    QLabel* searchLabel = new QLabel("Search:");
    searchInput = new QLineEdit();
    searchInput->setPlaceholderText("Enter search term...");
    searchInput->setMinimumWidth(300);
    connect(searchInput, &QLineEdit::textChanged, this, &MainWindow::onSearchTextChanged);
    
    searchFilterCombo = new QComboBox();
    searchFilterCombo->addItems({"All", "ID", "Type", "Brand", "Model", "Status"});
    searchFilterCombo->setMinimumWidth(120);
    connect(searchFilterCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::onSearchTextChanged);
    
    searchLayout->addWidget(searchLabel);
    searchLayout->addWidget(searchInput);
    searchLayout->addWidget(searchFilterCombo);
    searchLayout->addStretch();
    
    layout->addLayout(searchLayout);
    
    // Table
    vehicleTable = new QTableWidget();
    vehicleTable->setColumnCount(6);
    vehicleTable->setHorizontalHeaderLabels({"ID", "Type", "Brand", "Model", "Rate/Day", "Status"});
    vehicleTable->horizontalHeader()->setStretchLastSection(true);
    vehicleTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    vehicleTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    vehicleTable->setSelectionMode(QAbstractItemView::SingleSelection);
    vehicleTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    layout->addWidget(vehicleTable);
    
    // Button row
    QHBoxLayout* buttonLayout = new QHBoxLayout();
    buttonLayout->setSpacing(10);
    
    QPushButton* refreshBtn = new QPushButton("Refresh");
    connect(refreshBtn, &QPushButton::clicked, this, &MainWindow::refreshVehicleTable);
    
    QPushButton* removeBtn = new QPushButton("Remove Selected");
    removeBtn->setObjectName("removeButton");
    connect(removeBtn, &QPushButton::clicked, this, &MainWindow::removeSelectedVehicle);
    
    buttonLayout->addWidget(refreshBtn);
    buttonLayout->addWidget(removeBtn);
    buttonLayout->addStretch();
    
    layout->addLayout(buttonLayout);
    
    stackedWidget->addWidget(dashboardWidget);
}

void MainWindow::createAddVehicleForm() {
    QWidget* formWidget = new QWidget();
    formWidget->setObjectName("contentWidget");
    QVBoxLayout* layout = new QVBoxLayout(formWidget);
    layout->setContentsMargins(30, 30, 30, 30);
    layout->setSpacing(20);
    
    // Title
    QLabel* titleLabel = new QLabel("Add New Vehicle");
    titleLabel->setObjectName("titleLabel");
    layout->addWidget(titleLabel);
    
    // Form
    QFormLayout* formLayout = new QFormLayout();
    formLayout->setSpacing(15);
    formLayout->setLabelAlignment(Qt::AlignRight);
    
    typeComboBox = new QComboBox();
    typeComboBox->addItem("Car");
    typeComboBox->addItem("Bike");
    connect(typeComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::onVehicleTypeChanged);
    formLayout->addRow("Vehicle Type:", typeComboBox);
    
    brandInput = new QLineEdit();
    brandInput->setPlaceholderText("Enter brand name");
    formLayout->addRow("Brand:", brandInput);
    
    modelInput = new QLineEdit();
    modelInput->setPlaceholderText("Enter model name");
    formLayout->addRow("Model:", modelInput);
    
    baseRateInput = new QLineEdit();
    baseRateInput->setPlaceholderText("Enter daily rate");
    formLayout->addRow("Base Rate ($/day):", baseRateInput);
    
    // Number of doors (Car only)
    numDoorsWidget = new QWidget();
    QHBoxLayout* doorsLayout = new QHBoxLayout(numDoorsWidget);
    doorsLayout->setContentsMargins(0, 0, 0, 0);
    QLabel* doorsLabel = new QLabel("Number of Doors:");
    numDoorsInput = new QSpinBox();
    numDoorsInput->setRange(2, 5);
    numDoorsInput->setValue(4);
    doorsLayout->addWidget(doorsLabel);
    doorsLayout->addWidget(numDoorsInput);
    doorsLayout->addStretch();
    layout->addWidget(numDoorsWidget);
    
    // Engine capacity (Bike only)
    engineCapacityWidget = new QWidget();
    QHBoxLayout* engineLayout = new QHBoxLayout(engineCapacityWidget);
    engineLayout->setContentsMargins(0, 0, 0, 0);
    QLabel* engineLabel = new QLabel("Engine Capacity:");
    engineCapacityInput = new QSpinBox();
    engineCapacityInput->setRange(50, 2000);
    engineCapacityInput->setValue(500);
    engineCapacityInput->setSuffix(" cc");
    engineLayout->addWidget(engineLabel);
    engineLayout->addWidget(engineCapacityInput);
    engineLayout->addStretch();
    engineCapacityWidget->hide();
    layout->addWidget(engineCapacityWidget);
    
    layout->addLayout(formLayout);
    
    // Add button
    QHBoxLayout* buttonLayout = new QHBoxLayout();
    QPushButton* addBtn = new QPushButton("Add Vehicle");
    connect(addBtn, &QPushButton::clicked, this, &MainWindow::addVehicle);
    buttonLayout->addWidget(addBtn);
    buttonLayout->addStretch();
    
    layout->addLayout(buttonLayout);
    layout->addStretch();
    
    stackedWidget->addWidget(formWidget);
}

void MainWindow::createRentReturnForm() {
    QWidget* rentWidget = new QWidget();
    rentWidget->setObjectName("contentWidget");
    QVBoxLayout* layout = new QVBoxLayout(rentWidget);
    layout->setContentsMargins(30, 30, 30, 30);
    layout->setSpacing(20);
    
    // Title
    QLabel* titleLabel = new QLabel("Rent or Return Vehicle");
    titleLabel->setObjectName("titleLabel");
    layout->addWidget(titleLabel);
    
    // Instructions
    QLabel* instructionLabel = new QLabel(
        "Select a vehicle from the table below and choose an action:");
    layout->addWidget(instructionLabel);
    
    // Table (reuse the main table reference)
    QTableWidget* rentTable = new QTableWidget();
    rentTable->setColumnCount(6);
    rentTable->setHorizontalHeaderLabels({"ID", "Type", "Brand", "Model", "Rate/Day", "Status"});
    rentTable->horizontalHeader()->setStretchLastSection(true);
    rentTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    rentTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    rentTable->setSelectionMode(QAbstractItemView::SingleSelection);
    rentTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    
    // Populate table
    const auto& fleet = rentalManager->getFleet();
    rentTable->setRowCount(fleet.size());
    
    for (size_t i = 0; i < fleet.size(); ++i) {
        Vehicle* v = fleet[i];
        rentTable->setItem(i, 0, new QTableWidgetItem(QString::number(v->getId())));
        rentTable->setItem(i, 1, new QTableWidgetItem(v->getType()));
        rentTable->setItem(i, 2, new QTableWidgetItem(v->getBrand()));
        rentTable->setItem(i, 3, new QTableWidgetItem(v->getModel()));
        rentTable->setItem(i, 4, new QTableWidgetItem(QString("$%1").arg(v->getBaseRate(), 0, 'f', 2)));
        rentTable->setItem(i, 5, new QTableWidgetItem(v->getIsRented() ? "Rented" : "Available"));
    }
    
    layout->addWidget(rentTable);
    
    // Buttons
    QHBoxLayout* buttonLayout = new QHBoxLayout();
    buttonLayout->setSpacing(10);
    
    QPushButton* rentBtn = new QPushButton("Rent Selected");
    connect(rentBtn, &QPushButton::clicked, [this, rentTable]() {
        int currentRow = rentTable->currentRow();
        if (currentRow < 0) {
            QMessageBox::warning(this, "No Selection", "Please select a vehicle to rent.");
            return;
        }
        
        int vehicleId = rentTable->item(currentRow, 0)->text().toInt();
        
        if (rentalManager->rentVehicle(vehicleId)) {
            QMessageBox::information(this, "Success", "Vehicle rented successfully!");
            // Refresh the table
            const auto& fleet = rentalManager->getFleet();
            for (size_t i = 0; i < fleet.size(); ++i) {
                Vehicle* v = fleet[i];
                if (v->getId() == vehicleId) {
                    rentTable->setItem(i, 5, new QTableWidgetItem(v->getIsRented() ? "Rented" : "Available"));
                    break;
                }
            }
            onSearchTextChanged(); // Preserve search state on dashboard
        } else {
            QMessageBox::warning(this, "Error", "This vehicle is already rented or not found.");
        }
    });
    
    QPushButton* returnBtn = new QPushButton("Return Selected");
    connect(returnBtn, &QPushButton::clicked, [this, rentTable]() {
        int currentRow = rentTable->currentRow();
        if (currentRow < 0) {
            QMessageBox::warning(this, "No Selection", "Please select a vehicle to return.");
            return;
        }
        
        int vehicleId = rentTable->item(currentRow, 0)->text().toInt();
        
        if (rentalManager->returnVehicle(vehicleId)) {
            QMessageBox::information(this, "Success", "Vehicle returned successfully!");
            // Refresh the table
            const auto& fleet = rentalManager->getFleet();
            for (size_t i = 0; i < fleet.size(); ++i) {
                Vehicle* v = fleet[i];
                if (v->getId() == vehicleId) {
                    rentTable->setItem(i, 5, new QTableWidgetItem(v->getIsRented() ? "Rented" : "Available"));
                    break;
                }
            }
            onSearchTextChanged(); // Preserve search state on dashboard
        } else {
            QMessageBox::warning(this, "Error", "This vehicle is not currently rented or not found.");
        }
    });
    
    buttonLayout->addWidget(rentBtn);
    buttonLayout->addWidget(returnBtn);
    buttonLayout->addStretch();
    
    layout->addLayout(buttonLayout);
    
    stackedWidget->addWidget(rentWidget);
}

void MainWindow::refreshVehicleTable() {
    const auto& fleet = rentalManager->getFleet();
    populateTable(fleet);
}

void MainWindow::populateTable(const std::vector<Vehicle*>& vehicles) {
    vehicleTable->setRowCount(vehicles.size());
    
    for (size_t i = 0; i < vehicles.size(); ++i) {
        Vehicle* v = vehicles[i];
        vehicleTable->setItem(i, 0, new QTableWidgetItem(QString::number(v->getId())));
        vehicleTable->setItem(i, 1, new QTableWidgetItem(v->getType()));
        vehicleTable->setItem(i, 2, new QTableWidgetItem(v->getBrand()));
        vehicleTable->setItem(i, 3, new QTableWidgetItem(v->getModel()));
        vehicleTable->setItem(i, 4, new QTableWidgetItem(QString("$%1").arg(v->getBaseRate(), 0, 'f', 2)));
        vehicleTable->setItem(i, 5, new QTableWidgetItem(v->getIsRented() ? "Rented" : "Available"));
    }
}

void MainWindow::showDashboard() {
    stackedWidget->setCurrentIndex(0);
    onSearchTextChanged(); // Refresh with current search state
}

void MainWindow::showAddVehicleForm() {
    stackedWidget->setCurrentIndex(1);
}

void MainWindow::showRentReturnForm() {
    stackedWidget->setCurrentIndex(2);
}

void MainWindow::addVehicle() {
    QString brand = brandInput->text().trimmed();
    QString model = modelInput->text().trimmed();
    QString rateStr = baseRateInput->text().trimmed();
    
    if (brand.isEmpty() || model.isEmpty() || rateStr.isEmpty()) {
        QMessageBox::warning(this, "Invalid Input", "Please fill in all required fields.");
        return;
    }
    
    bool ok;
    double rate = rateStr.toDouble(&ok);
    if (!ok || rate <= 0) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid base rate.");
        return;
    }
    
    int id = rentalManager->getNextId();
    Vehicle* vehicle = nullptr;
    
    if (typeComboBox->currentText() == "Car") {
        int numDoors = numDoorsInput->value();
        vehicle = new Car(id, brand, model, rate, numDoors);
    } else {
        int engineCapacity = engineCapacityInput->value();
        vehicle = new Bike(id, brand, model, rate, engineCapacity);
    }
    
    rentalManager->addVehicle(vehicle);
    
    // Clear inputs
    brandInput->clear();
    modelInput->clear();
    baseRateInput->clear();
    
    QMessageBox::information(this, "Success", "Vehicle added successfully!");
    onSearchTextChanged(); // Preserve search state
}

void MainWindow::removeSelectedVehicle() {
    int currentRow = vehicleTable->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "No Selection", "Please select a vehicle to remove.");
        return;
    }
    
    int vehicleId = vehicleTable->item(currentRow, 0)->text().toInt();
    
    QMessageBox::StandardButton reply = QMessageBox::question(
        this, "Confirm Removal", 
        "Are you sure you want to remove this vehicle?",
        QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        if (rentalManager->removeVehicle(vehicleId)) {
            QMessageBox::information(this, "Success", "Vehicle removed successfully!");
            onSearchTextChanged(); // Preserve search state
        } else {
            QMessageBox::warning(this, "Error", "Failed to remove vehicle.");
        }
    }
}

void MainWindow::rentSelectedVehicle() {
    int currentRow = vehicleTable->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "No Selection", "Please select a vehicle to rent.");
        return;
    }
    
    int vehicleId = vehicleTable->item(currentRow, 0)->text().toInt();
    
    if (rentalManager->rentVehicle(vehicleId)) {
        QMessageBox::information(this, "Success", "Vehicle rented successfully!");
        onSearchTextChanged(); // Preserve search state
    } else {
        QMessageBox::warning(this, "Error", "This vehicle is already rented or not found.");
    }
}

void MainWindow::returnSelectedVehicle() {
    int currentRow = vehicleTable->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "No Selection", "Please select a vehicle to return.");
        return;
    }
    
    int vehicleId = vehicleTable->item(currentRow, 0)->text().toInt();
    
    if (rentalManager->returnVehicle(vehicleId)) {
        QMessageBox::information(this, "Success", "Vehicle returned successfully!");
        onSearchTextChanged(); // Preserve search state
    } else {
        QMessageBox::warning(this, "Error", "This vehicle is not currently rented or not found.");
    }
}

void MainWindow::onVehicleTypeChanged(int index) {
    if (index == 0) { // Car
        numDoorsWidget->show();
        engineCapacityWidget->hide();
    } else { // Bike
        numDoorsWidget->hide();
        engineCapacityWidget->show();
    }
}

void MainWindow::onSearchTextChanged() {
    QString searchTerm = searchInput->text().trimmed();
    QString filterType = searchFilterCombo->currentText();
    
    // Get filtered vehicles
    std::vector<Vehicle*> filteredVehicles = rentalManager->searchVehicles(searchTerm, filterType);
    
    // Update table with filtered results
    populateTable(filteredVehicles);
}
