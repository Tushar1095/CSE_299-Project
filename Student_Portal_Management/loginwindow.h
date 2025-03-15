// loginwindow.h
#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include "dashboard.h"

class LoginWindow : public QWidget {
    Q_OBJECT

private:
    QLineEdit *usernameInput;
    QLineEdit *passwordInput;
    QPushButton *loginButton;
    QPushButton *signupButton;

public:
    explicit LoginWindow(QWidget *parent = nullptr);

private slots:
    void attemptLogin();
    void attemptSignup();
};

#endif
