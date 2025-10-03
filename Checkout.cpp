#include "Checkout.h"

void Checkout::processPayment(const PaymentProcessor& processor, double amount) {
    processor.process(amount);
}
