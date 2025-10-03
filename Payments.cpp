#include "Payments.h"

void PayPalPayment::process(double amount) const {
    std::cout << "Processing PayPal payment of $" << amount << std::endl;
}

void GooglePayPayment::process(double amount) const {
    std::cout << "Processing GooglePay payment of $" << amount << std::endl;
}

void CreditCardPayment::process(double amount) const {
    std::cout << "Processing Credit Card payment of $" << amount << std::endl;
}
