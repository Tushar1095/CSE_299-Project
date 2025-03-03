#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QFileDialog>
#include "dashboard.h"

class LoginWindow : public QWidget {
    Q_OBJECT

private:
    QLineEdit *usernameInput;
    QLineEdit *passwordInput;
    QLineEdit *parentNameInput;
    QLineEdit *birthDateInput;
    QLineEdit *nationalityInput;
    QLineEdit *bloodGroupInput;
    QLineEdit *idNumberInput;
    QPushButton *uploadPhotoButton;
    QPushButton *loginButton;
    QPushButton *signupButton;
    QString photoPath;

public:
    explicit LoginWindow(QWidget *parent = nullptr);

private slots:
    void attemptLogin();
    void attemptSignup();
    void uploadPhoto();
};

#endif
