#include "loginwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QCryptographicHash>

LoginWindow::LoginWindow(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *title = new QLabel("Student Portal Login", this);

    usernameInput = new QLineEdit(this);
    usernameInput->setPlaceholderText("Username");
    passwordInput = new QLineEdit(this);
    passwordInput->setPlaceholderText("Password");
    passwordInput->setEchoMode(QLineEdit::Password);

    parentNameInput = new QLineEdit(this);
    parentNameInput->setPlaceholderText("Parent's Name");
    birthDateInput = new QLineEdit(this);
    birthDateInput->setPlaceholderText("Birth Date (YYYY-MM-DD)");
    nationalityInput = new QLineEdit(this);
    nationalityInput->setPlaceholderText("Nationality");
    bloodGroupInput = new QLineEdit(this);
    bloodGroupInput->setPlaceholderText("Blood Group");
    idNumberInput = new QLineEdit(this);
    idNumberInput->setPlaceholderText("ID Number");

    uploadPhotoButton = new QPushButton("Upload Photo", this);
    loginButton = new QPushButton("Login", this);
    signupButton = new QPushButton("Sign Up", this);

    layout->addWidget(title);
    layout->addWidget(usernameInput);
    layout->addWidget(passwordInput);
    layout->addWidget(parentNameInput);
    layout->addWidget(birthDateInput);
    layout->addWidget(nationalityInput);
    layout->addWidget(bloodGroupInput);
    layout->addWidget(idNumberInput);
    layout->addWidget(uploadPhotoButton);
    layout->addWidget(loginButton);
    layout->addWidget(signupButton);

    connect(loginButton, &QPushButton::clicked, this, &LoginWindow::attemptLogin);
    connect(signupButton, &QPushButton::clicked, this, &LoginWindow::attemptSignup);
    connect(uploadPhotoButton, &QPushButton::clicked, this, &LoginWindow::uploadPhoto);
}

void LoginWindow::attemptSignup() {
    QString username = usernameInput->text();
    QString password = passwordInput->text();
    QByteArray hashedPassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex();

    QString parentName = parentNameInput->text();
    QString birthDate = birthDateInput->text();
    QString nationality = nationalityInput->text();
    QString bloodGroup = bloodGroupInput->text();
    QString idNumber = idNumberInput->text();

    QFile file("users.csv");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << username << "," << hashedPassword << "," << parentName << "," << birthDate << ","
            << nationality << "," << bloodGroup << "," << idNumber << "," << photoPath << "\n";
        QMessageBox::information(this, "Signup Success", "Account created successfully. Please log in.");
    }
}
