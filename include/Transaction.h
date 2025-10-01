#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction {
private:
    int id;
    std::string username;
    std::string type;
    double amount;
    std::string date;

public:
    Transaction(int i, const std::string& u, const std::string& t, double a, const std::string& d);

    Transaction(const std::string& t, double a, const std::string& d);

    int getId() const;
    const std::string& getUsername() const;
    const std::string& getType() const;
    double getAmount() const;
    const std::string& getDate() const;

    std::string getInfo() const;
};

#endif
