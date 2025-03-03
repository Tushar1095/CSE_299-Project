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
    QPushButton *editInfoButton;
    QPushButton *logoutButton;

public:
    explicit Dashboard(QString username, QWidget *parent = nullptr);

private slots:
    void editStudentInfo();
    void logout();
};

#endif
