// cgpa_calculator.cpp
#include "cgpa_calculator.h"
#include <QMessageBox>

CGPACalculator::CGPACalculator(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *title = new QLabel("CGPA Calculator", this);
    gradesInput = new QLineEdit(this);
    gradesInput->setPlaceholderText("Enter grades separated by commas");
    calculateButton = new QPushButton("Calculate", this);
    resultLabel = new QLabel("Your CGPA will be shown here", this);

    layout->addWidget(title);
    layout->addWidget(gradesInput);
    layout->addWidget(calculateButton);
    layout->addWidget(resultLabel);

    connect(calculateButton, &QPushButton::clicked, this, &CGPACalculator::calculateCGPA);
}

void CGPACalculator::calculateCGPA() {
    QStringList gradesList = gradesInput->text().split(",");
    double total = 0;
    int count = 0;
    for (const QString &grade : gradesList) {
        bool ok;
        double value = grade.toDouble(&ok);
        if (ok) {
            total += value;
            count++;
        }
    }
    if (count > 0) {
        double cgpa = total / count;
        resultLabel->setText("Your CGPA: " + QString::number(cgpa, 'f', 2));
    } else {
        QMessageBox::warning(this, "Error", "Invalid input. Please enter valid grades.");
    }
}
