#ifndef WALLET_H
#define WALLET_H

class Wallet {
private:
    double balance;

public:
    Wallet();
    Wallet(double initialBalance);

    void deposit(double amount);
    bool withdraw(double amount);

    double getBalance() const;
    void setBalance(double b);
};

#endif
