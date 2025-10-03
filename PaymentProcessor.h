#ifndef PAYMENTPROCESSOR_H
#define PAYMENTPROCESSOR_H

class PaymentProcessor {
public:
    virtual ~PaymentProcessor() = default;
    virtual void process(double amount) const = 0;
};

#endif
