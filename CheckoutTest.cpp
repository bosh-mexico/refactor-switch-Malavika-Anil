#include "Checkout.h"
#include "Payments.h"
#include <gtest/gtest.h>
#include <string>

TEST(CheckoutTest, UsesPolymorphism) {
    Checkout checkout;
    PayPalPayment paypal;

    testing::internal::CaptureStdout();
    checkout.processPayment(paypal, 200.0);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Processing PayPal payment of $200"), std::string::npos);
}
