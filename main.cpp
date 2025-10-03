#include "Checkout.h"
#include "Payments.h"

int main() {
    Checkout checkout;
    double amount = 150.75;

    PayPalPayment paypal;
    GooglePayPayment gpay;
    CreditCardPayment card;

    checkout.processPayment(paypal, amount);
    checkout.processPayment(gpay, amount);
    checkout.processPayment(card, amount);

    return 0;
}
