// payment_parking.h
#ifndef PAYMENT_PARKING_H
#define PAYMENT_PARKING_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

class PaymentParking : public QWidget {
    Q_OBJECT
private:
    QLabel *paymentLabel;
    QPushButton *makePaymentButton;
    QLabel *parkingLabel;
    QPushButton *registerParkingButton;
public:
    explicit PaymentParking(QWidget *parent = nullptr);
private slots:
    void makePayment();
    void registerParking();
};

#endif // PAYMENT_PARKING_H
