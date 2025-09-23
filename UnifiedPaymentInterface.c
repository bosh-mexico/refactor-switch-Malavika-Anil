#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;

// ---- Interface (DIP: Depend on abstractions) ----
class IPaymentProcessor {
public:
    virtual void processPayment(double amount) = 0;
    virtual ~IPaymentProcessor() = default;
};

// ---- Concrete Payment Processors (SRP: Each has one responsibility) ----
class PayPalPayment : public IPaymentProcessor {
public:
    void processPayment(double amount) override {
        cout << "Processing PayPal payment of $" << amount << endl;
        // PayPal-specific logic
    }
};

class GooglePayPayment : public IPaymentProcessor {
public:
    void processPayment(double amount) override {
        cout << "Processing GooglePay payment of $" << amount << endl;
        // GooglePay-specific logic
    }
};

class CreditCardPayment : public IPaymentProcessor {
public:
    void processPayment(double amount) override {
        cout << "Processing Credit Card payment of $" << amount << endl;
        // Credit Card-specific logic
    }
};

// ---- Checkout class (OCP: Open for extension, closed for modification) ----
class Checkout {
public:
    void makePayment(unique_ptr<IPaymentProcessor> processor, double amount) {
        processor->processPayment(amount);
    }
};

// ---- Example usage ----
int main() {
    double amount = 150.75;
    Checkout checkout;

    checkout.makePayment(make_unique<PayPalPayment>(), amount);
    checkout.makePayment(make_unique<GooglePayPayment>(), amount);
    checkout.makePayment(make_unique<CreditCardPayment>(), amount);

    return 0;
}
