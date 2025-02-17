#include "mainwindow.h"
#include "ui_mainwindow.h" // Include the generated UI header
#include <QMessageBox> // For QMessageBox

// Constructor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) // Initialize the UI
{
    ui->setupUi(this); // Set up the UI
    connect(ui->loginButton, &QPushButton::clicked, this, &MainWindow::on_loginButton_clicked); // Connect button click to slot
}

// Destructor
MainWindow::~MainWindow()
{
    delete ui; // Clean up the UI
}

// Slot for handling login button click
void MainWindow::on_loginButton_clicked()
{
    QString username = ui->usernameLineEdit->text(); // Get username
    QString password = ui->passwordLineEdit->text(); // Get password

    // Hardcoded credentials for demonstration
    if (username == "student" && password == "password123") {
        QMessageBox::information(this, "Login", "Login Successful!"); // Show success message
    } else {
        QMessageBox::warning(this, "Login", "Invalid username or password."); // Show error message
    }
}