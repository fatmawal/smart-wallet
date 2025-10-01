#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "Wallet.h"
#include "Transaction.h"

class User {
private:
    std::string username;
    std::string password;
    Wallet wallet;
    std::vector<Transaction> transactions;

public:
    User(const std::string& u, const std::string& p, double balance = 0.0);
    User(const std::string& u);

    const std::string& getUsername() const;
    const std::string& getPassword() const;

    Wallet& getWallet();
    const Wallet& getWallet() const;

    const std::vector<Transaction>& getTransactions() const;
    void addTransaction(const Transaction& t);

    void setBalance(double b);
    double getBalance() const;
};

#endif
