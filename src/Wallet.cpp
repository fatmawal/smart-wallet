#include "Wallet.h"

Wallet::Wallet() : balance(0.0) {}
Wallet::Wallet(double initialBalance) : balance(initialBalance) {}

void Wallet::deposit(double amount) {
    if (amount > 0) balance += amount;
}

bool Wallet::withdraw(double amount) {
    if (amount > 0 && balance >= amount) {
        balance -= amount;
        return true;
    }
    return false;
}

double Wallet::getBalance() const { return balance; }
void Wallet::setBalance(double b) { balance = b; }
