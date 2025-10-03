#include "Payments.h"

// PayPal
void PayPalPayment::process(double amount) const {
    std::cout << "Processing PayPal payment of $" << amount << std::endl;
    // TODO: Integrate with PayPal API
}

// GooglePay
void GooglePayPayment::process(double amount) const {
    std::cout << "Processing GooglePay payment of $" << amount << std::endl;
    // TODO: Integrate with GooglePay API
}

// CreditCard
void CreditCardPayment::process(double amount) const {
    std::cout << "Processing Credit Card payment of $" << amount << std::endl;
    // TODO: Integrate with Credit Card API
}
