#ifndef TRANSACTIONREPOSITORY_H
#define TRANSACTIONREPOSITORY_H

#include <string>
#include <vector>
#include "Transaction.h"

class TransactionRepository {
private:
    std::string filename;
    std::vector<Transaction> transactions;

public:
    TransactionRepository(const std::string& file);

    bool loadFromCSV(const std::string& filename);
    bool saveToCSV(const std::string& filename);
    void addTransaction(const Transaction& t);
    std::vector<Transaction> getUserTransactions(const std::string& username) const;

    const std::vector<Transaction>& getAllTransactions() const { return transactions; }
};

#endif
