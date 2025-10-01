#ifndef MENUMANAGER_H
#define MENUMANAGER_H
#pragma once
#include "UserRepository.h"
#include "TransactionRepository.h"
#include "Menus.h"

class MenuManager {
private:
    UserRepository& userRepo;
    TransactionRepository& transactionRepo;
    WelcomeMenu* welcomeMenu;
    UserMenu* userMenu;
    TransactionMenu* transactionMenu;

public:
    MenuManager(UserRepository& uRepo, TransactionRepository& tRepo);
    ~MenuManager();

    // getters
    UserRepository& getUserRepo() { return userRepo; }
    TransactionRepository& getTransactionRepo() { return transactionRepo; }

    void showMainMenu();
    void showUserMenu();
    void showTransactionMenu();
};

#endif
