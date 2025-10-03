#ifndef CHECKOUT_H
#define CHECKOUT_H

#include "PaymentProcessor.h"

class Checkout {
public:
    void processPayment(const PaymentProcessor& processor, double amount);
};

#endif
