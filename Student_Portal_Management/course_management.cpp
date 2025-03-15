// course_management.cpp
#include "course_management.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QTableWidgetItem>

CourseManagement::CourseManagement(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *title = new QLabel("Course Enrollment & Analysis", this);
    courseDropdown = new QComboBox(this);
    courseDropdown->addItems({"Math", "Physics", "Chemistry", "Computer Science"});
    enrollButton = new QPushButton("Enroll", this);
    coursesTable = new QTableWidget(0, 2, this);
    coursesTable->setHorizontalHeaderLabels({"Course", "Status"});

    layout->addWidget(title);
    layout->addWidget(courseDropdown);
    layout->addWidget(enrollButton);
    layout->addWidget(coursesTable);

    connect(enrollButton, &QPushButton::clicked, this, &CourseManagement::enrollInCourse);
}

void CourseManagement::enrollInCourse() {
    QString course = courseDropdown->currentText();
    int row = coursesTable->rowCount();
    coursesTable->insertRow(row);
    coursesTable->setItem(row, 0, new QTableWidgetItem(course));
    coursesTable->setItem(row, 1, new QTableWidgetItem("Enrolled"));

    // Append enrollment info to a CSV file for persistence.
    QFile file("course_enrollment.csv");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << course << ",Enrolled\n";
        file.close();
    }

    QMessageBox::information(this, "Enrollment", "Successfully enrolled in " + course);
}
