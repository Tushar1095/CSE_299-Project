// cgpa_calculator.h
#ifndef CGPA_CALCULATOR_H
#define CGPA_CALCULATOR_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

class CGPACalculator : public QWidget {
    Q_OBJECT

private:
    QLineEdit *gradesInput;
    QPushButton *calculateButton;
    QLabel *resultLabel;

public:
    explicit CGPACalculator(QWidget *parent = nullptr);

private slots:
    void calculateCGPA();
};

#endif
