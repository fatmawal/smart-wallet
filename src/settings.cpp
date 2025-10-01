#include "settings.h"
#include <iostream>

Settings::Settings(User* u) : user(u) {}

void Settings::viewProfile() {
    std::cout << "Viewing profile of user " << user->getUsername() << "\n";
}

void Settings::changePIN() {
    std::cout << "Changing PIN...\n";
}

void Settings::changePassword() {
    std::cout << "Changing password...\n";
}

void Settings::updateUserCSV() {
    std::cout << "Updating user CSV...\n";
}
