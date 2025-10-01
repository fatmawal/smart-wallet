#include "Transaction.h"
#include <string>

Transaction::Transaction(int i, const std::string& u, const std::string& t, double a, const std::string& d)
    : id(i), username(u), type(t), amount(a), date(d) {}

Transaction::Transaction(const std::string& t, double a, const std::string& d)
    : id(0), username(""), type(t), amount(a), date(d) {}

int Transaction::getId() const { return id; }
const std::string& Transaction::getUsername() const { return username; }
const std::string& Transaction::getType() const { return type; }
double Transaction::getAmount() const { return amount; }
const std::string& Transaction::getDate() const { return date; }

std::string Transaction::getInfo() const {
    return std::to_string(id) + "," + username + "," + type + "," + std::to_string(amount) + "," + date;
}
