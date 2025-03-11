// course_management.h
#ifndef COURSE_MANAGEMENT_H
#define COURSE_MANAGEMENT_H

#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QLabel>

class CourseManagement : public QWidget {
    Q_OBJECT
private:
    QComboBox *courseDropdown;
    QPushButton *enrollButton;
    QTableWidget *coursesTable;
public:
    explicit CourseManagement(QWidget *parent = nullptr);
signals:
    void courseEnrolled(const QString &course);
private slots:
    void enrollInCourse();
};

#endif // COURSE_MANAGEMENT_H
