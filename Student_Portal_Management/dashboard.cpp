// dashboard.cpp
#include "dashboard.h"
#include "loginwindow.h"
#include "cgpa_calculator.h"
#include "course_management.h"
#include "payment_parking.h"
#include <QMessageBox>

Dashboard::Dashboard(QString username, QWidget *parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);
    studentInfoLabel = new QLabel("Student Dashboard for " + username, this);
    logoutButton = new QPushButton("Logout", this);
    openCGPAButton = new QPushButton("Open CGPA Calculator", this);
    openCourseManagementButton = new QPushButton("Course Enrollment & Analysis", this);
    openPaymentParkingButton = new QPushButton("Payment & Parking", this);

    layout->addWidget(studentInfoLabel);
    layout->addWidget(openCGPAButton);
    layout->addWidget(openCourseManagementButton);
    layout->addWidget(openPaymentParkingButton);
    layout->addWidget(logoutButton);

    connect(logoutButton, &QPushButton::clicked, this, &Dashboard::logout);
    connect(openCGPAButton, &QPushButton::clicked, this, &Dashboard::openCGPA);
    connect(openCourseManagementButton, &QPushButton::clicked, this, &Dashboard::openCourseManagement);
    connect(openPaymentParkingButton, &QPushButton::clicked, this, &Dashboard::openPaymentParking);
}

void Dashboard::logout() {
    this->close();
    LoginWindow *login = new LoginWindow();
    login->show();
}

void Dashboard::openCGPA() {
    CGPACalculator *calculator = new CGPACalculator();
    calculator->setAttribute(Qt::WA_DeleteOnClose);
    calculator->show();
}

void Dashboard::openCourseManagement() {
    // Opens the course enrollment and analysis widget
    CourseManagement *courseMng = new CourseManagement();
    courseMng->setAttribute(Qt::WA_DeleteOnClose);
    courseMng->show();
}

void Dashboard::openPaymentParking() {
    PaymentParking *payPark = new PaymentParking();
    payPark->setAttribute(Qt::WA_DeleteOnClose);
    payPark->show();
}
