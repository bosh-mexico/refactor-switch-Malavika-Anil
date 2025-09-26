#include <iostream>
#include <string>
#include <memory>
using namespace std;


enum class PaymentMode {
    PayPal,
    GooglePay,
    CreditCard,
    Unknown
};


class IPaymentProcessor {
public:
    virtual void processPayment(double amount) = 0;
    virtual ~IPaymentProcessor() = default;
};


class PayPalPayment : public IPaymentProcessor {
public:
    void processPayment(double amount) override {
        cout << "Processing PayPal payment of $" << amount << endl;
        // Placeholder: integrate PayPal API
    }
};

class GooglePayPayment : public IPaymentProcessor {
public:
    void processPayment(double amount) override {
        cout << "Processing GooglePay payment of $" << amount << endl;
        // Placeholder: integrate GooglePay API
    }
};

class CreditCardPayment : public IPaymentProcessor {
public:
    void processPayment(double amount) override {
        cout << "Processing Credit Card payment of $" << amount << endl;
        // Placeholder: integrate CreditCard API
    }
};

// Factory --SRP
class PaymentProcessorFactory {
public:
    static unique_ptr<IPaymentProcessor> createProcessor(PaymentMode mode) {
        switch (mode) {
            case PaymentMode::PayPal:
                return make_unique<PayPalPayment>();
            case PaymentMode::GooglePay:
                return make_unique<GooglePayPayment>();
            case PaymentMode::CreditCard:
                return make_unique<CreditCardPayment>();
            default:
                return nullptr; // Unsupported mode
        }
    }
};


void checkout(PaymentMode mode, double amount) {
    auto processor = PaymentProcessorFactory::createProcessor(mode);
    if (processor) {
        processor->processPayment(amount);
    } else {
        cout << "Error: Unsupported or invalid payment mode!" << endl;
    }
}


int main() {
    double amount = 150.75;

    checkout(PaymentMode::PayPal, amount);
    checkout(PaymentMode::GooglePay, amount);
    checkout(PaymentMode::CreditCard, amount);
    checkout(PaymentMode::Unknown, amount);

    return 0;
}
