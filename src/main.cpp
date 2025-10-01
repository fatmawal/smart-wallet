#include "Application.h"
#include "UserRepository.h"
#include "TransactionRepository.h"

int main() {
    UserRepository userRepo("data/users.csv");
    TransactionRepository transactionRepo("data/transactions.csv");

    Application app(userRepo, transactionRepo);
    app.run();

    return 0;
}
