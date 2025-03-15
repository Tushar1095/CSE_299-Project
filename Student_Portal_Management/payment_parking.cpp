// payment_parking.cpp
#include "payment_parking.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

PaymentParking::PaymentParking(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    paymentLabel = new QLabel("Outstanding Fees: $1000.00", this);
    makePaymentButton = new QPushButton("Make Payment", this);

    parkingLabel = new QLabel("Parking Status: Not Registered", this);
    registerParkingButton = new QPushButton("Register Parking", this);

    layout->addWidget(paymentLabel);
    layout->addWidget(makePaymentButton);
    layout->addWidget(parkingLabel);
    layout->addWidget(registerParkingButton);

    connect(makePaymentButton, &QPushButton::clicked, this, &PaymentParking::makePayment);
    connect(registerParkingButton, &QPushButton::clicked, this, &PaymentParking::registerParking);
}

void PaymentParking::makePayment() {
    QMessageBox::information(this, "Payment", "Payment Successful!");
    paymentLabel->setText("Outstanding Fees: $0.00");
}

void PaymentParking::registerParking() {
    QMessageBox::information(this, "Parking", "Vehicle Registered Successfully!");
    parkingLabel->setText("Parking Status: Registered");
}
