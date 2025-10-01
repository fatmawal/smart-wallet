#include "User.h"

User::User(const std::string& u, const std::string& p, double balance)
    : username(u), password(p), wallet(balance) {}

User::User(const std::string& u) : username(u), password(""), wallet(0.0) {}

const std::string& User::getUsername() const { return username; }
const std::string& User::getPassword() const { return password; }

Wallet& User::getWallet() { return wallet; }
const Wallet& User::getWallet() const { return wallet; }

const std::vector<Transaction>& User::getTransactions() const { return transactions; }
void User::addTransaction(const Transaction& t) { transactions.push_back(t); }

void User::setBalance(double b) { wallet.setBalance(b); }
double User::getBalance() const { return wallet.getBalance(); }
