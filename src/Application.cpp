#include "Application.h"

Application::Application(UserRepository& uRepo, TransactionRepository& tRepo)
    : menuManager(uRepo, tRepo),  // menuManager أولاً
      userRepo(uRepo),
      transactionRepo(tRepo)      // transactionRepo بعده
{
}

void Application::run() {
   menuManager.showMainMenu();
}
