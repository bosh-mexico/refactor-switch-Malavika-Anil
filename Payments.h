#ifndef PAYMENTS_H
#define PAYMENTS_H

#include "PaymentProcessor.h"
#include <iostream>

class PayPalPayment : public PaymentProcessor {
public:
    void process(double amount) const override;
};

class GooglePayPayment : public PaymentProcessor {
public:
    void process(double amount) const override;
};

class CreditCardPayment : public PaymentProcessor {
public:
    void process(double amount) const override;
};

#endif
