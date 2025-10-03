#include "Payments.h"
#include <gtest/gtest.h>
#include <string>

TEST(PaymentsTest, PayPalProcessesCorrectly) {
    PayPalPayment paypal;

    testing::internal::CaptureStdout();
    paypal.process(50.0);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Processing PayPal payment of $50"), std::string::npos);
}

TEST(PaymentsTest, GooglePayProcessesCorrectly) {
    GooglePayPayment gpay;

    testing::internal::CaptureStdout();
    gpay.process(75.0);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Processing GooglePay payment of $75"), std::string::npos);
}

TEST(PaymentsTest, CreditCardProcessesCorrectly) {
    CreditCardPayment card;

    testing::internal::CaptureStdout();
    card.process(120.0);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Processing Credit Card payment of $120"), std::string::npos);
}
