// loginwindow.cpp
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

    loginButton = new QPushButton("Login", this);
    signupButton = new QPushButton("Sign Up", this);

    layout->addWidget(title);
    layout->addWidget(usernameInput);
    layout->addWidget(passwordInput);
    layout->addWidget(loginButton);
    layout->addWidget(signupButton);

    connect(loginButton, &QPushButton::clicked, this, &LoginWindow::attemptLogin);
    connect(signupButton, &QPushButton::clicked, this, &LoginWindow::attemptSignup);
}

void LoginWindow::attemptLogin() {
    QString username = usernameInput->text();
    QString password = passwordInput->text();
    QByteArray hashedPassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex();

    // For simplicity, we use the CSV file 'users.csv'
    QFile file("users.csv");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QStringList data = in.readLine().split(",");
            if (data.size() >= 2 && data[0] == username && data[1] == hashedPassword) {
                QMessageBox::information(this, "Login Success", "Welcome to the student portal.");
                this->close();
                Dashboard *dashboard = new Dashboard(username);
                dashboard->show();
                return;
            }
        }
    }
    QMessageBox::warning(this, "Login Failed", "Invalid username or password.");
}

void LoginWindow::attemptSignup() {
    QString username = usernameInput->text();
    QString password = passwordInput->text();
    QByteArray hashedPassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex();

    // Here, you could add additional signup details if needed.
    QFile file("users.csv");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        // Storing only username and hashed password for simplicity.
        out << username << "," << hashedPassword << "\n";
        QMessageBox::information(this, "Signup Success", "Account created successfully. Please log in.");
    }
}
