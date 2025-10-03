#ifndef PAYMENTS_H
#define PAYMENTS_H

#include "PaymentProcessor.h"
#include <iostream>

// PayPal
class PayPalPayment : public PaymentProcessor {
public:
    void process(double amount) const override;
};

// GooglePay
class GooglePayPayment : public PaymentProcessor {
public:
    void process(double amount) const override;
};

// CreditCard
class CreditCardPayment : public PaymentProcessor {
public:
    void process(double amount) const override;
};

#endif
