// dashboard.h
#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

class Dashboard : public QWidget {
    Q_OBJECT

private:
    QLabel *studentInfoLabel;
    QPushButton *logoutButton;
    QPushButton *openCGPAButton;
    QPushButton *openCourseManagementButton;
    QPushButton *openPaymentParkingButton;

public:
    explicit Dashboard(QString username, QWidget *parent = nullptr);

private slots:
    void logout();
    void openCGPA();
    void openCourseManagement();
    void openPaymentParking();
};

#endif
