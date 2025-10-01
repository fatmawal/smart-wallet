#include "Storage.h"
#include <fstream>
#include <sstream>
#include <iostream>

void Storage::save(const User& user) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file for saving!\n";
        return;
    }

    // سطر أول: username,balance
    file << user.getUsername() << "," << user.getWallet().getBalance() << "\n";

    // سطور معاملات: id,username,type,amount,date
    for (const auto& t : user.getTransactions()) {
        file << t.getId() << "," 
             << t.getUsername() << ","
             << t.getType() << ","
             << t.getAmount() << ","
             << t.getDate() << "\n";
    }

    file.close();
}

User Storage::load() {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return User("default");
    }

    std::string line;
    // اقرأ أول سطر: username,balance
    if (!std::getline(file, line)) return User("default");
    std::stringstream ss(line);
    std::string username, balanceStr;
    std::getline(ss, username, ',');
    std::getline(ss, balanceStr, ',');
    double balance = 0.0;
    try { balance = std::stod(balanceStr); } catch(...) { balance = 0.0; }

    User user(username, "", balance);
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        std::stringstream ts(line);
        std::string idStr, u, type, amountStr, date;
        std::getline(ts, idStr, ',');
        std::getline(ts, u, ',');
        std::getline(ts, type, ',');
        std::getline(ts, amountStr, ',');
        std::getline(ts, date, ',');

        int id = 0;
        double amount = 0.0;
        try { id = std::stoi(idStr); } catch(...) { id = 0; }
        try { amount = std::stod(amountStr); } catch(...) { amount = 0.0; }

        Transaction t(id, u, type, amount, date);
        user.addTransaction(t);
    }

    return user;
}
