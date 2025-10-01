#include "MenuManager.h"
#include <iostream>

MenuManager::MenuManager(UserRepository& uRepo, TransactionRepository& tRepo)
    : userRepo(uRepo), transactionRepo(tRepo) {
    welcomeMenu = new WelcomeMenu(*this);
    userMenu = new UserMenu(*this);
    transactionMenu = new TransactionMenu(*this);
}

MenuManager::~MenuManager() {
    delete welcomeMenu;
    delete userMenu;
    delete transactionMenu;
}

void MenuManager::showMainMenu() {
   /* int choice;
    std::cout << "1. User Menu\n2. Transaction Menu\n3. Exit\nEnter choice: ";
    std::cin >> choice;

    if (choice == 1) userMenu->run();
    else if (choice == 2) transactionMenu->run();
    else if (choice == 3) std::cout << "Exiting...\n";  */
     welcomeMenu->run();
  
    }

void MenuManager::showUserMenu() { userMenu->run(); }
void MenuManager::showTransactionMenu() { transactionMenu->run(); }
