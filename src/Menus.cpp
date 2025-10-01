#include "Menus.h"
#include "MenuManager.h"
#include <iostream>

WelcomeMenu::WelcomeMenu(MenuManager& m) : manager(m) {}
TransactionMenu::TransactionMenu(MenuManager& m) : manager(m) {}
UserMenu::UserMenu(MenuManager& m) : manager(m) {}

void WelcomeMenu::run() {
    int choice;
    do {
        std::cout << "\n--- Welcome Menu ---\n";
        std::cout << "1. User Menu\n";
        std::cout << "2. Transaction Menu\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            manager.showUserMenu();
            break;
        case 2:
            manager.showTransactionMenu();
            break;
        case 3:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice!\n";
        }
    } while (choice != 3);
}

void UserMenu::run() {
    int choice;
    do {
        std::cout << "\n--- User Menu ---\n";
        std::cout << "1. Add User\n";
        std::cout << "2. View Users\n";
        std::cout << "3. Back\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

       if (choice == 1) {
    std::string username, password;
    double balance;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;
    std::cout << "Enter initial balance: ";
    std::cin >> balance;

    User newUser(username, password, balance);
    auto& repo = manager.getUserRepo();
    repo.addUser(newUser);  
    std::cout << "User " << username << " created successfully!\n";

        } else if (choice == 2) {
            auto& repo = manager.getUserRepo();
            const auto& users = repo.getAllUsers();
            std::cout << "--- All Users ---\n";
            for (auto& u : users) {
                std::cout << "User: " << u.getUsername() 
                          << ", Balance: " << u.getBalance() << "\n";
            }
        }

    } while (choice != 3);
}
void TransactionMenu::run() {
    int choice;
    do {
        std::cout << "\n--- Inside Transaction Menu ---\n";
        std::cout << "1. Add Transaction\n";
        std::cout << "2. View Transactions\n";
        std::cout << "3. Back\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;
if (choice == 1) {
    std::string user, desc;
    double amount;
    std::cout << "Enter username: ";
    std::cin >> user;
    std::cout << "Enter amount: ";
    std::cin >> amount;
    std::cout << "Enter description: ";
    std::cin.ignore();
    std::getline(std::cin, desc);

    Transaction t(0, user, desc, amount, "2025-10-01");
    manager.getTransactionRepo().addTransaction(t);
    std::cout << "Transaction added and saved!\n";
}
 else if (choice == 2) {
            std::string user;
            std::cout << "Enter username: ";
            std::cin >> user; 
            auto list = manager.getTransactionRepo().getUserTransactions(user);
            std::cout << "--- Transactions for " << user << " ---\n";
            for (auto& t : list) {
                std::cout << t.getInfo() << "\n";
            }
        }

    } while (choice != 3);
}
