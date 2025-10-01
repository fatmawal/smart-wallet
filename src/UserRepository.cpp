#include "UserRepository.h"
#include <fstream>
#include <sstream>
#include <iostream>

UserRepository::UserRepository(const std::string& file) : filename(file) {
    load(); // أول ما نعمل object هيقرأ من الملف
}

void UserRepository::load() {
    users.clear();
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open file: " << filename << "\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        std::string username, password, balanceStr;

        std::getline(ss, username, ',');
        std::getline(ss, password, ',');
        std::getline(ss, balanceStr, ',');

        double balance = 0.0;
        try { balance = std::stod(balanceStr); } catch (...) {}

        users.emplace_back(username, password, balance);
    }

    file.close();
}

void UserRepository::save() {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open file for writing: " << filename << "\n";
        return;
    }

    for (const auto& u : users) {
        file << u.getUsername() << ","
             << u.getPassword() << ","
             << u.getBalance() << "\n";
    }

    file.close();
}

bool UserRepository::loadFromCSV(const std::string& fname) {
    filename = fname;
    load();
    return !users.empty();
}

bool UserRepository::saveToCSV(const std::string& fname) {
    filename = fname;
    save();
    return true;
}

User* UserRepository::findUser(const std::string& username, const std::string& password) {
    for (auto& u : users) {
        if (u.getUsername() == username && u.getPassword() == password) {
            return &u;
        }
    }
    return nullptr;
}

void UserRepository::updateUser(const User& user) {
    for (auto& u : users) {
        if (u.getUsername() == user.getUsername()) {
            u = user; // overwrite
            return;
        }
    }
    users.push_back(user); // لو مش موجود نضيفه
}
void UserRepository::addUser(const User& user) {
    users.push_back(user);
    save(); 


const std::vector<User>& UserRepository::getAllUsers() const {
    return users;
}
