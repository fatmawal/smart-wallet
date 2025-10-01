#include "TransactionRepository.h"
#include <fstream>
#include <sstream>
#include <iostream>

TransactionRepository::TransactionRepository(const std::string& file)
    : filename(file) {
    loadFromCSV(filename);
}

bool TransactionRepository::loadFromCSV(const std::string& filename) {
    transactions.clear();
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open file: " << filename << "\n";
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);

        int id;
        std::string username;
        std::string type;
        double amount;
        std::string date;

        std::string idStr, amountStr;

        std::getline(ss, idStr, ',');
        std::getline(ss, username, ',');
        std::getline(ss, type, ',');
        std::getline(ss, amountStr, ',');
        std::getline(ss, date, ',');

        try {
            id = std::stoi(idStr);
            amount = std::stod(amountStr);
        } catch (...) {
            continue; // لو فيه parsing error
        }

        transactions.emplace_back(id, username, type, amount, date);
    }

    file.close();
    return true;
}

bool TransactionRepository::saveToCSV(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open file for writing: " << filename << "\n";
        return false;
    }

    for (const auto& t : transactions) {
        file << t.getId() << ","
             << t.getUsername() << ","
             << t.getType() << ","
             << t.getAmount() << ","
             << t.getDate() << "\n";
    }

    file.close();
    return true;
}

void TransactionRepository::addTransaction(const Transaction& t) {
    transactions.push_back(t);
    saveToCSV(filename); // نخزن بعد الإضافة
}

std::vector<Transaction> TransactionRepository::getUserTransactions(const std::string& username) const {
    std::vector<Transaction> result;
    for (const auto& t : transactions) {
        if (t.getUsername() == username) {
            result.push_back(t);
        }
    }
    return result;
}
