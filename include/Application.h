#pragma once
#include "UserRepository.h"
#include "TransactionRepository.h"
#include "MenuManager.h"

class Application {
    MenuManager menuManager;
    UserRepository& userRepo;
    TransactionRepository& transactionRepo;

public:
    Application(UserRepository& uRepo, TransactionRepository& tRepo);
    void run();
};
