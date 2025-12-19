#include "LoginWindow.h"
#include "DatabaseManager.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QMessageBox>
#include <QInputDialog>
#include <QComboBox>
#include <QDialog>

LoginWindow::LoginWindow(QWidget *parent) : QWidget(parent) {
    authManager = new AuthManager();
    setupUI();
    applyStyles();
}

LoginWindow::~LoginWindow() {
    delete authManager;
}

void LoginWindow::setupUI() {
    // Main layout
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(50, 50, 50, 50);
    mainLayout->setSpacing(20);
    
    // Title
    QLabel* titleLabel = new QLabel("Vehicle Rental System");
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-size: 24px; font-weight: bold; margin-bottom: 20px;");
    mainLayout->addWidget(titleLabel);
    
    // Form layout
    QFormLayout* formLayout = new QFormLayout();
    formLayout->setSpacing(15);
    
    usernameInput = new QLineEdit();
    usernameInput->setPlaceholderText("Enter username");
    formLayout->addRow("Username:", usernameInput);
    
    passwordInput = new QLineEdit();
    passwordInput->setPlaceholderText("Enter password");
    passwordInput->setEchoMode(QLineEdit::Password);
    formLayout->addRow("Password:", passwordInput);
    
    mainLayout->addLayout(formLayout);
    
    // Status label
    statusLabel = new QLabel("");
    statusLabel->setAlignment(Qt::AlignCenter);
    statusLabel->setStyleSheet("color: #ff6b6b;");
    mainLayout->addWidget(statusLabel);
    
    // Buttons
    QHBoxLayout* buttonLayout = new QHBoxLayout();
    
    loginButton = new QPushButton("Login");
    loginButton->setMinimumHeight(40);
    connect(loginButton, &QPushButton::clicked, this, &LoginWindow::onLoginClicked);
    buttonLayout->addWidget(loginButton);
    
    registerButton = new QPushButton("Register");
    registerButton->setMinimumHeight(40);
    connect(registerButton, &QPushButton::clicked, this, &LoginWindow::onRegisterClicked);
    buttonLayout->addWidget(registerButton);
    
    mainLayout->addLayout(buttonLayout);
    
    // Add stretch to center content
    mainLayout->addStretch();
    
    setLayout(mainLayout);
    setWindowTitle("Login - Vehicle Rental System");
    setMinimumSize(400, 350);
}

void LoginWindow::applyStyles() {
    setStyleSheet(R"(
        QWidget {
            background-color: #2b2b2b;
            color: #ffffff;
        }
        QLineEdit {
            padding: 8px;
            border: 2px solid #3d3d3d;
            border-radius: 5px;
            background-color: #1e1e1e;
            color: #ffffff;
            min-height: 30px;
        }
        QLineEdit:focus {
            border: 2px solid #6a5acd;
        }
        QPushButton {
            padding: 10px;
            border: none;
            border-radius: 5px;
            background-color: #6a5acd;
            color: #ffffff;
            font-weight: bold;
        }
        QPushButton:hover {
            background-color: #7b68ee;
        }
        QPushButton:pressed {
            background-color: #5a4abd;
        }
        QLabel {
            color: #ffffff;
        }
    )");
}

void LoginWindow::onLoginClicked() {
    QString username = usernameInput->text().trimmed();
    QString password = passwordInput->text();
    
    if (username.isEmpty() || password.isEmpty()) {
        statusLabel->setText("Please enter both username and password");
        return;
    }
    
    if (authManager->login(username, password)) {
        statusLabel->setStyleSheet("color: #4caf50;");
        statusLabel->setText("Login successful!");
        
        User* user = authManager->getCurrentUser();
        emit loginSuccessful(user);
        
        // Close the login window
        close();
    } else {
        statusLabel->setStyleSheet("color: #ff6b6b;");
        statusLabel->setText("Invalid username or password");
        passwordInput->clear();
    }
}

void LoginWindow::onRegisterClicked() {
    // Create a dialog for registration
    QDialog* registerDialog = new QDialog(this);
    registerDialog->setWindowTitle("Register New User");
    registerDialog->setMinimumWidth(400);
    
    QVBoxLayout* layout = new QVBoxLayout(registerDialog);
    QFormLayout* formLayout = new QFormLayout();
    
    QLineEdit* newUsernameInput = new QLineEdit();
    QLineEdit* newPasswordInput = new QLineEdit();
    newPasswordInput->setEchoMode(QLineEdit::Password);
    QLineEdit* confirmPasswordInput = new QLineEdit();
    confirmPasswordInput->setEchoMode(QLineEdit::Password);
    QComboBox* roleComboBox = new QComboBox();
    roleComboBox->addItem("customer");
    roleComboBox->addItem("admin");
    QLineEdit* contactInput = new QLineEdit();
    QLineEdit* licenseInput = new QLineEdit();
    
    formLayout->addRow("Username:", newUsernameInput);
    formLayout->addRow("Password:", newPasswordInput);
    formLayout->addRow("Confirm Password:", confirmPasswordInput);
    formLayout->addRow("Role:", roleComboBox);
    formLayout->addRow("Contact Info:", contactInput);
    formLayout->addRow("License Number:", licenseInput);
    
    layout->addLayout(formLayout);
    
    QHBoxLayout* buttonLayout = new QHBoxLayout();
    QPushButton* okButton = new QPushButton("Register");
    QPushButton* cancelButton = new QPushButton("Cancel");
    
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);
    layout->addLayout(buttonLayout);
    
    // Apply dark theme to dialog
    registerDialog->setStyleSheet(this->styleSheet());
    
    connect(okButton, &QPushButton::clicked, [=]() {
        QString username = newUsernameInput->text().trimmed();
        QString password = newPasswordInput->text();
        QString confirmPassword = confirmPasswordInput->text();
        QString role = roleComboBox->currentText();
        QString contact = contactInput->text().trimmed();
        QString license = licenseInput->text().trimmed();
        
        if (username.isEmpty() || password.isEmpty()) {
            QMessageBox::warning(registerDialog, "Error", "Username and password are required!");
            return;
        }
        
        if (password != confirmPassword) {
            QMessageBox::warning(registerDialog, "Error", "Passwords do not match!");
            return;
        }
        
        if (authManager->registerUser(username, password, role, contact, license)) {
            QMessageBox::information(registerDialog, "Success", "User registered successfully!\nYou can now login.");
            registerDialog->accept();
        } else {
            QMessageBox::warning(registerDialog, "Error", "Registration failed. Username may already exist.");
        }
    });
    
    connect(cancelButton, &QPushButton::clicked, registerDialog, &QDialog::reject);
    
    registerDialog->exec();
    delete registerDialog;
}
