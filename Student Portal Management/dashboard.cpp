#include "dashboard.h"
#include "loginwindow.h"
#include <QMessageBox>

Dashboard::Dashboard(QString username, QWidget *parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    studentInfoLabel = new QLabel("Student Information for " + username, this);
    editInfoButton = new QPushButton("Edit Information", this);
    logoutButton = new QPushButton("Logout", this);

    layout->addWidget(studentInfoLabel);
    layout->addWidget(editInfoButton);
    layout->addWidget(logoutButton);

    connect(editInfoButton, &QPushButton::clicked, this, &Dashboard::editStudentInfo);
    connect(logoutButton, &QPushButton::clicked, this, &Dashboard::logout);
}

void Dashboard::editStudentInfo() {
    QMessageBox::information(this, "Edit Info", "Feature to edit student details.");
}

void Dashboard::logout() {
    this->close();
    LoginWindow *login = new LoginWindow();
    login->show();
}
